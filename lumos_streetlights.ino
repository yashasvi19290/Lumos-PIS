int ldr=A0;
int ldr_val=0;

int sensor1=A1;
int sensor2=A4;
int sensor3=A3;

int light1=3;
int light2=5;
int light3=6;
int light4=9;
int light5=10;
int light6=11;

float outputval=0;

void initialise()
{
  analogWrite(light1,0);
  analogWrite(light2,0);
  analogWrite(light3,0);
  analogWrite(light4,0);
  analogWrite(light5,0);
  analogWrite(light6,0);    
}

void setup() {
  Serial.begin(9600);
  
  pinMode(ldr,INPUT);
  
  pinMode(sensor1,INPUT);
  pinMode(sensor2,INPUT);
  pinMode(sensor3,INPUT);
  
  pinMode(light1,OUTPUT);
  pinMode(light2,OUTPUT);
  pinMode(light3,OUTPUT);
  pinMode(light4,OUTPUT);
  pinMode(light5,OUTPUT);
  pinMode(light6,OUTPUT);
  
  initialise();
}

void loop() {

  ldr_val=analogRead(ldr);
  outputval=(1023-ldr_val)*0.249;
  
  if(digitalRead(sensor1)==1 || digitalRead(sensor2)==1)  //IR Sensor-1 or 2 detects motion
  {
    analogWrite(light1,255);
    analogWrite(light2,255);
    Serial.println("Motion Detected");
  }
  else  //Light intensity controlled by LDR
  {
    analogWrite(light1,outputval);
    analogWrite(light2,outputval);
    Serial.println("LDR Mode");    
  }

  if(digitalRead(sensor2)==1 || digitalRead(sensor3)==1)  //IR Sensor-2 or 3 detects motion
  {
    analogWrite(light3,255);
    analogWrite(light4,255);
    Serial.println("Motion Detected");
  }
  else  //Light intensity controlled by LDR
  {
    analogWrite(light3,outputval);
    analogWrite(light4,outputval);
    Serial.println("LDR Mode");    
  }

  if(digitalRead(sensor3)==1)  //IR Sensor-3 detects motion
  {
    analogWrite(light5,255);
    analogWrite(light6,255);
    Serial.println("Motion Detected");
  }
  else  //Light intensity controlled by LDR
  {
    analogWrite(light5,outputval);
    analogWrite(light6,outputval);
    Serial.println("LDR Mode");    
  }

  delay(1000);
}
