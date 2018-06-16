clc;
close all;
clear all;
%%Circular Convoltuion with zero padding
xn=input('Enter the input sequece xn:');
hn=input('Enter the input sequece hn:');
L=length(xn);
M=length(hn);
yn1=conv(xn,hn)
N1=max(L,M);
yn2=cconv(xn,hn,N1)
N2=L+M-1;
yn3=cconv(xn,hn,N2)
n=0:1:N1-1;
subplot(5,1,1);
stem(n,xn);
xlabel('n');
ylabel('xn');
title('fig.1.Given Sequence xn');
subplot(5,1,2);
stem(n,hn);
xlabel('n');
ylabel('hn');
title('fig.2.Impulse Sequence hn');
n=0:1:L+M-2;
subplot(5,1,3);
stem(n,yn1);
xlabel('n');
ylabel('yn1');
title('fig.3.Linear Convolution');
n=0:1:N1-1;
subplot(5,1,4);
stem(n,yn2);
xlabel('n');
ylabel('yn2');
title('fig.4:Circular Convolution');
n=0:1:N2-1;
subplot(5,1,5);
stem(n,yn3);
xlabel('n');
ylabel('yn');
title('fig 5.Circular Convolution using zero padding');
