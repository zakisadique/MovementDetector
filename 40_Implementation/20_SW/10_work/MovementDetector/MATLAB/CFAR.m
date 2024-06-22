% Parameters
N = 100;              % Number of range cells
cutIndex = 50;        % Cell Under Test index
guardCells = 2;       % Number of guard cells
referenceCells = 10;  % Number of reference cells on each side

priorPorts=instrfind;
delete(priorPorts);
PSoC=serial('COM9', 'BaudRate', 115200, 'InputBufferSize', 14000);
fopen(PSoC);
fwrite(PSoC,'s','uchar');
if PSoC.BytesAvailable == 2048
    rx_data_adc = fread(PSoC,1024,'uint16');
    fwrite(PSoC,'o','uchar'); 
end
if PSoC.BytesAvailable ~= 2048 
    fprintf("Transfer in progress: %i, Bytes Available: %d\n", count, PSoC.BytesAvailable);

end



% Generate a random signal with noise
signal = abs(randn(1, N));
signal = rx_data_adc;

% Add a target in the CUT
signal(cutIndex) = 5 + max(signal);

% CFAR Implementation
% Define the CUT and reference cells
cut = signal(cutIndex);
referenceWindow = [signal(cutIndex-referenceCells-guardCells:cutIndex-guardCells-1), ...
                   signal(cutIndex+guardCells+1:cutIndex+guardCells+referenceCells)];

% Estimate the noise level
noiseLevel = mean(referenceWindow);

% Set the threshold (using a scaling factor)
scalingFactor = 5; % Example scaling factor
threshold = scalingFactor * noiseLevel;

% Detection
if cut > threshold
    detection = true;
else
    detection = false;
end

% Plotting the results
figure;
plot(signal, 'b-o');
hold on;
plot(cutIndex, cut, 'ro', 'MarkerSize', 10, 'LineWidth', 2);
yline(threshold, 'r--', 'LineWidth', 2);
legend('Signal', 'CUT', 'Threshold');
title('CFAR Detection');
xlabel('Range Cell Index');
ylabel('Amplitude');
grid on;
