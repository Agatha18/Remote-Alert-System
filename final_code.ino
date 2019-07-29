#include <SoftwareSerial.h>

#include <Sim800l.h>
SoftwareSerial mySerial(9,10);
const int Input1=2;
int State1;

void setup(){
  Serial.begin(9600);
  mySerial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(Input1),sendsms,RISING);
  pinMode(Input1, INPUT);
}

void loop()
{
  updateSerial();
}
void updateSerial(){
  delay(500);
  while(mySerial.available()){
    Serial.write(mySerial.read());
  }
  while(Serial.available()){
    mySerial.write(Serial.read());
  }
}
void sendsms()
{
  mySerial.println("AT\r");
  delay(1000);
  Serial.write(mySerial.read());
  mySerial.println("AT+CMGF=1\r");
  delay(1000);
  mySerial.println("AT+CMGS=\"+256785979980\"\r");
  delay(1000);
 
  mySerial.println("EMERGENCY!");
  delay(1000);
 
  mySerial.println((char)26);
  delay(100);
 
}
