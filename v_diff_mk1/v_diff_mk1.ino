byte left_motor = 9;
byte right_motor = 10;

void setup(){
 
 Serial.begin(9600); 
}

void loop() {
 unsigned long steer = analogRead(A0);
 //Serial.println(steer);
 if (steer > 511) {
   unsigned long right_motor_speed = -0.498047*steer+509.502; 
   analogWrite(left_motor,255);
   analogWrite(right_motor,right_motor_speed);
   Serial.print("Left: 255  Right: ");
   Serial.println(right_motor_speed);
 } else {
   unsigned long left_motor_speed = 255*steer/512; 
   analogWrite(left_motor, left_motor_speed);
   analogWrite(right_motor,255);
   Serial.print(" Left: ");
   Serial.print(left_motor_speed);
   Serial.println(" Right: 255");
 }
 delay(10);
}
