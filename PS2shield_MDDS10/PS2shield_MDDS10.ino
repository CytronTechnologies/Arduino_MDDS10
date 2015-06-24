/*
PWM input mode with microcontroller (Independent Both), DIP switch 1 0 1 1 0 1 0 0 .
This code is using PS2 shield library and math library.
This code is tested with CT-Uno,Smart Drive Duo 10(MDDS10),PS2 shield and PS2 wireless. 
*/
#include <Shield_PS2.h>
PS2 ps2=PS2();

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
  pinMode(dig1,OUTPUT);      //initialize for all the input and output
  pinMode(dig2,OUTPUT);
  pinMode(an1,INPUT);
  pinMode(an2,INPUT);
  Serial.begin(9600);
  ps2.init(9600, 2, 3);//initialize the main board to use desired (baudrate, rx, tx)
                       //for Arduino Mega use RX:10, TX: 11 for software serial
                       //for Arduino Leonardo use pin 8, 9, 10, 11 as RX and TX for software serial
  analogWrite(an1,0);  //Based on the datasheet, the MDDS10 analog pin should get 0 input upon start 
  analogWrite(an2,0);  //thus we need to send 0 value at the beginning
  delay(1000);                        
  
}

void loop()
{
    //joystick value
    ly=ps2.getval(p_joy_ly);
    lx=ps2.getval(p_joy_lx);
    acc=ps2.getval(p_l2);
   
     
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


