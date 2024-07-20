const int trigPin=13;
const int echoPin=12;
long duration;
int distance;
int buggypin5=5;
int buggypin6=6;
int buggypin7=7;
int buggypin8=8;
int ir1 = A0;
int ir2 = A1;
int pin=4;
int count = 0,l,r;
45
unsigned long value=0
;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
pinMode(ir1, INPUT);
pinMode(ir2, INPUT);
pinMode(pin, INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT);
}
void forward() {
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
delay(10);
}
void left() {
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
//delay(10);
}
void right() {
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH);
delay(10);
}
void stopp() {
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW);
}
long st=millis(),endt;
int flag =0;
void loop() {
if(Serial.read() == 'z' || flag ==
1
)
{
digitalWrite(trigPin,LOW);
delayMicroseconds(2);
46
digitalWrite(trigPin,HIGH);
delayMicroseconds(10);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distance=duration*0.034/2;
if
(distance<=20) {
stopp();
delay(2000);
}
else {
forward();
}
if (digitalRead(pin)
> 0)
{
value=pulseIn(pin,HIGH);
Serial.print("Value =");
Serial.println(value);
if(value >1500 && value <2000)
Serial.println("Gantry 1 Crossed");
stopp();
delay(1000);
if(value >2500 && value <3000)
Serial.println("Gantry 2 Crossed");
stopp();
delay(1000);
if(value >500 && value <1000) {
Serial.println("Gantry 3 Crossed");
stopp();
delay(1000);
}
}
flag
= 1;
l = digitalRead(ir1); r = digitalRead(ir2);
if(l==1 && r ==1)
forward();
if(l==0 && r==1)
47
left();
if(l==1 && r==0)
right();
if(l==0 && r==0) {
// forward();
endt= millis();
if(endt
- st > 500)
{
count++;
Serial.print("Count = ");
Serial.println(count);
// Serial.print("Time
= ");
// Serial.println(endt
- st);
//analogWrite(13, 150);
//delay(10);
//analogWrite(13, 0);
st=millis();
}
if(count == 1)
forward();
Serial.print("forward :");
Serial.println(count);
if(count == 2) {
left();
delay(500);
Serial.print("left :");
Serial.println( count);
}
if(count == 3)
forward();
Serial.print(count);
if(count == 4) {
forward();
Serial.print(count);
Serial.println("forward");
}
if(count == 5) {
48
left();
delay(1000);
Serial.print(count);
Serial.println("left");
}
if(count == 6)
{
forward();
Serial.print(count);
Serial.println("forward");
}
if(count > 6)
{
stopp();
Serial.print("Stop");
flag=0;
}
}
}
}

