% CA CFAR Algorithm
clear all;
close all;
clc;

% CA CFAR Parameters
N  = 1024;   % Sample Size
NG = 2;     % Guard Cells
NR = 10;    % Reference Cells
%PFA = 10^-0.2; % Probability of False Alarm
PFA = 0.0001;
%PFA = 100;

n = 0:(N-1);

priorPorts=instrfind;
delete(priorPorts);
PSoC=serial('COM10', 'BaudRate', 115200, 'InputBufferSize', 14000);
fopen(PSoC);


f1 = figure;
count = 1;

flg_data_avai = 0;
fwrite(PSoC,'s','uchar') % means send, I am ready to receive

while(flg_data_avai == 0)
    fprintf("Bytes Available: %d\n", PSoC.BytesAvailable); % Print BytesAvailable
        if PSoC.BytesAvailable == 8192
          
           %fwrite(PSoC,'o','uchar') % means I received all expected data
           rx_data_fft = fread(PSoC,2048,'int32');
           

            % Spectral computation
            fft_real = rx_data_fft(1:2:end);
            fft_imag = rx_data_fft(2:2:end);
             
            fft_mag = sqrt(fft_real.^2 + fft_imag.^2);
            fft_mag(1) = 0;

            figure(f1)
            subplot(2,1,1)
            plot(n,fft_mag);
            adc_fft_db = ((abs(fft_mag)).^2);
            xlabel 'Frequency Bins'
            ylabel 'Magnitude'
            title('Spectrum of the signal')

           %adc_fft_db = 20*log10((1/N)*abs(adc_fft));
           figure(f1)
           subplot(2,1,2)
           plot(n,adc_fft_db);
           xlabel 'Frequency bins'
           ylabel 'Power'
           title('Spectrum of the signal')
            

           % CFAR
            % Implement CA-CFAR Algorithm
            
            % Initialize arrays for thresholds and detected targets
            thresholds = zeros(N, 1);
            targets = zeros(N, 1);
            
            % Calculate the scaling factor alpha using PFA
            alpha = NR * (PFA^(-1/NR) - 1);

            %alpha = PFA;

            % Calculate the CA-CFAR threshold for each cell under test
            for i = NR + NG + 1 : N - NR - NG %setting the range of i, i=CUT 
                %consider cells for lagging &leading window, [x1,x2,x3,CUT,x5,x6,x7]
            
                % Reference cells: sum of the reference cells surrounding the CUT
                lagging_cells = adc_fft_db(i - NR - NG : i - NG - 1); %cells behind CUT
                leading_cells = adc_fft_db(i + NG + 1 : i + NG + NR); %cells after CUT
                
                % Compute the noise level by avg the reference cells
                noise_level = mean([lagging_cells', leading_cells']'); 
                
                % calculate CFAR threshold by scaling
                threshold = noise_level * alpha;
                %threshold = noise_level * PFA;
                
    
                % Store the threshold
                thresholds(i) = threshold;
                
                % Check if spectra peaks go above the calculated threshold limit
                if adc_fft_db(i) > threshold
                    targets(i) = adc_fft_db(i); % Target detected    
                end
            end
            
            % Plot the resulting threshold and detected targets in the spectra plot
            if (count == 10)
                hold on;
                plot(n, thresholds, 'r', 'LineWidth', 1); 
                legend('Spectrum', 'Threshold')
            end
            
            % Return the number of targets
            num_targets = sum(targets > 0);
            disp(['Number of targets detected: ', num2str(num_targets)]);

             %save(strcat('CW_rx_data_adc_',int2str(count),'.mat'),'rx_data_adc');
            count=count+1;
            if (num_targets > 0)
                fwrite(PSoC,'t','uchar') % means target detected
            end
            if (num_targets == 0)
                fwrite(PSoC,'n','uchar') % means target detected
            end
            fwrite(PSoC,'o','uchar') % means I received all expected data
       end

            
            if count == 11
                break;
            end

       fwrite(PSoC,'s','uchar') % means send, I am ready to receive

end



%%%