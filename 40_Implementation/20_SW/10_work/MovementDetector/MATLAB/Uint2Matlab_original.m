%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Uint8 Datatransfer from FreeSoc2 to Matlab
% Version 1.1, Bannwarth, 27.05.2020
%
% Behaviour: 
% 1. sends 's' over the serial Port
% 2. Waits until there are 256 bytes in the buffer
% 3. If there 256 bytes in the buffer, it take them, calculates the fft 
%    out of it and displays the received data and the absolute of the fft.
%
% Using:
% 1. Connect FreeSoc2 to USB (i.e. Power Up)
% 2. Check the correct serial Port Settings
% 3. Run this Script
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

close all;
clear all;
clc;


% Setup and open the serial communication in Matlab
priorPorts=instrfind;
delete(priorPorts);
PSoC=serial('COM8', 'BaudRate', 9600, 'InputBufferSize', 512); % implecit: Parity off / stop bit: 1 
fopen(PSoC);

% flags
flg_data_avai = 0;
rx_meas_num = 0;

%%% 

% Matlab ready to send: Command to PSoc to send data
fwrite(PSoC,'s','uchar'); % means ready to receive, send data

while(flg_data_avai == 0)
   
        if PSoC.BytesAvailable == 0
        
            fprintf(" Waiting \n");
        
        end
        
       if PSoC.BytesAvailable == 512 % When the 256 Bytes are sent, the buffer is read
             rx_data = fread(PSoC,256,'uint8');
             fprintf(" Transfer %i DONE \n",rx_meas_num);
             %fwrite(PSoC,'o','uchar'); % What can you do with this?
             flg_data_avai = 1;
       end
                   
end

fclose(PSoC);

figure
plot([1:256],rx_data);
title('Received Time Domain Data');

figure
plot([1:256],1/length(rx_data)*abs(fft(rx_data)));
title('FFT - from Matlab');

fprintf(" Scipt End \n");