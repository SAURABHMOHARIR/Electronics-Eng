clc;
close all;
clear all;
%%IDFT
N=input('Enter number of samples:');
xn=input('Enter the sequecence:');

L=length(xn);
if(N<L)
    error('N point DFT should be than L');
end;
xn=[xn zeros(1,N-L)];
xk=[];
for k=0:1:N-1;
    [x]=0;
    for n=0:1:N-1;
    x=[x+xn(1,n+1)*exp((-1i*2*pi*k*n)/N)];
        end;
        xn=[xn x]
end;
        k=0:1:N-1;
        subplot(3,1,1);
        stem(k,xk);
        xlabel('x');
        ylabel('xk');
        title('figure 1 DFT Plot');
        subplot(3,1,2);
        n=0:1:N-1;
        stem(n,xn);
        title('fig.2 magnitude plot of IDFT');
         xlabel('n');
        ylabel('|xn|');
        subplot(3,1,3);
        n=0:1:N-1;
        stem(k,angle(xn));
        xlabel('n');
        ylabel('angle xn');
        title('Fig.3 Phase Plot of IDFT');
        
        
    