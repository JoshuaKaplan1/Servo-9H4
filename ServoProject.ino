/*Code written by Josh Kaplan, with help from Ben and Sammy. 
 * All Rights Reserved @ Josh_Kaplan.
 
#include <Servo.h> //includes the servo.h library.

int trigPin = 12; //declares what the trigpin is.
int echoPin = 11; //decleares what the echopin is.
int servo = 9; //declares the pin for the servo.
int but1 = 10; //declares the pin for the on button.
int but2 = 8; //declares the pin for the off button.

int decide = 1; //declares the int decide
int val; //makes an int called val
long duration, inches; //makes 2 longs(64 bit instead of 32, double the decimal count).

Servo myservo; //makes a servo called Myservo

void setup() {
  // put your setup code here, to run once:
   pinMode(trigPin, OUTPUT); //declares this pin an output.
   pinMode(echoPin, INPUT); //declares this pin an input.
   pinMode(but1, INPUT); //declares this pin an input.
   pinMode(but2, INPUT); //declares this pin an input.
  
   pinMode(servo, INPUT); //declares this pin an input. 
   myservo.attach(servo); //attaches the servo on pin 9
   
   Serial.begin(9600); //begins the serial monitor for debugging purposes
}

void loop() {
  // put your main code here, to run repeatedly:

  if (decide == 1) { //if decide is in the on position(Equal to 1), then it runs the function handwave
    hand_wave(); //does the function called hand_wave.
  }
  
  if (digitalRead(but1) == 1 && decide == 0) { //reads button, and ensures that decide never goes above 1.
  decide++; //Adds to decide
  }

  if (digitalRead(but2) == 1 && decide == 1) { //reads button, and ensures that decide never goes under 0.
  decide--; //Subtracts from decides.
  }

  Serial.println(decide); //prints decide for debugging purposes
}

void hand_wave() { //makes a function called handwave

  digitalWrite(trigPin, LOW); //sends nothing to trigpin.
  delayMicroseconds(2); //delay
  digitalWrite(trigPin, HIGH); //sends a signal to the trigpin
  delayMicroseconds(5); //delay 
  digitalWrite(trigPin, LOW); //sends nothing to the trigpin.
  duration = pulseIn(echoPin, HIGH);//checks for values on the echopin
  inches = duration / 74 / 2; //does math to find Inches from Sensor
  
  if (inches < 10) { //If less than 25 inches away.
     for(int i = 0; i < 4; i++) {
      val = random(20, 90); //makes a random int.
      myservo.write(val); //writes that integer to the servo.
      delay(300); //delays for 15 seconds.
      Serial.print("val1 = "); 
      Serial.println(val);//prints out random int for debugging purposes.
      val = random(90, 160); //makes a random int.
      myservo.write(val); //writes that integer to the servo.
      delay(300); //delays for 15 seconds.
      Serial.print("val1 = "); 
      Serial.println(val);//prints out random int for debugging purposes.
      myservo.write(90); //writes that integer to the servo.
     }

  }

  delay(500);
}
