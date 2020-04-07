#define B0 4
#define B1 5
#define B2 6
#define B3 7

void setup() {
  // put your setup code here, to run once:
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(B0,INPUT);
pinMode(B1,INPUT);
pinMode(B2,INPUT);
pinMode(B3,INPUT);

Serial.begin(9600);
}
void moveRobot (String motion){
  if (motion=="Forward"){
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }
  if(motion=="Backward"){
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);
  }
  if(motion=="Left"){
    digitalWrite(10,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,HIGH);  
    }
  if(motion=="Right"){
    digitalWrite(10,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
    
  }
  if(motion=="Stop"){
    digitalWrite(10,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
    digitalWrite(13,LOW);
  }
}
void loop() {
  //int ls=analogRead(A0);
 //int rs=analogRead(A1);
// Serial.println("ls"+String(ls));
// Serial.println("rs"+String(rs));
 int d0=digitalRead(B0);
 int d1=digitalRead(B1);
 int d2=digitalRead(B2);
 int d3=digitalRead(B3);

 if(d0==1 && d1==0 && d2==1 &&d3==0 ){
  moveRobot("Forward");
  }
 if(d0==0 && d1==0 && d2==0 &&d3==0 ){
  moveRobot("Stop");
  }
 if(d0==0 && d1==1 && d2==1 &&d3==0 ){
  moveRobot("Right");
 }
 if(d0==1 && d1==1 && d2==1 &&d3==1 ){
  moveRobot("Left");
  
 
 }
}
