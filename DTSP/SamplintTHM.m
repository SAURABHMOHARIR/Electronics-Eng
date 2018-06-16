clc;
close all;
clear all;
%% Continous signal Generation
t=-10:0.01:10;
T=4;
fm=1/T;
x=cos(2*pi*fm*t);
subplot(3,3,1);
plot(t,x);
grid on;
xlabel('Time in Seconds');
ylabel('Ampltude');
fs1=1.6*fm;
fs2=2*fm;
fs3=8*fm;
fs4=10*fm;
fs5=12*fm;
fs6=16*fm;
%%Samplng Freq not less than 2Fm
n1=-4:1:4;
xn1=cos(2*pi*fm*n1/fs1);
subplot(3,3,2);
stem(n1,xn1);
hold on;
subplot(3,3,2);
plot(n1,xn1);
grid on;
xlabel('n1');
ylabel('Discrete signal for fs<2fm');
title('Discrete signal');
%%Samplng Freq equal to 2fm
n2=-5:1:5;
xn2=cos(2*pi*fm*n2/fs2);
subplot(3,3,3);
stem(n2,xn2);
hold on;
subplot(3,3,3);
plot(n2,xn2);
xlabel('n2');
ylabel('Discrete signal for fs=2fm');
title('Discrete signal');
grid on;
%%Samplng Freq greater than 2fm
n3=-20:1:20;
xn3=cos(2*pi*fm*n3/fs3);
subplot(3,3,4);
stem(n3,xn3);
hold on;
subplot(3,3,4);
plot(n3,xn3);
xlabel('n3');
ylabel('Discrete signal for fs>2fm');
title('Discrete signal');
grid on;
%% SAMPLING FREQUNECY fs=10fm
n4=-40:1:40;
xn4=cos(2*pi*fm*n4/fs4);
subplot(3,3,5);
stem(n4,xn4);
hold on;
subplot(3,3,5);
plot(n4,xn4);
xlabel('n4');
ylabel('Discrete signal for fs>10fm');
title('Discrete signal');
grid on;

%% SAMPLING FREQUNECY fs=12fm
n5=-80:1:80;
xn5=cos(2*pi*fm*n5/fs5);
subplot(3,3,6);
stem(n5,xn5);
hold on;
subplot(3,3,6);
plot(n5,xn5);
xlabel('n5');
ylabel('Discrete signal for fs>12fm');
title('Discrete signal');
grid on;

%% SAMPLING FREQUNECY fs=16fm
n6=-100:1:100;
xn6=cos(2*pi*fm*n6/fs6);
subplot(3,3,7);
stem(n6,xn6);
hold on;
subplot(3,3,7);
plot(n6,xn6);
xlabel('n6');
ylabel('Discrete signal for fs>16fm');
title('Discrete signal');
grid on;