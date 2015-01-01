hold on
innerWheelRadians = (innerWheel) .* (pi/180);
outerWheelRadians = (outerWheel) .* (pi/180);
steeringWheelAngle = rackOffset.*70;
plot(steeringWheelAngle,innerWheelRadians, 'r.')
plot(steeringWheelAngle,outerWheelRadians, 'b.')
xlabel('Steering Angle (degrees)', 'fontsize', 16)
ylabel('Wheel Angle (radians)', 'fontsize', 16)
title('Steering Geometry', 'fontsize', 22)
legend('Inner Wheel', 'Outer Wheel')