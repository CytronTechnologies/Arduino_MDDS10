int pwm_motor_right=6;                //pwm mottor right connect to AN2 at MDS10
int pwm_motor_left=5;                 //pwm mottor left connect to AN1 at MDS10
int dir_motor_right=4;                //direction mottor right connect to DIG2 at MDS10 
int dir_motor_left=7;                 //direction mottor left connect to DIG1 at MDS10


void setup() {
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  delay(1000);      // to make the input data in low.
  // put your setup code here, to run once:

}

void loop() {
  
  analogWrite(pwm_motor_right,255);
  analogWrite(pwm_motor_left,255);
  digitalWrite(dir_motor_right,HIGH);
  digitalWrite(dir_motor_left,HIGH);
  delay(2000);
  
  analogWrite(pwm_motor_right,127);
  analogWrite(pwm_motor_left,127);
  digitalWrite(dir_motor_right,HIGH);
  digitalWrite(dir_motor_left,HIGH);
  delay(2000);
  
  analogWrite(pwm_motor_right,70);
  analogWrite(pwm_motor_left,70);
  digitalWrite(dir_motor_right,HIGH);
  digitalWrite(dir_motor_left,HIGH);
  delay(2000);
  
  analogWrite(pwm_motor_right,70);
  analogWrite(pwm_motor_left,70);
  digitalWrite(dir_motor_right,HIGH);
  digitalWrite(dir_motor_left,HIGH);
  delay(2000);
  
  analogWrite(pwm_motor_right,127);
  analogWrite(pwm_motor_left,127);
  digitalWrite(dir_motor_right,HIGH);
  digitalWrite(dir_motor_left,HIGH);
  delay(2000);
  
  analogWrite(pwm_motor_right,255);
  analogWrite(pwm_motor_left,255);
  digitalWrite(dir_motor_right,HIGH);
  digitalWrite(dir_motor_left,HIGH);
  delay(2000);
  
  
}

