int sensorValue;
int digitalPin = 2;
int analogPin = 0;
int state;
int N = 6;

void setup() {
  pinMode(digitalPin, INPUT_PULLUP);
  pinMode(analogPin, INPUT);
  Serial.begin(9600);
}

void dData() {
  sensorValue = digitalRead(digitalPin);
  if (state != sensorValue){
    state = sensorValue;
    Serial.write(state+253);
  }
    
}

void aData() {
  Serial.write(255);
  for (int i=0; i<N; i++) {
    sensorValue = analogRead(i);
    Serial.write(sensorValue>>3);
    Serial.write(sensorValue&7);
  }
}

void loop() {
 
  dData();
  aData();
  
  delay(5);
}
