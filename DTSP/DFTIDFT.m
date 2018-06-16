clc;
close all;
clear all;
%%DFT by direct method
xn=input('Enter the sequecence:');
N=input('Enter N point DFT:');
L=length(xn);
if(N<L)
    error('N point DFT should be than L');
end;
xn=[xn zeros(1,N-L)];
xk=[];
for k=0:1:N-1;
    [x]=0;
    for n=0:1:N-1;
    x=[x+xn(1,n+1)*exp((-j*2*pi*k*n)/N)];
        end;
        xk=[xk x]
end;
        k=0:1:N-1;
        subplot(3,1,1);
        stem(k,xk);
        xlabel('x');
        ylabel('xk');
        title('figure 1 DFT Plot');
        subplot(3,1,2);
        stem(k,abs(xk));
        xlabel('k');
        ylabel('|xk|');
        title('Fig 2 Magnitude Plot');
        subplot(3,1,3);
        stem(k,angle(xk));
        xlabel('K');
        ylabel('angle');
        title('Fig.3 Phase Plot');
        
        
    