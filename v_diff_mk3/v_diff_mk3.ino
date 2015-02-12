byte left_motor = 9;
byte right_motor = 10;
byte inner_wheel;
byte outer_wheel;
unsigned long steer_angle;
const int w = 48;
const int l = 62;

void setup(){
 Serial.begin(9600); 
}

void loop() {
 unsigned long steer = analogRead(A0);
 unsigned long throttle = analogRead(A1);
 if (steer > 511) {
   inner_wheel = right_motor;
   outer_wheel = left_motor;
   steer_angle = map(steer, 0, 511, 0, 1);
 }
 else {
   inner_wheel = left_motor;
   outer_wheel = right_motor;
   steer_angle = map(steer, 512, 1023, 0, 1);
 }
     
 unsigned long inner_wheel_ratio = (l - w * (0.00445 * steer_angle + 0.003061))/l;  //l / (w * (0.1631 * exp(0.0129 * steer_angle)) + (-.1669 * exp(-.01945) * steer_angle)+ l);    //inner wheel ratio
 unsigned long outer_wheel_ratio = 1;   
 
 //apply throttle
 unsigned long pre_inner_wheel_speed = inner_wheel_ratio * throttle;                                                               
 unsigned long pre_outer_wheel_speed = outer_wheel_ratio * throttle;                                                             
 
 // map throttle value to output to motor  
 unsigned long inner_wheel_speed = map(pre_inner_wheel_speed, 0, 1023, 0, 255);                                                    
 unsigned long outer_wheel_speed = map(pre_outer_wheel_speed, 0, 1023, 0, 255);                                                  

 // write value to motors
 analogWrite(inner_wheel,inner_wheel_speed);
 analogWrite(outer_wheel,outer_wheel_speed);
 Serial.print("Steer: "); 
 Serial.print(steer);
 Serial.print(" Throttle: ");
 Serial.print(throttle);
 Serial.print(" Inner: ");
 Serial.print(inner_wheel_ratio);
 Serial.print(" Outer: ");
 Serial.println(outer_wheel_ratio);
 delay(100);
}
