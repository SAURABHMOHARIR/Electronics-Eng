clc;
close all;
clear all;
%%Interploation and Decimation
%%Two Stage Sampling Rate converter
fm=input('ENter the frequency of DT signal:');
fs=input('Enter the frequency of DT sinusoidal:');
M=input('Down Sampling Factor:');
L=input('Up sampling Faactor:');

t=0:1/fs:0.5;
x=sin(2*pi*fm*t);

figure(1);

subplot(4,1,1);
stem(x);
xlabel('No of samples');
ylabel('Amplitude');
title('Input Discrete sinusoidal sequence');

xd=decimate(x,M);
subplot(4,1,2);
stem(xd);
xlabel('No of samples');
ylabel('Amplitude');
title('Decimated Sinusoidal Sequecne');

xi=interp(x,L);
subplot(4,1,3);
stem(xi);
xlabel('No of samples');
ylabel('Amplitude');
title('Interpolated sinusoidal Sequence');

xi=interp(xd,L);
subplot(4,1,4);
stem(xi);
xlabel('No of samples');
ylabel('AMplitude');
title('Original Signal obtained after interpolating decimated signal');