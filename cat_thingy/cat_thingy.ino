// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin = 2; 
// Create a servo object 
Servo Servo1; 
const int trigPin = 12;
const int echoPin = 13;
long duration;
int distance;
void setup() { 
   // We need to attach the servo to the used pin number 
   Servo1.attach(servoPin); 
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   Serial.begin(9600); //Användes under debugging och används inte längre då 
}
void loop(){ 
   digitalWrite(trigPin, LOW); 
   delayMicroseconds(2); //En kort delay för tillåta signalen som skickats ut att ha tid att komma tillbaka innan man fångar upp den. 
   digitalWrite(trigPin, HIGH);
   
   duration = pulseIn(echoPin, HIGH); //Gör om avståndet som kom tillbaka till variabeln duration för lättare skrivning av koden. 

   distance = duration * 0.034/2; //Hittade en ekvation på internet som gjorde om avståndet till cm för lättare kalibrering i verkligheten

   Serial.println(distance); //Användes under kalibreringen för att hitta ett bra avstånd där bromsträckan var tillräckligt lång men samtidigt inte för lång.

   
   if (distance < 5){
    rotate_servo(); 
   }
   
}

void rotate_servo(){
   Servo1.write(0); 
   delay(1000); 
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(1000); 
   Servo1.write(0);
   delay(5000);
}
