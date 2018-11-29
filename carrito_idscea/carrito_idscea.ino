#include <Servo.h>
Servo servo;
int left1=2; //motor1 ahead
int left2=8; //motor1 back
int right1=4;//motor2 ahead
int right2=7;//motor2 back 
int value; //data sent from Android device 
int enable1=5; //pwm motor1
int enable2=6;//pwm motor2
int Speed=100;//variable which keeps the motor speed 
int led=13;                                          
void setup() {
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  pinMode(left1,OUTPUT);
  pinMode(left2,OUTPUT);
  pinMode(right1,OUTPUT);
  pinMode(right2,OUTPUT);
  pinMode(enable1,OUTPUT);
  pinMode(enable2,OUTPUT);
  Serial.begin(9600); 
  servo.attach(9); //servo starts on pin 9 
}
void loop() { 
  if(Serial.available()>0){ 
  value = Serial.read(); 
  //servo.write(170); //initializing servo on position 3º instead of 0
  switch(value)
  {
    case 'a':  
    digitalWrite(left1,HIGH);
    digitalWrite(right1,HIGH);
    digitalWrite(left2,LOW);
    digitalWrite(right2,LOW); //car moves ahead
    analogWrite(enable1,Speed); 
    analogWrite(enable2,Speed);  
    break;
    case 'b': 
    digitalWrite(left2,HIGH);
    digitalWrite(right2,HIGH);
    digitalWrite(left1,LOW);
    digitalWrite(right1,LOW); //car moves back
    analogWrite(enable1,Speed); 
    analogWrite(enable2,Speed); 
    break;
    case 'l': 
    digitalWrite(right1,HIGH); 
    digitalWrite(left1,LOW); 
    digitalWrite(left2,LOW);
    digitalWrite(right2,LOW);//moves on left
    analogWrite(enable2,Speed);
    break; 
    case 'r': 
    digitalWrite(left1,HIGH); 
    digitalWrite(right1,LOW); 
    digitalWrite(left2,LOW);
    digitalWrite(right2,LOW);//moves on right
    analogWrite(enable1,Speed);
    break; 
    case 'L': 
    digitalWrite(right1,LOW); 
    digitalWrite(left1,LOW); 
    digitalWrite(left2,LOW);//back left
    digitalWrite(right2,HIGH);
    analogWrite(enable2,Speed);
    break; 
    case 'R': 
    digitalWrite(left1,LOW); 
    digitalWrite(right1,LOW); 
    digitalWrite(left2,HIGH);//back right
    digitalWrite(right2,LOW);
    analogWrite(enable1,Speed);
    break; 
    case 's':
    digitalWrite(left1,LOW);
    digitalWrite(right1,LOW);
    digitalWrite(left2,LOW); //stop car
    digitalWrite(right2,LOW); 
    //servo.write(170);
    break; 
    case 'u': 
    servo.write(90); //servo goes up 90º
    break;
    case 'd': 
    servo.write(170); //servo goes down 180º
    break; 
    /*default:
    digitalWrite(left1,LOW);
    digitalWrite(right1,LOW);
    digitalWrite(left2,LOW); //stop car
    digitalWrite(right2,LOW); 
    //servo.write(170);
    break;*/
     }
    }
  }
