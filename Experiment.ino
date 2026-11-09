int led = 9;
int brightness = 0;

unsigned long previousMillis = 0;
const long interval = 1000;   // change to 2000 if your professor wants that
int ledState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(8, OUTPUT);         // needed so pin 8 drives the LED properly
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  //digitalWrite(8, HIGH);
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