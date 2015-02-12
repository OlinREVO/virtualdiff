byte left_motor = 9;
byte right_motor = 10;
const int w = 48;
const int l = 62;

void setup(){
 
 Serial.begin(9600); 
}

void loop() {
 unsigned long steer = analogRead(A0);
 unsigned long  throttle = analogRead(A1); 
 //Serial.println(steer);
 if (steer > 511) {
   
   // map the potentiometer reading to angle for right wheel as inner wheel
   
   unsigned long steer_angle = map(steer, 0, 511, 0, 135);                                                                          
   unsigned long right_motor_ratio = l / (w * (0.1631 * exp(0.0129 * steer_angle)) + (-.1669 * exp(-.01945) * steer_angle)+ l);    //inner wheel ratio
   unsigned long left_motor_ratio = (l - w * (0.00445 * steer_angle + 0.003061))/l;   
   
   //apply throttle
     
   unsigned long pre_left_motor_speed = left_motor_ratio * throttle;                                                               
   unsigned long pre_right_motor_speed = right_motor_ratio * throttle;                                                             
   
   // map throttle value to output to motor 
   
   unsigned long left_motor_speed = map(pre_left_motor_speed, 0, 1023, 0, 255);                                                    
   unsigned long right_motor_speed = map(pre_right_motor_speed, 0, 1023, 0, 255);                                                  
  
  // write value to motors
  
   analogWrite(left_motor,left_motor_speed);
   analogWrite(right_motor,right_motor_speed);
   Serial.print("Right: ");
   Serial.println(right_motor_speed);
   Serial.print("Left: ");
   Serial.println(left_motor_speed);
   
 } else {
   
   // map the potentiometer reading to angle for left wheel as inner wheel
   
   unsigned long steer_angle = map(steer, 512, 1023, 0, 135);
   unsigned long left_motor_ratio = l / (w * (0.1631 * exp(0.0129 * steer_angle)) + (-.1669 * exp(-.01945) * steer_angle)+ l); 
   unsigned long right_motor_ratio = (l - w * (0.00445 * steer_angle + 0.003061))/l;
   
   //apply throttle
   
   unsigned long pre_left_motor_speed = left_motor_ratio * throttle;
   unsigned long pre_right_motor_speed = right_motor_ratio * throttle;
   
   // map throttle value to output to motor 
   
   unsigned long left_motor_speed = map(pre_left_motor_speed, 0, 1023, 0, 255);
   unsigned long right_motor_speed = map(pre_right_motor_speed, 0, 1023, 0, 255);  

   // write value to motors
   
   analogWrite(left_motor, left_motor_speed);
   analogWrite(right_motor, right_motor_speed);
   Serial.print(" Left: ");
   Serial.print(left_motor_speed);
   Serial.println(" Right: ");
     Serial.print(right_motor_speed);
 }
 
 delay(10);
}