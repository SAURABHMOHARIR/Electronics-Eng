clc;
close all;
clear all;
%% Samplinng THeroem
t=-10:0.01:10;
T=4;
fm=1/T;
x=cos(2*pi*fm*t);
subplot(2,2,1);
plot(t,x);
grid on;
xlabel('TIme in seconds');
ylabel('AMplitude');
fs1=1.6*fm;
fs2=2*fm;
fs3=4*fm;
%%sampling Freq values

%%Fs<2fm
n1=-4:1:4;
xn1=cos(2*pi*fm*n1/fs1);
subplot(2,2,2);
stem(n1,xn1);
hold on;
subplot(2,2,2);
plot(n1,xn1);
grid on;
xlabel('n1');
ylabel('Discrete signal for fs<2fm');
title('Discrete signal');

%%Fs=2fm
n2=-5:1:5;
xn2=cos(2*pi*fm*n2/fs2);
subplot(2,2,3);
stem(n2,xn2);
hold on; 
subplot(2,2,3);
plot(n2,xn2);
grid on;
xlabel('TIme in seconds');
ylabel('Discrete signal for fs=2fm');

%%Fs>2fm
n3=-10:1:10;
xn3=cos(2*pi*fm*n3/fs3);
subplot(2,2,4);
stem(n3,xn3);
hold on;
subplot(2,2,4);
plot(n3,xn3);
grid on;
xlabel('Time in seconds');
ylabel('Disccrte signal for fs>2fm');

