#include <RH_ASK.h>
#include <SPI.h> 
#include <SoftwareSerial.h>

#define dataout 12
#define datain 11
RH_ASK rf_driver;
int State1;
      
int buttonPin = 2;
int buzzerPin = 3;
int ledPin = 6;
const int toneFreq = 923;

void setup()
{
    rf_driver.init();
    pinMode(dataout,OUTPUT);
     pinMode(buttonPin, INPUT);
      pinMode(buzzerPin, OUTPUT);
        pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    //delay(2000);
 
}
 
void loop()
{
    int buttonState = digitalRead(buttonPin);
    if (buttonState==HIGH)
    {   
      // digitalWrite(dataout, HIGH);
        const char *msg = "EMERGENCY!";
        rf_driver.send((uint8_t *)msg, strlen(msg));
        rf_driver.waitPacketSent();
        //delay(1000);
        tone(buzzerPin, toneFreq);
        delay(5000); 
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, toneFreq);
        delay(5000);
        
        digitalWrite(ledPin, LOW);
         noTone(buzzerPin);  
    }
     else
        {
        /*  digitalWrite(ledPin, LOW);
         noTone(buzzerPin);  */
        }
}
