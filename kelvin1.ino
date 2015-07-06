// first pin connected to power
// buttons connected to pins 2 - 5 with pull down resistors
const int button1 = 3;
const int button2 = 2;
const int button3 = 5;

// all buttons set to LOW
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;

//fetPin
const int fetPin = 6;

//tempSensor
const int tempPin = 0;
int tempRead;
float desiredTempC;


void setup() {
  // label pins input or output
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(fetPin, OUTPUT);
  // begin serial for readings
  Serial.begin(9600);
}

void loop() {
  //Serial.print("hello World");

  //read state of each button
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);

  //read temp sensor
  tempRead = analogRead(tempPin);

  //convert reading to voltage
  float voltage = tempRead * 5.0;
  voltage /= 1024.0;
  Serial.print(voltage); Serial.print(" volts");

  // convert 10mv/degree with 500mv offset to degress Celsius ((voltage - 500mV) * 100)
  float tempC = (voltage - 0.5) * 100;
  Serial.print(tempC); Serial.println(" degrees C");

  //if button pressed, say which button
  if (buttonState1 == HIGH) {
    Serial.println("pressed 1");
    desiredTempC = 15;
  }
  if (buttonState2 == HIGH) {
    Serial.println("pressed 2");
    desiredTempC = 22.5;
  }
  if (buttonState3 == HIGH) {
    Serial.println("pressed 3");
    desiredTempC = 30;
  }

  // check temp
  if (tempC >= desiredTempC && tempC < desiredTempC + 2) {
    analogWrite(fetPin, 255);
  }
  else {
    //turn pad off
    analogWrite(fetPin, 0);
  }

  delay(500);

}
