/*
PWM input mode with microcontroller (Independent Both), DIP switch 1 0 1 1 0 1 0 0 .
This code is using PS2 shield library and math library.
This code is tested with CT-Uno,Smart Drive Duo 10(MDDS10),PS2 shield and PS2 wireless. 
*/
#include <SoftwareSerial.h>
#include <Cytron_PS2Shield.h> //PS2 shield library
Cytron_PS2Shield ps2(2, 3); // SoftwareSerial: Rx and Tx pin
#include<math.h>

int dig1=7;  //pin signal for motor left
int dig2=4;  //pin signal for motor right
int an1=6;   //pin pwm for motor left
int an2=5;   //pin pwm for motor right 


int ly=0;
int lx=0;
int xaxis=0;
int yaxis=0;
int acc=0;


void setup()
{
  ps2.begin(9600); // This baudrate must same with the jumper setting at PS2 shield
  ps2.reset(1);             //call to reset Shield-PS2
  delay(100);
  ps2.reset(0);
  pinMode(dig1,OUTPUT);      //initialize for all the input and output
  pinMode(dig2,OUTPUT);
  pinMode(an1,INPUT);
  pinMode(an2,INPUT);
  Serial.begin(9600);
  analogWrite(an1,0);  //Based on the datasheet, the MDDS10 analog pin should get 0 input upon start 
  analogWrite(an2,0);  //thus we need to send 0 value at the beginning
  delay(1000);                        
  
}

void loop()
{
    //joystick value
    ly=ps2.readButton(PS2_JOYSTICK_LEFT_Y_AXIS);
    lx=ps2.readButton(PS2_JOYSTICK_LEFT_X_AXIS);
    acc=(ps2.readButton(PS2_LEFT_2) == 0);
   
     
     if(acc==HIGH)
     {
     Normal();}         //function call for normal speed
     else{
     Acceleration();}   //function call for higher speed
     Movement();
   
    
}
//funtion for the movement
void forward(int pwm){
  digitalWrite(dig1,HIGH);      
  digitalWrite(dig2,HIGH);
  analogWrite(an1,pwm);
  analogWrite(an2,pwm);
  Serial.println(pwm);
}
void reverse(int pwm){
  digitalWrite(dig1,LOW);      
  digitalWrite(dig2,LOW);
  analogWrite(an1,pwm);
  analogWrite(an2,pwm);
  Serial.println(pwm);
}
void left(int pwm){
  digitalWrite(dig1,HIGH);      
  digitalWrite(dig2,LOW);
  analogWrite(an1,pwm);
  analogWrite(an2,pwm);
  Serial.println(pwm);
}
void right(int pwm){
  digitalWrite(dig1,LOW);      
  digitalWrite(dig2,HIGH);
  analogWrite(an1,pwm);
  analogWrite(an2,pwm);
  Serial.println(pwm);
}
void Stop(int pwm){
  digitalWrite(dig1,LOW);      
  digitalWrite(dig2,HIGH);
  analogWrite(an1,pwm);
  analogWrite(an2,pwm);
  Serial.println(pwm);
}
void Acceleration(){

  yaxis=map(ly,0,255,250,-250);      //mapping for the value from the joystick to our desired value
  xaxis=map(lx,0,255,-250,250);
}
void Normal(){

  yaxis=map(ly,0,255,180,-180);
  xaxis=map(lx,0,255,-180,180);
}
//Delete the "//" before the Serial.print to see the output from serial monitor
void Movement(){
  
   if( yaxis>0 && yaxis>xaxis){
           forward(yaxis);
           //Serial.print("forward");
     
     }      
   else if( yaxis<0 && yaxis< abs(xaxis)){
           reverse(abs(yaxis));
           //Serial.print("reverse");
     }  
   else if( xaxis>0 && xaxis>yaxis){
           right(xaxis);
           //Serial.print("right");
     }  
   else if( xaxis<0 && xaxis<abs(yaxis)){
           left(abs(xaxis));
           //Serial.print("left");
     }
   else if( yaxis==1 && xaxis==0){
           Stop(0);
           //Serial.print("Stop");
     }   
}


