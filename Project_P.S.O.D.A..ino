// Set the value of the I/O pins to be used in the program
int trigPin = 2;    
int echoPin = 3;
int vibrationMotor = 4;
    
long duration, cm, inches;

// Setup the pins as I/O
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vibrationMotor, OUTPUT);
}

// Main method
void loop(){

  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  // Turns the output of the sensor off, on, and then off
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Checks the input (reciever) of ultrasonic sensor
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // Checks to see distance of input data
  // If greater than 92 cm away, not of any use
  if (cm < 92) 
    digitalWrite(vibrationMotor, HIGH);
    delay(250);
    digitalWrite(vibrationMotor, LOW);
    delay(250);
  
  // Print the data
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  // Add delay to ensure user is not "spammed" by vibrations
  delay(200);
}
