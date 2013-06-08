function [] = circ (p0, r)

  for th = 0 : 0.2 : 2*pi
    q0 = p0 + r * [cos(th), sin(th)];
    q1 = p0 + r * [cos(th+0.2), sin(th+0.2)];
    plot([q0(1);q1(1)], [q0(2);q1(2)] , '-'); hold on;
    axis equal;
end