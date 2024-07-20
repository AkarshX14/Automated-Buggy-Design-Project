void setup() {
pinMode(A0,INPUT);
pinMode(A1,INPUT);
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(7,OUTPUT);
pinMode(8,OUTPUT); }
void forward() {
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH); }
void right() {
digitalWrite(5,LOW);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,HIGH); }
void left() {
digitalWrite(5,HIGH);
digitalWrite(6,LOW);
digitalWrite(7,LOW);
digitalWrite(8,LOW); }
void loop()
{
int l,r;
l=digitalRead(A0);
r=digitalRead(A1);
if(l==1&&r==1)
forward();
28
if(l==0&&r==1)
left();
if(r==0&&l==1)
right();
if(l==0&&r==0)
forward();
}
