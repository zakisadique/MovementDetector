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



count = 1;
totalCount = 6;
f1 = figure;

flg_data_avai = 0;
fwrite(PSoC,'s','uchar') % means send, I am ready to receive

while(flg_data_avai == 0)
    fprintf("Bytes Available: %d\n", PSoC.BytesAvailable); % Print BytesAvailable
    if PSoC.BytesAvailable == 8192 + 2048

        %fwrite(PSoC,'o','uchar') % means I received all expected data

        rx_data_signal = fread(PSoC,1024,'int16');
        figure(1)
        subplot(4,1,1);
        plot(n,rx_data_signal);
        xlabel 'Samples'
        ylabel 'Magnitude'
        title('Sampled Signal')


        rx_data_signal_fft_matlab = 20*log10((1/length(rx_data_signal))*(abs(fft(rx_data_signal))));
        subplot(4,1,2);
        plot(n, rx_data_signal_fft_matlab);

        plot(n,rx_data_signal_fft_matlab);
        xlabel 'freq bins'
        ylabel 'amplitude'
        title('signal fft - matlab')


        rx_data_fft = fread(PSoC,2048,'int32');


        % Spectral computation
        fft_real_psoc = rx_data_fft(1:2:end);
        fft_imag_psoc = rx_data_fft(2:2:end);

        rx_data_signal_fft_psoc = sqrt(fft_real_psoc.^2 + fft_imag_psoc.^2);

        %fft_mag(1) = 0;


        subplot(4,1,3);
        plot([0:1023],20*log10(rx_data_signal_fft_psoc));
        xlabel 'Frequency Bins'
        ylabel 'amplitude'
        title('signal fft - psoc')

        %adc_fft_db = 20*log10((1/N)*abs(adc_fft));
        rx_data_signal_power = ((abs(rx_data_signal_fft_psoc)).^2);
        rx_data_signal_power(1) = 0;

        subplot(4,1,4);
        plot(n,rx_data_signal_power);
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
            lagging_cells = rx_data_signal_power(i - NR - NG : i - NG - 1); %cells behind CUT
            leading_cells = rx_data_signal_power(i + NG + 1 : i + NG + NR); %cells after CUT

            % Compute the noise level by avg the reference cells
            noise_level = mean([lagging_cells', leading_cells']');

            % calculate CFAR threshold by scaling
            threshold = noise_level * alpha;
            %threshold = noise_level * PFA;


            % Store the threshold
            thresholds(i) = threshold;

            % Check if spectra peaks go above the calculated threshold limit
            if rx_data_signal_power(i) > threshold
                targets(i) = rx_data_signal_power(i); % Target detected
            end
        end
        count=count+1;
        % Plot the resulting threshold and detected targets in the spectra plot


        % Return the number of targets
        num_targets = sum(targets > 0);
        disp(['Number of targets detected: ', num2str(num_targets)]);

        if (count == totalCount)
            hold on;
            plot(n, thresholds, 'r', 'LineWidth', 1);
            legend('Spectrum', 'Threshold')
        end



        %save(strcat('CW_rx_data_adc_',int2str(count),'.mat'),'rx_data_adc');

        if (num_targets > 0)
            fwrite(PSoC,'t','uchar') % means target detected
        end
        if (num_targets == 0)
            fwrite(PSoC,'n','uchar') % means target detected
        end
        fwrite(PSoC,'o','uchar') % means I received all expected data
    end


    if count == totalCount
        break;
    end

    fwrite(PSoC,'s','uchar') % means send, I am ready to receive

end