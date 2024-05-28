close all;
clear all;
clc;


% Setup and open the serial communication in Matlab
priorPorts=instrfind;
delete(priorPorts);
PSoC=serial('COM8', 'BaudRate', 9600, 'InputBufferSize', 2048); % implecit: Parity off / stop bit: 1 
fopen(PSoC);

i = 0;
tr_done = 0;
while (tr_done == 0)
    if PSoC.BytesAvailable >= 2048
        rx_data = fread(PSoC,1024,'uint16');
        fprintf("Transfer DONE\n");
        tr_done = 1;
    end
    fprintf("Bytes Available: %d\n", PSoC.BytesAvailable); % Print BytesAvailable

end

figure
plot([1:1024],rx_data);
title('Received Time Domain Data');

figure
plot([1:1024],1/length(rx_data)*abs(fft(rx_data)));
title('FFT - from Matlab');

fprintf(" Scipt End \n");
