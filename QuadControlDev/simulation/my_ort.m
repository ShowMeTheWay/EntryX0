
function Rt_ort = my_ort(Rt)

    X_ = Rt(:,1); 
    Y_ = Rt(:,2); 
    Z_ = Rt(:,3);
    C_ = (X_/norm(X_)+Y_/norm(Y_)+Z_/(norm(Z_)))/3;

    % alg start
    r = sqrt(2/3);
    C = C_/norm(C_)/sqrt(3);
    k = norm(C_)/sqrt(3);

    Xp = X_*k/(C_'*X_);
    Yp = Y_*k/(C_'*Y_);
    Zp = Z_*k/(C_'*Z_);

    th_xy_p = acos((C-Xp)'*(C-Yp)/(norm(C-Xp)*norm(C-Yp)));
    th_yz_p = acos((C-Yp)'*(C-Zp)/(norm(C-Yp)*norm(C-Zp)));

    th_x = (th_xy_p + th_xy_p + th_yz_p - 2*pi)/3;

    v3 = C_/norm(C_);
    v1 = (Xp - C)/norm(Xp - C);
    v2 = cross(v3,v1);

    Rt = [v1 v2 v3];

    OX = C + Rt*[cos(th_x); sin(th_x); 0]*r;
    OY = C + Rt*[cos(th_x+2*pi/3); sin(th_x+2*pi/3); 0]*r;
    OZ = C + Rt*[cos(th_x+4*pi/3); sin(th_x+4*pi/3); 0]*r;
    
    Rt_ort = [OX OY OZ];
end