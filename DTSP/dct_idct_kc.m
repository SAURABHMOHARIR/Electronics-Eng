clc;
clear all;
close all;
%%DCT IDCT
fp = fopen('watermark.wav', 'r');
fseek(fp, 44, -1)
a = fread(fp, 1024);
plot(a);
hold on;
title('Plot  of Original speech signal');
xlabel('sample number');
ylabel('Amplitude');

figure;
c = dct(a);
plot(c);
hold on
title('Plot  of frequency contents of speech signal in DCT domain');
xlabel('DCT Coefficient number');
ylabel('Amplitude');


for i = 1:104
    d1(i)= c(i);
end

for i = 105:1023
    d1(i)= 0;
end
figure;
plot(d1);
title('Plot  of frequency contents of speech signal after LPF WINDOW TO PASS 1 TO 104 dct samples');
xlabel('DCT Coefficient number');
ylabel('Amplitude');

d2 = idct(d1);
figure;
plot(d2);
title('Plot  of LPF (DCT domain) speech signal');
xlabel('Sample number');
ylabel('Amplitude');