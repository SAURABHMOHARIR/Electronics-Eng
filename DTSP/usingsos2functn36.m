clc;
close all;
clear all;
%%Using SOS2 functn
n=6;
n1=input('Enter the coefficient of n1:');
n2=input('Enter the coefficient of n2:');
n3=input('Enter the coefficient of n3:');

d1=input('Enter the coefficent of d1:');
d2=input('Enter the coefficent of d2:');
d3=input('Enter the coefficent of d3:');

B=[n1;n2;n3]
A=[d1;d2;d3]
[b a]=sos2tf([B A])
b=[b zeros(1,n-1)]
[x r]=deconv(b,a)
[r p k]=residuez(b,a)