#include <Servo.h>
const int doorpin = A1;
Servo door;
int echoPin = 12;
int trigPin = 11;
long duration = 0; 
int distance;
int soilPin = A0;
int pumpPin = 10;
int photoPin = A2;
int tempPin = A5;
int bulb = 13;
int heater = 9;
const int wifi = 8;
int valPin = 7;
double ang;


void setup()
{
  pinMode(bulb, OUTPUT);
  door.attach(doorpin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(heater, OUTPUT);
  pinMode(wifi, OUTPUT);
  Serial.begin(9600);
}



void loop()
{
  int soil = analogRead(soilPin);
  int photo = analogRead(photoPin);
  int temp = analogRead(tempPin);
  if(photo<300){
    digitalWrite(bulb, HIGH);
  }else{
    digitalWrite(bulb, LOW);
  }
  
  if(temp<160){
    digitalWrite(heater, HIGH);
  }else{
    digitalWrite(heater, LOW);
  }
  
  if(soil<450){
    digitalWrite(pumpPin, HIGH);
  }else{
    digitalWrite(pumpPin, LOW);
  }
  
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration*0.034/2;
  if(distance>320){
    digitalWrite(wifi, HIGH);
  }else{
    digitalWrite(wifi, LOW);
  }
  
  int value = digitalRead(valPin);
  if (value==HIGH) {
      ang = 90;
  }else{
      ang = 0;
  }
  Serial.println(value );
  door.write(ang);
  delay(100);
}
