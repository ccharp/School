clear all;

N = 10;   %create N samples 
n = 10000;   %each sample is an average of n random samples
para = 0.9;  %poisson parameter
m =  'norm'; %'poiss';

x = 1:N;
for i = 1:N
   [y(i),z] = randomSamples(n, para, m);
end

sum(y)/N

vy = (y - para*ones(1, N)) * (y - para*ones(1, N))'/N;

y = sort(y);
figure(1)
subplot(1,2,1);
plot(x,y);
subplot(1,2,2);
histfit(z);
figure(2);
subplot(1,2,1);
qqplot(y);
subplot(1,2,2);
histfit(y);
