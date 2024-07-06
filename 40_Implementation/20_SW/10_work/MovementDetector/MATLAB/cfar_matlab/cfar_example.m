% CA CFAR Algorithm
clear all;
close all;
clc;

% CA CFAR Parameters
N  = 1024;   % Sample Size
NG = 2;     % Guard Cells
NR = 10;    % Reference Cells
PFA = 10^-0.3; % Probability of False Alarm


%%%
% Test Data Generation
%%%

% sine Parameters
A0 = 1;
fs = 256;
ks1 = 20.0;
phase1 = -pi/4;

f1 = fs/N*ks1;

% sampled and "continuous"
n = 0:(N-1);
x = A0*cos(2*pi*f1/fs*n + phase1); %- 0.5*sin(2*pi*f2/fs*n + phase2);

% noise
A0eff = A0/sqrt(2);
sinePower = A0eff^2;
noise = A0eff*randn(N,1);

% signal and noise
%xnoise = x+noise';
xnoise = x;
% Plot sine with noise
figure(1)
plot(n,xnoise,'b');
hold on
plot(n,x,'r','LineWidth',1.5);
xlabel 'n'
ylabel 'x_{noise}(n)'
title('sampled sinewave with AWGN');
legend('sine and noise','sine')

% Spectral computation
X = fft(xnoise); % Compute FFT
X_db = 20*log10(abs(X)); % Convert to dB

figure(2) % plot the spectra
plot(n, X_db);
xlabel 'Frequency (Hz)'
ylabel 'Magnitude (dB)'
title('Spectrum of the signal with noise')


%%%
% CFAR
% Implement CA-CFAR Algorithm

% Number of cells under test
CUT = N - 2 * NR - 2 * NG; 

% Initialize arrays for thresholds and detected targets
thresholds = zeros(1, N);
targets = zeros(1, N);

% Calculate the scaling factor alpha using PFA
alpha = NR * (PFA^(-1/NR) - 1);

% Calculate the CA-CFAR threshold for each cell under test
for i = NR + NG + 1 : N - NR - NG %setting the range of i, i=CUT 
    %consider cells for lagging &leading window, [x1,x2,x3,CUT,x5,x6,x7]

    % Reference cells: sum of the reference cells surrounding the CUT
    lagging_cells = X_db(i - NR - NG : i - NG - 1); %cells behind CUT
    leading_cells = X_db(i + NG + 1 : i + NG + NR); %cells after CUT
    
    % Compute the noise level by avg the reference cells
    noise_level = mean([lagging_cells, leading_cells]);
    
    % calculate CFAR threshold by scaling
    threshold = noise_level * alpha;
    


    % Store the threshold
    thresholds(i) = threshold;
    
    % Check if spectra peaks go above the calculated threshold limit
    if X_db(i) > threshold
        targets(i) = X_db(i); % Target detected
        
    end
end

% Plot the resulting threshold and detected targets in the spectra plot
hold on;
plot(n, thresholds, 'r', 'LineWidth', 1); 
legend('Spectrum', 'Threshold')

% Return the number of targets
num_targets = sum(targets > 0);
disp(['Number of targets detected: ', num2str(num_targets)]);
