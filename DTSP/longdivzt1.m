clc;
clear all;
close all;
%%Long division method ZT1

n=7;
num=input('Enter the numerator Coeff:');
den=input('Enter the denominator coefficent:');
num=[num zeros(1,n-1)];
[x r]=deconv(num,den)
zplane(num,den);
zk=roots(num)
pk=roots(den)