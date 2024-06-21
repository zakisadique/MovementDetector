% CA CFAR Algorhytmus
close all;
clear all;
clc;
priorPorts=instrfind;
delete(priorPorts);
PSoC=serial('COM9', 'BaudRate', 115200, 'InputBufferSize', 14000);
fopen(PSoC);
f1 = figure;
count = 1;

flg_data_avai = 0;
fwrite(PSoC,'s','uchar') % means send, I am ready to receive
while(flg_data_avai == 0)
    fprintf("Transfer in progress: %i, Bytes Available: %d\n", count, PSoC.BytesAvailable); % Print BytesAvailable
       if PSoC.BytesAvailable == 2048
             fwrite(PSoC,'o','uchar') % means I received all expected data
             rx_data_adc = fread(PSoC,1024,'uint16');
             fprintf(" Transfer %i DONE \n",count);
             
             % Plotting the received data
                
             figure(f1)
             subplot(2,1,1)
             plot([0:(length(rx_data_adc)-1)],rx_data_adc(1:(length(rx_data_adc))));
             title(['Received Time Domain Data No.:',num2str(count)]);
             subplot(2,1,2)
             plot([0:1023],1/length(rx_data_adc)*20*log10(abs(fft(rx_data_adc))));
             title('FFT -  Matlab');

             % Save the received data
             save(strcat('CW_rx_data_adc_',int2str(count),'.mat'),'rx_data_adc');
             count=count+1;
       end

       if count == 11
           break;
       end

       fwrite(PSoC,'s','uchar') % means send, I am ready to receive
end
fclose(PSoC);
fprintf(" Scipt End \n");





% CA CFAR Parameters
N  = 1024;   %Sample Size
NG = 2;     %Guard Cells
NR = 6;    %Reference Cells
PFA = 10^-6; %Probability of False Alarm

% Initialize threshold and detection arrays
threshold = zeros(1, N);
detection = zeros(1, N);
noise = 0;
count = 0;

load('CW_rx_data_adc_10.mat')
%rx_fft_data = zeros(1,N);
rx_fft_data = fft(rx_data_adc);

% Spectral computation
for i = 1:N
    for k = i- NR- NG : i - NG - 1
        if k <= 0
           fprintf(" ");
        else
            count = count + 1;
            sum = 1/N*(abs(rx_fft_data(k))).^2;
            noise = noise + sum; 
        end
    end
    for k = i + NG + 1 : i + NR + NG
        if k > 1024
           fprintf(" ");
        else
            count = count + 1;
            sum = 1/N*(abs(rx_fft_data(k))).^2;
            noise = noise + sum;  
        end
    end
    noise = noise / count;
    thresholdFactor = ((PFA^-(1/count)) - 1)*(count);
    threshold(i) = thresholdFactor * noise;
    if abs(rx_fft_data(i)) > threshold(i)
        detection(i) = 1; 
    end
    count = 0;
end

% Plot the resulting threshold in the spectra plot
figure(1);

plot(0:1023,(1/length(threshold))*10*log10(threshold),'g');
title('CFAR Threshold');
xlabel('Bin');
ylabel('Amplitude(dB)');
legend('Threshold');

hold on;
plot(0:1023,(1/length(rx_fft_data))*20*log10(abs(rx_fft_data)),'b');
legend('threshold', 'spectrum');

% Plot the detection
figure(2);
plot(0:1023,detection(1:length(detection)));
title('CFAR Detection');
xlabel('Sample Index');
ylabel('Detection');

% hold off
% %Count the number of targets
% numTargets = sum(detection);
% fprintf('Number of Targets: %d\n', numTargets);
