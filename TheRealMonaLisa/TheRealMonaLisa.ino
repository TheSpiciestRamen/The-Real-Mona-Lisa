// C++ code
//


#include <Servo.h>
static unsigned int LEDpin2 = 9;
static unsigned int LEDpin1 = 8;
Servo eyeservo1;
static unsigned int eyeservoPin1 = 2;
Servo eyeservo2;
static unsigned int eyeservoPin2 = 3;
Servo bigservo1;
static unsigned int bigservoPin1 = 4;
Servo bigservo2;
static unsigned int bigservoPin2 = 5;

unsigned int LEDstate = LOW;


unsigned long eyemovePreviousMillis1 = 0;
unsigned long eyemovePreviousMillis2 = 0;
unsigned long eyemovePreviousMillis3 = 0;
unsigned long eyemovePreviousMillis4 = 0;
unsigned long eyemovePreviousMillis5 = 0;

unsigned long eyeservoPreviousMillis = 0;
unsigned long bigservoPreviousMillis = 0;


const unsigned long eyemoveInterval1 = 5000;
const unsigned long eyemoveInterval2 = 7000;
const unsigned long eyemoveInterval3 = 10000;
const unsigned long eyemoveInterval4 = 11000;
const unsigned long eyemoveInterval5 = 15000;

const unsigned long LEDinterval = 20000;
const unsigned long bigservointerval = 25000;

void setup()
{
  Serial.begin(9600);
  Serial.print("Debug");
  
  pinMode(LEDpin1, OUTPUT);
  pinMode(LEDpin2, OUTPUT);
  
  //pinMode(eyeservoPin1, OUTPUT);
 // pinMode(eyeservoPin2, OUTPUT);
  
 // pinMode(bigservoPin1, OUTPUT);
 // pinMode(bigservoPin2, OUTPUT);
  
  eyeservo1.attach(eyeservoPin1);
  eyeservo2.attach(eyeservoPin2);
  
  bigservo1.attach(bigservoPin1);
  bigservo2.attach(bigservoPin2);
  
  bigservo1.write(90);
  bigservo2.write(90);
  delay(1000);
  
}

void loop()
{
 
 
  
    
  if (currentMillis - eyemovePreviousMillis1 >= eyemoveInterval1)
  {
    eyeservo1.write(120);
    eyeservo2.write(120);
    eyemovePreviousMillis1 = currentMillis;
  }
  if (currentMillis - eyemovePreviousMillis2 >= eyemoveInterval2)
  {
    eyeservo1.write(100);
    eyeservo2.write(100);
    eyemovePreviousMillis2 = currentMillis;
  }
  if (currentMillis - eyemovePreviousMillis3 >= eyemoveInterval3)
  {
    eyeservo1.write(80);
    eyeservo2.write(80);
    eyemovePreviousMillis3 = currentMillis;
  }
  if (currentMillis - eyemovePreviousMillis4 >= eyemoveInterval4)
  {
    eyeservo1.write(60);
    eyeservo2.write(60);
    eyemovePreviousMillis4 = currentMillis;
  }
  
  
  if (currentMillis - eyeservoPreviousMillis >= LEDinterval)
  {
    LEDstate = !LEDstate;
    digitalWrite(LEDpin1, LEDstate);
    digitalWrite(LEDpin2, LEDstate);
    eyeservoPreviousMillis = currentMillis;
  }
  
  if (currentMillis - bigservoPreviousMillis >= bigservointerval)
  {
    bigservo1.write(0);
    bigservo2.write(180);
    bigservoPreviousMillis = currentMillis;
  }
  
 
  if (LEDstate == LOW)
  {
   bigservo1.write(90);
   bigservo2.write(90);
  }
  
  
  
  
  

}