int trigPin = 2;    
int echoPin = 3;
int vibrationMotor = 4;
    
long duration, cm, inches;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(vibrationMotor, OUTPUT);
}
 
void loop(){

  cm = (duration/2) / 29.1;
  inches = (duration/2) / 74; 
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 

  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  if (cm < 92) 
    digitalWrite(vibrationMotor, HIGH);
    delay(250);
    digitalWrite(vibrationMotor, LOW);
    delay(250);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  
  delay(200);
}

