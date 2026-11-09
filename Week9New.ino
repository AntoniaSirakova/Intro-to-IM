int led = 9;
int brightness = 0;

unsigned long previousMillis = 0;
const long interval = 1000;   
int ledState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(8, OUTPUT);         
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  
  int sensorValue = analogRead(A2);

  sensorValue = constrain(sensorValue, 300, 900);
  brightness = map(sensorValue, 300, 900, 0, 255);

  analogWrite(led, brightness);

  Serial.println(sensorValue);
  delay(30);

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = (ledState == LOW) ? HIGH : LOW;
    digitalWrite(8, ledState);
  }
}