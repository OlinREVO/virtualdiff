w = 48;
l = 62;
a = 0.1631;
b = 0.0129;
c = -0.1669;
d = -0.01945;
x = linspace(0, 130, 1000);
sigmaI = a.*exp(b.*x)+c.*exp(d.*x);
sigmaO = 0.00445.*x+0.003061;
rI = l./(w.*(sigmaI)+l);
rO = (l-w*(sigmaO))./l;
rm = (rI + rO)./2;
hold on;
plot(x, rI, 'b', 'linewidth', 1.5);
plot(x,rO, 'r', 'linewidth', 1.5);
plot(x, rm, 'g')
legend('Inner Wheel Calulations', 'Outer Wheel Calculations', 'Average')
xlabel('Steering Angle', 'fontsize', 16)
ylabel('Ratio of Inner to Outer Wheel Velocity', 'fontsize', 16)
title('Wheel Velocity Ratio', 'fontsize', 22)
