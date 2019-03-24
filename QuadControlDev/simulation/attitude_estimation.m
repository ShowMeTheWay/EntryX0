
% estimate position, beni
% rad/sec, m/s^2
clear all
clc
close all
data = load('dataDump.mat');
ts = 0.01;

M = data.M;
M_acc = M(:,2:4);
% M_gyro = M(:,5:7);
t = M(:,1);
m = M_acc(1,:);
% n = M_gyro(1,:);
% un FTJ pe acc pt ceva eliminare de zgomot
for i = 2:length(t)
    m(i,:) = m(i-1,:)*0.9 + 0.1*M_acc(i,:);
    %n(i,:) = n(i-1,:)*0.1 + 0.9*M_gyro(i,:);
end

% plot(M(:,1),m);

M(:,2:4) = m;
% M(:,5:7) = n;

accx = M(:,2);
accy = M(:,3);
accz = M(:,4);
gyrox = M(:,5);
gyroy = M(:,6);
gyroz = M(:,7);



% plot(t,gyroy);
R = eye(3);
k = 2;
R_test = R;
for i = 1:length(t)
%   integration
    wx = gyrox(i);
    wy = gyroy(i);
    wz = gyroz(i);
 
    wb_vp = [0 -wz wy; wz 0 -wx;-wy wx 0];
    R_test = R*(eye(3)+ ts*wb_vp);
%   orthogonalization
    R_test = my_ort(R_test);
%   sensor fusion
    OZ_acc = ([accx(i);accy(i);accz(i)]);
    OZ_acc = OZ_acc/norm(OZ_acc);
    OZ_gyro = R_test*[0;0;1];
    
    wf = -k*cross(OZ_gyro,OZ_acc);
    W = [wx;wy;wz] - wf;
    
    wb_vp = [0 -W(3) W(2); W(3) 0 -W(1);-W(2) W(1) 0];
    R = R*(eye(3)+ ts*wb_vp);
    %   orthogonalization
    R = my_ort(R);
    
    sRo{i} = R;
    R_test = R;
end

figure
q = 0:0.01:1;

for i = 1:50:length(t)
    i
    R = sRo{i};
    
    OX = [zeros(3,1) R(:,1)];
    OY = [zeros(3,1) R(:,2)];
    OZ = [zeros(3,1) R(:,3)];
    view([71,42]);
    hold on
    plot3(OX(1,:), OX(2,:), OX(3,:),'r');
    plot3(OY(1,:), OY(2,:), OY(3,:),'g');
    plot3(OZ(1,:), OZ(2,:), OZ(3,:),'b');
    pause(0.01);
    clf
    
%     for j = 1:length(q)
%         ax_x = q*
%     end
end







