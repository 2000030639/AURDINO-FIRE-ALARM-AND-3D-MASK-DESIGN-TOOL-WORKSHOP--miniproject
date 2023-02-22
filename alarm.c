const int temperaturePin = 0;
int led = 13;
int usa = 12;
void setup()
{
pinMode(led, OUTPUT);
pinMode(usa, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
float voltage, degreesC, degreesF;
voltage = getVoltage(temperaturePin);
 degreesC = (voltage - 0.5) * 100.0;
degreesF = degreesC * (9.0/5.0) + 32.0;
Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
if(degreesC>26)
  {
    digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delay(500);               // wait for a second
  tone(12, 10000, 200);
  }
  
}
float getVoltage(int pin)
{
 return (analogRead(pin) * 0.004882814);
}
