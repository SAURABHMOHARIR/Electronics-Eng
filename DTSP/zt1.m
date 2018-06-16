clc;
close all;
clear all;
%%ZT 36
syms n a w;
xn=input('Enter sequence:');
y=ztrans(xn)
num=input('ENter num coeff:');
den=input('Enter the den coeff:');
figure;
zplane(num,den);
figure;
freqz(num,den);
subplot(2,1,1);
stem(k,abs(y));
subplot(2,1,2);
stem(k,angle(xk));
