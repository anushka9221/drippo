/* 
Flower Pot Soil Mosture Sensor
A0 - Soil Mosture Sensor
Connect the Soil Mosture Sensor to anolog input pin 0, 
*/

int mostureSensor = 0;

void setup() {
  // Serial Begin so we can see the data from the mosture sensor in our serial input window. 
  Serial.begin(9600);
 
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(mostureSensor);
  // print out the value you read:

  Serial.println(sensorValue);
       // delay 1 second between reads
}
