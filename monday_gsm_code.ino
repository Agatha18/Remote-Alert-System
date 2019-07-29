#include <RH_ASK.h>
#include <SPI.h> 
#include <SoftwareSerial.h>

#include <Sim800l.h>
SoftwareSerial mySerial (9,10);

#define dataout 12
#define datain 11
RH_ASK rf_driver;
int buttonState1 =0;

      
int buttonPin = 2;
int buzzerPin = 3;
int ledPin = 6;
const int toneFreq = 423;

void setup()
{
    rf_driver.init();
    pinMode(dataout,OUTPUT);
     pinMode(buttonPin, INPUT);
      pinMode(buzzerPin, OUTPUT);
        pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    mySerial.begin(9600);
    delay(500);
   
}
 
void loop()
{
    updateSerial();
     
     buttonState1 = digitalRead(buttonPin);
    if (buttonState1==HIGH)
    {   
        sendsms();
        delay(500);
        const char *msg = "EMERGENCY!";
        rf_driver.send((uint8_t *)msg, strlen(msg));
        rf_driver.waitPacketSent();
        //delay(1000);
        tone(buzzerPin, toneFreq);
        delay(500); 
        digitalWrite(ledPin, HIGH);
        tone(buzzerPin, toneFreq);
        delay(500);
               digitalWrite(ledPin, LOW);
               noTone(buzzerPin);  
    }
     else
        {
        /*  digitalWrite(ledPin, LOW);
         noTone(buzzerPin);  */
        }
}
void updateSerial(){
  delay(500);
  while(mySerial.available())
  {
    Serial.write(mySerial.read());
  }
  while(Serial.available())
  {
    mySerial.write(Serial.read());
  }
}

void sendsms()
{
  mySerial.println("AT\r");
  delay(500);
  Serial.write(mySerial.read());
  mySerial.println("AT+CMGF=1\r");
  delay(500);
  mySerial.println("AT+CMGS=\"+256783420711\"\r");
  delay(500);
 
  mySerial.println("EMERGENCY!");
  delay(500);
 
  mySerial.println((char)26);
  delay(100);
 
}
