clc;
close all;
clear all;
%ciruclar convolution
N=input('Enter the no of samples:');
xn=input('Enter the first sequence:');
hn=input('Enter the impulse respnonse:');
l=length(xn);
m=length(hn);
xk=fft(xn,N);
hk=fft(hn,N);
yk=xk.*hk;
yn=ifft(yk,N)
N1=l+m-1;
xk1=fft(xn,N1);
hk1=fft(hn,N1);
yk1=xk1.*hk1;
yn1=ifft(yk1,N1)