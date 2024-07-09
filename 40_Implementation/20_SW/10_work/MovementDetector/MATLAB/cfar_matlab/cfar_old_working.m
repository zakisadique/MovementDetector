close all;
clear all;
clc;

% CA CFAR Parameters
N  = 1024;   % Sample Size
NG = 2;     % Guard Cells
NR = 10;    % Reference Cells

PFA = 0.1; % probablility of false detection


n = 0:(N-1);

ADC_bytes = 1024*2;
FFT_Bytes = 2048*4;

priorPorts=instrfind;
delete(priorPorts);
PSoC=serial('COM10', 'BaudRate', 115200, 'InputBufferSize', 40480);
fopen(PSoC);

f1 = figure;
count = 1;

flg_data_avai = 0;
fwrite(PSoC,'s','uchar') % means send, I am ready to receive
while(flg_data_avai == 0)
    fprintf("Transfer in progress: %i, Bytes Available: %d\n", count, PSoC.BytesAvailable); % Print BytesAvailable
    if PSoC.BytesAvailable >= ADC_bytes + FFT_Bytes

        rx_data_adc = fread(PSoC,1024,'uint16');
        rx_data_fft = fread(PSoC,2048,'int32');
        fprintf(" Transfer %i DONE \n",count);

        rx_data_fft_real = rx_data_fft(1:2:end);
        rx_data_fft_imag = rx_data_fft(2:2:end);
        rx_data_signal_fft_psoc = sqrt(rx_data_fft_real.^2 + rx_data_fft_imag.^2);

        % Plotting the received data

        figure(1)

        subplot(4,1,1)
        plot([0:(length(rx_data_adc)-1)],rx_data_adc(1:(length(rx_data_adc))));
        xlabel 'No. of samples'
        ylabel 'Amplitude'
        title(['Received Time Domain Data No.:',num2str(count)]);

        subplot(4,1,2)
        plot([0:1023], 20*log10((1/length(rx_data_adc))*(abs(fft(rx_data_adc)))));
        xlabel 'Frequency bins'
        ylabel 'Magnitude'
        title('FFT - Array - Matlab');

        %fft_magnitude_psoc = abs(rx_data_fft_combined);
        fft_magnitude_psoc_db = 20 * log10(rx_data_signal_fft_psoc);


        subplot(4,1,3)
        plot([0:1023],fft_magnitude_psoc_db);
        xlabel 'Frequency bins'
        ylabel 'Magnitude'
        title('FFT - Array - PSoC');



        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        rx_data_adc_power = ((abs(rx_data_signal_fft_psoc)).^2);
        rx_data_adc_power(1) = 0;

        subplot(4,1,4);
        plot([0:1023],rx_data_adc_power);
        xlabel 'Frequency bins'
        ylabel 'Power'
        title('Spectrum of the signal')
        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
        % Threshold and target arrays init
        thresholds = zeros(N, 1);
        targets = zeros(N, 1);

        % Alpha calculation
        alpha = NR * (PFA^(-1/NR) - 1);

        % CA-CFAR calculation under each CUT
        for i = NR + NG + 1 : N - NR - NG 

            % Reference cells
            lagging_cells = rx_data_adc_power(i - NR - NG : i - NG - 1); 
            leading_cells = rx_data_adc_power(i + NG + 1 : i + NG + NR);

            % Compute the noise level by averaging the reference cells
            noise_level = mean([lagging_cells', leading_cells']');

            % calculate CFAR threshold 
            threshold = noise_level * alpha;

            thresholds(i) = threshold;

            % Target detection
            if rx_data_adc_power(i) > threshold
                targets(i) = rx_data_adc_power(i); % Target detected
            end
        end

        num_targets = sum(targets > 0);
        disp(['Number of targets detected: ', num2str(num_targets)]);

        hold on;
        plot(n, thresholds, 'r', 'LineWidth', 1);
        legend('Spectrum', 'Threshold')
        hold off;

        %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

        % Save the received data
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
        fwrite(PSoC,'s','uchar') % means send, I am ready to receive
        break;
    end

    fwrite(PSoC,'s','uchar') % means send, I am ready to receive
end
fwrite(PSoC,'o','uchar') % means send, I am ready to receive
fwrite(PSoC,'s','uchar') % means send, I am ready to receive
fclose(PSoC);

fprintf(" Scipt End \n");