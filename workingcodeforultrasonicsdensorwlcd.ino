#include <Wire.h> 
#include <LiquidCrystal_I2C.h>


// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
const int trigPin = 9;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch;
int RED = 6;
int GREEN = 5;
int myNumb;
int buzzPin=4;
int dt=3000;


void setup()
{
  lcd.begin(); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(buzzPin, OUTPUT);

}




void loop()
{
  digitalWrite(trigPin, LOW); //turn of ultrasensor
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(RED, LOW);
  digitalWrite(buzzPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distanceCm = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  if (distanceInch<5){
    digitalWrite(GREEN,HIGH);
    digitalWrite(buzzPin, HIGH);
    delay(dt);
    digitalWrite(buzzPin, LOW);
  }
   else {
    digitalWrite(RED,HIGH);
   }

  lcd.setCursor(0, 0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(distanceCm); // Prints the distance value from the sensor
  lcd.print(" cm");
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distanceInch);
  lcd.print(" inch");
  delay(10);



}
