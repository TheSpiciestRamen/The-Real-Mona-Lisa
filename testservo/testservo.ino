// C++ code
//


#include <Servo.h>

Servo bigservo2;
static unsigned int bigservoPin = 5;


void setup()
{
  Serial.begin(9600);
  Serial.print("Debug");
  
  bigservo.attach(bigservoPin);
  
}

void loop()
{
 
 bigservo.write(0);
 delay(1000);
 bigservo.write(90);
 delay(1000);  
 bigservo.write(180);
 delay(1000);  

}