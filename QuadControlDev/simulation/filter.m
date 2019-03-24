clc; clear all;

data = importdata('filterdata.csv')



% plot(data.data(:,1),[data.data(:,2),data.data(:,3),data.data(:,4),data.data(:,5),data.data(:,6),data.data(:,7)]);
plot(data.data(:,1),[data.data(:,2),data.data(:,3),data.data(:,4)]);
% hold on;

xacc = smooth(data.data(:,2),200);
yacc = smooth(data.data(:,3));
zacc = smooth(data.data(:,4));

figure
plot(data.data(:,1),[data.data(:,2) xacc]);