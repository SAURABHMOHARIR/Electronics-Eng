clc;
clear all;
close all;
%% Butterworth Low pass filter 
fp = input('Enter the pass band frequency:');
fs = input('Enter the stop band frequency:');
rp = input('Enter the pass band ripple:');
rs = input('Enter the stop band ripple:');
f  = input('Enter the sampling frequency:');

wp = 2*fp/f;
ws = 2*fs/f;

[N, wn] = buttord(wp, ws, rp, rs)
[b, a] = butter(N, wn);
Hs = tf(b, a)
[h , ph] = freqz(b,a);
m = 20*(log10 (abs(h)));
y = angle(h);

subplot(2,2,1);
plot(ph/pi, m);
title('Fig. 1 Magnitude Plot of Analog Butterworth Filter IIR LPF');
grid on;
subplot(2,2,2);
plot(ph/pi, y);
title('Fig.2 Phase Plot of Analog Butterworth Filter IIR LPF');
grid on;

[bz, az] = bilinear(b,a,f)
T = 1/f;
Hz = tf(bz, az, T)
[h1, ph1] = freqz(bz, az, 512,f);
m1 = 20*(log10 (abs(h1)));
y1 = angle(h1);
subplot(2,2,3);
plot(ph/pi, m1);
title('Fig. 3 Magnitude Plot of Digital Butterworth Filter IIR LPF');
grid on;

subplot(2,2,4);
plot(ph/pi, y1);
title('Fig. 4 Phase Plot of Digital Butterworth Filter IIR LPF');
grid on;

zplane(bz, az)
