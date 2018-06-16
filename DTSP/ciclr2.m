clc;
close all;
clear all;
%%Circular convolution2:using fft and ifft instructions.
xn=input('Enter the sequence:');
hn=input('Enter the impulse sequence');
l=length(xn);
m=length(hn);
N=max(l,m);
xk=fft(xn,N);
hk=fft(hn,N);
yk=xk.*hk;
yn=ifft(yk,N);
for i=1:N-1
    yk1(i)=xk(i)*hk(i);
end
yn1=ifft(yk1)
N1=l+m-1;
xk1=fft(xn,N1);
hk1=fft(hn,N1);
yk2=xk1.*hk1;
yn2=ifft(yk2,N1)
for i=1:N1;
    yk(i)=xk(i)*hk1(i);
end
yn3=ifft(yk3,N1)