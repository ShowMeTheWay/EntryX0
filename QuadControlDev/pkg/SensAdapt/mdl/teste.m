syms th ch ph

Rkt = [cos(th) -sin(th) 0; sin(th) cos(th) 0; 0 0 1];
Rit = [1 0 0;0 cos(ch) -sin(ch); 0 sin(ch) cos(ch)];
Rjt = [cos(ph) 0 sin(ph); 0 1 0; -sin(ph) 0 cos(ph)];

Rt = Rkt*Rit*Rjt;