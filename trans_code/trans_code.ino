/**
 #include <VirtualWire.h>
const int ledPin = 9;
char *data;
void setup() 
{
  pinMode(ledPin,OUTPUT);
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(12);
  vw_setup(4000);
}

void loop()
{
  data="1";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  digitalWrite(ledPin,HIGH);
  delay(2000);
  data="0";
  vw_send((uint8_t *)data, strlen(data));
  vw_wait_tx();
  digitalWrite(ledPin,LOW);
  delay(2000);
}  **/

#define dataout 12
#define ledPin 7

 void setup()
 {
   pinMode(dataout, OUTPUT);     
   pinMode(ledPin, OUTPUT);    
 }

 void loop()
 {
   
     digitalWrite(dataout, HIGH);
     digitalWrite(ledPin, HIGH);
     delay(5000);
     
     digitalWrite(dataout,LOW);
     digitalWrite(ledPin, LOW);
     delay(5000);
 
}
