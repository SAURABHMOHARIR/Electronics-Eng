clc;
close all;
clear all;
%%long div 2

num=input('Enter the numerator Coeff:');
den=input('Enter the denominator coefficent:');
n=6;
num=[num zeros(1,n-1)];
[x r]=deconv(num,den)
zplane(num,den);
zk=roots(num)
pk=roots(den)