int buzzerPin = 9;
int buttonPin = 7;
int ledPin = 6;
const int toneFreq = 923;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  int buttonState = digitalRead(buttonPin);
  if (buttonState==HIGH)
  {
    digitalWrite(ledPin, HIGH);
    tone(buzzerPin, toneFreq);
    delay(9000); digitalWrite(ledPin, HIGH);
   // tone(buzzerPin, toneFreq);
   // delay(8000);
  } 
  else
  {
    digitalWrite(ledPin, LOW);
    noTone(buzzerPin);
  }
}
