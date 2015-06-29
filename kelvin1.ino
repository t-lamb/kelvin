// first pin connected to power
// buttons connected to pins 2 - 5 with pull down resistors
const int button1 = 3;
const int button2 = 2;
const int button3 = 5;
const int button4 = 4;

//ledPin
const int ledPin = 6;

// all buttons set to LOW
int buttonState1 = 0;
int buttonState2 = 0;
int buttonState3 = 0;
int buttonState4 = 0;

void setup() {
  // label pins input or output
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(ledPin, OUTPUT);
  // begin serial for readings
  Serial.begin(9600);
}

void loop() { 
  //Serial.print("hello World");
  
  //read state of each button
  buttonState1 = digitalRead(button1);
  buttonState2 = digitalRead(button2);
  buttonState3 = digitalRead(button3);
  buttonState4 = digitalRead(button4);
  

  //if button pressed, say which button 
  if (buttonState1 == HIGH) {
    Serial.println("pressed 1");
    analogWrite(ledPin, 0);
  }
  if (buttonState2 == HIGH) {
    Serial.println("pressed 2");
    analogWrite(ledPin, 85);
  }
  if (buttonState3 == HIGH) {
    Serial.println("pressed 3");
    analogWrite(ledPin, 170);
  }
  if (buttonState4 == HIGH) {
    Serial.println("pressed 4");
    analogWrite(ledPin, 255);
  }
  
  delay(50);

}
