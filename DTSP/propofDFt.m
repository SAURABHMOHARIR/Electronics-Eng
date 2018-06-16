clc;
close all;
clear all;
%%DFT Linearty
N=input('Enter the no of samples');
xn1=input('Enter the 1st sequence');
xn2=input('Enter the 2nd sequence');
a1=input('Enter the value of constant a1:');
a2=input('Enter the value of constant a2:');
y=(a1*xn1)+(a2*xn2);
z=fft(y,N)
xk1=fft(xn1,N)
xk2=fft(xn2,N)
z1=a1*xk1+a2*xk2
