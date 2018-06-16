clc;
close all;
clear all;
%%DFT
N=input('Enter the no of samples:');
xn=input('Enter the original sequence:');
xk=fft(xn,N)
k=0:1:N-1;
subplot(2,1,1);
stem(k,abs(xk));
title('Magnitude Plot');
xlabel('k');
ylabel('|xk|');
subplot(2,1,2);
stem(k,angle(xk));
title('Phase Plot');
xlabel('k');
ylabel('Angle|xk|');