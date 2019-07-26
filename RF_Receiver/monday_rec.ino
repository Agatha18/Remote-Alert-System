// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
RH_ASK rf_driver;
#define dataIn 11
#define dataOut 12
 int ledPin = 2;
 int buzzerPin =3;
const int toneFreq =923;
void setup()
{
    // Initialize ASK Object
    rf_driver.init();
    // Setup Serial Monitor
    Serial.begin(9600);
    delay(2000);
    pinMode(dataIn, INPUT);
    pinMode(ledPin,OUTPUT);
    pinMode(buzzerPin,OUTPUT);
    
}
 
void loop()
{
    // Set buffer to size of expected message
    uint8_t buf[11];
    uint8_t buflen = sizeof(buf);
    delay(2000);
    // Check if received packet is correct size
    if (rf_driver.recv(buf, &buflen))
    {          
      Serial.print("Message Received: ");
      Serial.println((char*)buf);  
        digitalWrite(ledPin,HIGH);
        tone(buzzerPin,toneFreq);
          delay(5000);
         tone(buzzerPin,toneFreq);
          delay(5000);
          
          noTone(buzzerPin);
         digitalWrite(ledPin,LOW);
                 
      }
    else{
      /*   noTone(buzzerPin);
         digitalWrite(ledPin,LOW);  */
    }
    
}
