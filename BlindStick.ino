int trigPin=12;
int echoPin=11;
int pingTravelTime;
float distance;
int buzzPin=7;
int dt1=10;
int dt2=10000;
void setup() {
  // put your setup code here, to run once:
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(buzzPin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin,LOW);
delayMicroseconds(dt1);
digitalWrite(trigPin,HIGH);
delayMicroseconds(dt1);
digitalWrite(trigPin,LOW);
pingTravelTime=pulseIn(echoPin,HIGH);
Serial.println(pingTravelTime);
distance=(9./600.)*pingTravelTime+1.5;
Serial.println(distance);

if (distance<30.0){
  digitalWrite(buzzPin,HIGH);
  delayMicroseconds(dt2);
  digitalWrite(buzzPin,LOW);
  delayMicroseconds(dt2);
}
}
