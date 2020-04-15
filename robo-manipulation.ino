#define trigPin 7 
#define echoPin 6         
#define led 13
#include <Servo.h>
 Servo myservo1;                      
 Servo myservo2;
 Servo myservo3;
 Servo myservo4;      
 Servo myservo5;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);               
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  myservo1.attach(3);
  myservo2.attach(5);
  myservo3.attach(9);
  myservo4.attach(10);
  myservo5.attach(11);
 
}

void position1(){                       
    
    digitalWrite(led, HIGH);
    myservo2.writeMicroseconds(1300);
    myservo3.writeMicroseconds(1300);
    myservo4.writeMicroseconds(800);
    myservo5.writeMicroseconds(1000);
    } 
    
void position2(){                            
      
      digitalWrite(led,LOW);
      myservo2.writeMicroseconds(1200);
      myservo3.writeMicroseconds(1300);
      myservo4.writeMicroseconds(1400);
      myservo5.writeMicroseconds(2200);
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance <= 30) {              
  position1();
}
  else {
  position2();                            
} 
  
   if (distance < 10) {
      myservo5.writeMicroseconds(2200);     
} 
  else {
   
     myservo5.writeMicroseconds(1000);       
} 
  
  
  
  
  
  
  
  
  if (distance > 30 || distance <= 0){
    Serial.println("Out of range");         
    
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");                
   
   
  }
  delay(500);                                
}
