function [] = tri (p0, th, l1, l2, phi)
  th = th / 180.0 * pi;
  phi = phi / 180.0 * pi;
  v1 = [cos(th), sin(th)];
  v2 = [cos(th + phi), sin(th + phi)];
  p1 = p0 + v1 * l1;
  p2 = p0 + v2 * l2;
  ps = [p0; p1; p2; p0];
  plot(ps(:,1), ps(:,2),'--'); hold on;
  axis equal;
end