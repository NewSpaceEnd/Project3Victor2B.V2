// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 2; 
// Create a servo object 
Servo Servo1; 
int i = 0; //Används vid rotationen av servon
const int trigPin = 12; //Sätter upp Depth sensorn
const int echoPin = 13;
long duration;
int distance;
void setup() { 
   //Attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   Serial.begin(9600); //Användes under debugging och används inte längre då, men är kvar då man kanske vill kolla värdet 
}
void loop(){ 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); //En kort delay för tillåta signalen som skickats ut att ha tid att komma tillbaka innan man fångar upp den. 
   digitalWrite(trigPin, HIGH);
   
   duration = pulseIn(echoPin, HIGH); //Gör om avståndet som kom tillbaka till variabeln duration för lättare skrivning av koden. 

   distance = duration * 0.034/2; //Hittade en ekvation på internet som gjorde om avståndet till cm för lättare kalibrering i verkligheten

   Serial.println(distance); //Användes under kalibreringen för att hitta ett bra avstånd där bromsträckan var tillräckligt lång men samtidigt inte för lång.

   //När man kommer tillräckligt nära ska servon börja rotera
   if (distance < 5){
    rotate_servo(); 
   }
   
}
/Roterar servon sakta 180 grader för att sedan rotera tillbaka servon 180 grader
void rotate_servo(){
  while (i < 180){
   Servo1.write(i); 
   delay(100); 
   i = i + 3;
   Serial.println(i);
  }
  while (i > 0){
    Servo1.write(i);
    delay(100);
    i = i - 3;
    Serial.println(i);
  }
}
