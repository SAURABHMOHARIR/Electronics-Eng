clc;
close all;
clear all;
%%Windowing methods
rp=input('Enter passband ripples:');
rs=input('Enter stopband ripples:');
fp=input('ENter passband frequency:');
fs=input('ENter stopband frequency:');
f=input('Enter the sampling frequency:');
wp=2*fp/f;
ws=2*fs/f;

num=-20*log10(sqrt(rp*rs))-13
den=14.6*(fs-fp)/f
n=ceil(num/den)
n1=n+1;
if(rem(n,2)~=0)
    n1=n;
    n=n-1;
end;
y=blackman(n1)
subplot(2,1,1);
plot(y);
title('Fig.1 Magnitufde plot of Blackman window');
grid on;
hold on;
b=fir1(n,wp,y);
[h,o]=freqz(b,1,256);
m=20*log10(abs(h));
subplot(2,1,2);
plot(o/pi,m);
grid on;
title('fig.2 Magnitude response of digital FIR filter');
xlabel('Normalized Frequency in db');
ylabel('Normalized gain in db');
