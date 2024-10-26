const int trig = D4; //กำหนดขา trig
const int echo = D5; //กำหนดขา echo
const int led = D2; //กำหนดขา led
long duration, distance; //กำหรดตัวแปรเก็บค่าระยะ

void setup() {
  Serial.begin(9600);
  pinMode(echo, INPUT); //สั่งให้ขา echo ใช้งานเป็น input
  pinMode(trig, OUTPUT); //สั่งให้ขา trig ใช้งานเป็น output
  pinMode(led, OUTPUT);
}
void loop() {
 digitalWrite(trig, LOW); 
 delayMicroseconds(5); 
 digitalWrite(trig, HIGH); 
 delayMicroseconds(5); 
 digitalWrite(trig, LOW); //ใช้งานขา trig
 
 duration = pulseIn(echo, HIGH); //อ่านค่าของ echo
 distance = (duration/2) / 29.1; //คำนวณเป็น centimeters
 Serial.print(distance); 
 Serial.print(" cm\n");
 if(distance <= 5){ //เงื่อนไข ถ้าระยะน้อยกว่า 5cm ให้ led ติด
  digitalWrite(led, HIGH);
 } 
 else{
  digitalWrite(led, LOW);
 }
 delay(300);
}
