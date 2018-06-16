clc;
close all;
clear all;

%%calling function
xn=input('Enter the sequecence:');
N=input('Enter N point DFT:');
xk=DFT(xn,N);
display(xk);
k=0:1:N-1;
subplot(3,1,1);
stme(k,xk);
xlabel('k');
ylabel('xk');
title('dft plot');
subplot(3,1,2);
stem(k,abs(xk));
xlabel('k');
ylabel('|xk|');
title('magnitude plot');
subplot(3,1,3);
stem(k,angle(xk));
xlabel('k');
ylabel('Angle xk');
title('phase resonse');
%% DFT by calling 
L=length(xn)
if(N<L)
    error('N point DFT should be greater than L');
end
xn=[xn zeros(1,N-L)];
xk=[];
for k=0:1:N-1;
    [X]=0;
    for n=0:1:N-1;
        x=[x+xn(1,n+1)*exp((-j*2*pi*k*n)/N)];
    end;
    xk=[xk x]
end