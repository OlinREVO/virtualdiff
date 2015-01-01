hold on
totalRackOffset = vertcat(-rackOffset, rackOffset);
rightWheel = vertcat(-outerWheel,innerWheel);
leftWheel = vertcat(-innerWheel, outerWheel);
plot(totalRackOffset, rightWheel, 'r.')
plot(totalRackOffset, leftWheel, 'b.')