clc;
close all;
clear all;
%%Linear convilution using circular convolution
x=[1 2 2 1];
h=[1 2 1 0];

y_linear=conv(x,h)%Linear convolution
x1=fft(x);
h1=fft(h);
for i=1:4
    z(i)=x1(i)*h1(i);
end
display(z);

w_circular=ifft(z);%Ouput of ciruclar convolution
display(w_circular);

x=[1 2 2 1 0 0 0 0];
h=[1 2 1 0 0 0 0 0];
 y_linear=conv(x,h)%Linear COnvolution
 
 x1=fft(x,8);
 h1=fft(h,8);
 
 for i=1:8
     z(i)=x(i)*h(i);
 end
 display(z);
 w_cirular=ifft(z);%%output of ciruclar convolution
 display(w_circular);