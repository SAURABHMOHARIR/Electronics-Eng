clc;
close all;
clear all;
%Time Reveral
N=input('Enter the no of samples');
xn1=input('Enter the sequence');
xk1=fft(xn1,N);
xn2=[xn1(1)]
for z=0:N-2
    xn2=[xn2 xn1(N-2)];
end
display(xn2);
y=fft(xn2,N)
k=0:1:N-1;
subplot(4,1,1);
stem(k,abs(xk1));
xlabel('K');
ylabel('absolute |xk1|')
title('Fig.1 Magnitude of original Sequence');
subplot(4,1,2);
stem(k,angle(xk1));
xlabel('K');
ylabel('angle |xk|');
title('Fig.2 Phase of original Sequence');
subplot(4,1,3);
stem(k,abs(xk2));
xlabel('K');
ylabel('absolute |xk|');
title('Fig.3 Magnitude of Revered  Sequence');
subplot(4,1,4);
stem(k,angle(xkz));
xlabel('K');
ylabel('absolute |xk2|');
title('Fig.4 Phase of original Sequence');
