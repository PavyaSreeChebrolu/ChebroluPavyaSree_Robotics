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
pinMode(B0,OUTPUT);
pinMode(B1,OUTPUT);
pinMode(B2,OUTPUT);
pinMode(B3,OUTPUT);

pinMode(A0,INPUT);
pinMode(A1,INPUT);

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
  int ls=analogRead(A0);
 int rs=analogRead(A1);
 Serial.println("ls"+String(ls));
 Serial.println("rs"+String(rs));
 if(ls>700&&rs>700){
  moveRobot("Forward");
  digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
 }
 if(ls<700&&rs<700){
  moveRobot("Stop");
  digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
 }
 if(ls>700&&rs<700){
  moveRobot("Right");
  digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
 }
 if(ls<700&&rs>700){
  moveRobot("Left");
  
  digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
 
 }
}
