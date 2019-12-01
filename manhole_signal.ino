const int trigPin = 9;
const int echoPin = 10;

float duration;
float distance;

int light=1;

void setup() {
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT);
pinMode(light,OUTPUT);
Serial.begin(9600); 
}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

Serial.print("Distance: ");
Serial.println(distance);

if(distance>18.0) //Distance depends on the setting where the code is being used
{
  Serial.println("HIGH");
  digitalWrite(light,HIGH);
  
}
else
{
  Serial.println("LOW");
  digitalWrite(light,LOW);
}

delay(1000);
}

//The standard code for obtaining distance from ultrasonic sensor is inspired from https://howtomechatronics.com/tutorials/arduino/ultrasonic-sensor-hc-sr04/
