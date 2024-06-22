%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Testbench Communication from FreeSoc2 to Matlab
% Version 1.0, Bannwarth, 30.05./332020
%
% Behaviour: 
% - Every time Matlab writes ‘s’ on the UART, the PSoC sends new measurement 
%    results and Matlab writes 'o' if this data is received.
% - The Script terminates after 10 data transfers.
%
% Using:
% 1. Connect FreeSoc2 to USB (i.e. Power Up)
% 2. Check the correct serial Port Settings
% 3. Start this Matlab Script
% 4. Run this Script
% 5. Press the external Push Button to start measuring
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
close all;
clear all;
clc;

% Clean up prior serial port objects
priorPorts = instrfind;
delete(priorPorts);

% Initialize serial port object
PSoC = serial('COM9', 'BaudRate', 115200, 'InputBufferSize', 8192 * 4); % int32 * 2048 = 8192 bytes
fopen(PSoC);

f1 = figure;
count = 1;

flg_data_avai = 0;
fwrite(PSoC, 's', 'uchar'); % means send, I am ready to receive

while(flg_data_avai == 0)
    fprintf("Transfer in progress: %i, Bytes Available: %d\n", count, PSoC.BytesAvailable); % Print BytesAvailable
    if PSoC.BytesAvailable == 8192
        fwrite(PSoC, 'o', 'uchar'); % means I received all expected data
        rx_data_fft = fread(PSoC, 2048, 'int32');
        fprintf("Transfer %i DONE\n", count);
        
        % Plotting the received data
        figure(f1);
        subplot(2, 1, 1);
        plot([0:(length(rx_data_fft)-1)], rx_data_fft);
        title(['Received Time Domain Data No.:', num2str(count)]);
        
        subplot(2, 1, 2);
        plot([0:2047], 20*log10(abs(fft(rx_data_fft))));
        title('FFT - Matlab');
        
        % Save the received data
        save(strcat('FFT_rx_data_', int2str(count), '.mat'), 'rx_data_fft');
        count = count + 1;
    end
    
    if count == 11
        break;
    end
    
    fwrite(PSoC, 's', 'uchar'); % means send, I am ready to receive
end

fclose(PSoC);
fprintf("Script End\n");
