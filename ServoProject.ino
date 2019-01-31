//Code written Exclusively by Josh Kaplan, with help from Ben and Sammy. All Rights Reserved @ Josh_Kaplan.

#include <Servo.h> //includes the servo.h Library

int trigPin = 12; //declares what the trigpin is.
int echoPin = 11; //decleares what the echopin is.
int servo = 9; //declares the pin for the servo.
int but1 = 10; //declares the pin for the button.
int but2 = 8; //declares thee pin for the second button.

int but; //declares the int button.
int decide; //declares the int decide
int val; //makes an int called val
long duration, inches; //makes 2 longs(64 bit instead of 32)

Servo myservo; //makes a servo called Myservo

void setup() {
  // put your setup code here, to run once:
   pinMode(trigPin, OUTPUT); //declares this pin an output.
   pinMode(echoPin, INPUT); //declares this pin an input
   pinMode(but1, INPUT); //declares this pin an input
   pinMode(but2, INPUT); //declares this pin an input

   
   myservo.attach(servo); //attaches the servo on pin 9
   Serial.begin(9600); //begins the serial monitor for debugging purposes
   
   randomSeed(analogRead(0)); //for the random generator angle.
}

void loop() {
  // put your main code here, to run repeatedly:

  while (decide == 0) { //sees if the button is equal to 0
    hand_wave(); //does the function entitled hand_wave
  }

  but = digitalRead(but1);
  
  if (but == 1 && decide == 1) {
  decide = decide + 1;
  }

  but = digitalRead(but2);

  if (but == 1 && decide == 0) {
  decide = decide - 1;
  }

}

void hand_wave() { //makes a function called handwave(Hopefully it works, I did something like this during my Attempts with C programming.

  digitalWrite(trigPin, LOW); //sends nothing to trigpin.
  delayMicroseconds(2); //delay
  digitalWrite(trigPin, HIGH); //sends a signal to the trigpin
  delayMicroseconds(5); //delay 
  digitalWrite(trigPin, LOW); //sends nothing to the trigpin.
  duration = pulseIn(echoPin, HIGH);//checks for values on the echopin
  inches = duration / 74 / 2; //does math to find Inches from Sensor
  Serial.println(inches); //prints inches for debugging purposes.

  if (inches < 25) { //If less than 25 inches away.
     val = random(20, 160); //makes a random int between 40 and 120
     myservo.write(val); //writes that integer to the servo.
     delay(15); //delays for 15 seconds.
     Serial.print(val); //prints out random int for debugging purposes/
     myservo.write(90); //puts servo back into 9 degree position
  }

  delay(15);
}
