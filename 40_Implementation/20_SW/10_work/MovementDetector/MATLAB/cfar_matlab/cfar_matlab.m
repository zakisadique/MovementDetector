% CA CFAR Algorithm
clear all;
close all;
clc;

% CA CFAR Parameters
N  = 1024;   % Sample Size
NG = 2;     % Guard Cells
NR = 10;    % Reference Cells
%PFA = 10^-0.2; % Probability of False Alarm
PFA = 10^-9.5;
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
   %fprintf("Bytes Available: %d\n", PSoC.BytesAvailable); % Print BytesAvailable
       if PSoC.BytesAvailable == 2048
          
           %fwrite(PSoC,'o','uchar') % means I received all expected data
           rx_data_adc = fread(PSoC,1024,'uint16');
           figure(f1)
           subplot(2,1,1)
           plot(n,rx_data_adc);
            title(['Received Time Domain Data No.:',num2str(count)]);

           % Spectral computation
           adc_fft = fft(rx_data_adc); % Compute FFT
           %adc_fft_db = 20*log10((1/N)*abs(adc_fft)); % Convert to dB
           %adc_fft_db = ((1/N)*abs(adc_fft)).^2;
           adc_fft(1) = 0;
           adc_fft_db = ((abs(adc_fft)).^2);
           %adc_fft_db = 20*log10((1/N)*abs(adc_fft));
           subplot(2,1,2)
           plot(n,adc_fft_db);
           xlabel 'Frequency (Hz)'
           ylabel 'Magnitude (dB)'
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

             save(strcat('CW_rx_data_adc_',int2str(count),'.mat'),'rx_data_adc');
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


