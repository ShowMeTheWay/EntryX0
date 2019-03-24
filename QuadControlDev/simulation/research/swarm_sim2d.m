
% swarm simulation 
close all
clc
clear all

% get cuboid
L = 5;
l = 2;
h = 1;
V1 = [5;5;5];
V2 = V1 + [L;0;0];
V3 = V1 + [0;l;0];
V4 = V1 + [0;0;h];
V5 = V2 + [0;l;0];
V6 = V2 + [0;0;h];
V7 = V3 + [0;0;h];
V8 = V5 + [0;0;h];

A = [V1 V2 V3 V4 V5 V6 V7 V8];
A = A(1:2,[1,2,3,5]);

C = sum(A,2)/4;
s = 0:0.1:1;
% draw axis
plot(0, 0,'*g');
% draw cuboid
hold on

plot(V1(1), V1(2),'*r');
plot(V2(1), V2(2),'*r');
plot(V3(1), V3(2),'*r');
plot(V5(1), V5(2),'*r');


for i = 1:length(s)
    ax(:,i) = (1 - s(i))*[-2;0;0] + s(i)*[2;0;0];
    ay(:,i) = (1 - s(i))*[0;-2;0] + s(i)*[0;2;0];
end

plot(ax(1,:), ax(2,:),'r');
plot(ay(1,:), ay(2,:),'g');

plot(ax(1,end), ax(2,end),'r+');
text(ax(1,end)+0.2, ax(2,end)-0.2,'x');
plot(ay(1,end), ay(2,end),'g+');
text(ay(1,end)+0.2, ay(2,end)+0.2,'y');

% form forces matrix
N = 25; % number of drones in the swarm
al1 = 2;
al2 = 2;
al3 = 20;

% get random initial postions for drones
X0 = [];
for i = 1:N
    X0 = [X0 [1*C(1:2)+(rand(2,1)-0.5)*10]];
end

% plot the initial positions
for i = 1:N
    plot(X0(1,i), X0(2,i),'om');
    text(X0(1,i)+0.2, X0(2,i)+0.2,['D', num2str(i)]);
end

% begin integration
Ts = 0.005;
nsim = 300;
X = X0;
dX = zeros(2,N);
R = zeros(N);
Xc = [X dX]';
for k = 1:nsim
    
%   get forces
    Nf = [];
    for i = 1:N
        Fi = zeros(2,1);
        f_ = 0;
        F = 0;
        for j = 1:4
            F = al1*norm(X(:,i)-A(:,j))^2 + ...
                al2*(X(:,i)-A(:,j))'*(dX(:,i));
%             F = min([F,10]);
            Fi = Fi + F*A(:,j);
            f_ = f_ + F;
        end
        F_(i) = f_;
        Nf = [Nf Fi];
    end
    
    R = zeros(N);
    for i = 1:N
        R_ = 0;
        for j = i+1:N
            R(i,j) = -al3/norm(X(:,i)-X(:,j))^4;
            R(j,i) = -al3/norm(X(:,i)-X(:,j))^4;
        end
        R(i,i) = 0;
    end

%     R = zeros(N);
    for i = 1:N
        R_ = 0;
        for j = 1:N
            R_ = R_ - R(i,j);
        end
        R(i,i) = -F_(i) + R_;
    end
    
    M = [zeros(N) eye(N); R' zeros(N)];
%     k1 = Ts*(M*Xc + [zeros(N,3); Nf']);
%     k2 = Ts*(M*k1 + [zeros(N,3); Nf']);
%     k3 = Ts*(M*k2 + [zeros(N,3); Nf']);
%     k4 = Ts*(M*k3 + [zeros(N,3); Nf']);
%     Xc = Xc + 1/6*(k1+2*k2+2*k3+k4);
    
    Xc = Xc + Ts*(M*Xc + [zeros(N,2); Nf']);
    X_ = X;
    X = Xc(1:N,:)';
    dX = Xc(N+1:end,:)';
    
    if (k>10) && (norm(X-X_)<1e-2)
        break;
    end
    
    for i = 1:N
        plot(X(1,i), X(2,i),'*g');
    end
    pause(0.01);
end

% plot the initial positions
for i = 1:N
    plot(X0(1,i), X0(2,i),'om');
    text(X0(1,i)+0.2, X0(2,i)+0.2,['D', num2str(i)]);
end

% plot final positions
for i = 1:N
    plot(X(1,i), X(2,i),'*m');
end

% plot the vertexes
plot(V1(1), V1(2),'*r');
text(V1(1)+0.1, V1(2)+0.1,'V1');
plot(V2(1), V2(2),'*r');
text(V2(1)+0.1, V2(2)+0.1,'V2');
plot(V3(1), V3(2),'*r');
text(V3(1)+0.1, V3(2)+0.1,'V3');
plot(V5(1), V5(2),'*r');
text(V5(1)+0.1, V5(2)+0.1,'V4');

% plot the center
plot(C(1),C(2),'vb');

% figure info
xlabel('x [m]');
ylabel('y [m]');
title(['2-d swarming example ' num2str(N) ' drones']);





axis equal
