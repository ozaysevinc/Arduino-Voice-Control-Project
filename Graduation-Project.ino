#include <NewPing.h> 
#include <Servo.h>   
Servo myServo; 
#define echoPin 12
#define trigPin 13
#define Maksimum_uzaklik 500
#define MotorR1 7
#define MotorR2 6
#define MotorRE 9
#define MotorL1 4
#define MotorL2 5
#define MotorLE 3
NewPing sonar(trigPin,echoPin, Maksimum_uzaklik);
String voice;
long sure,uzaklik;
int i=0;
int buzzerPin = 11;
int LED1 = A0;
int LED2 = A1;

void setup()
{
  Serial.begin(9600); 
  Serial.begin(9600);
  myServo.attach(10); 
  myServo.write(90);  
  pinMode(LED1, OUTPUT); 
  pinMode(LED2, OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(trigPin,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(MotorR1,OUTPUT);
  pinMode(MotorR2,OUTPUT);
  pinMode(MotorRE,OUTPUT);
  pinMode(MotorL1,OUTPUT);
  pinMode(MotorL2,OUTPUT);
  pinMode(MotorLE,OUTPUT);
}

void loop() {
  
  while (Serial.available()){ 
     delay(10); 
    char c = Serial.read(); 
    if (c == '#') {break;} 
    voice += c; 
  }
  if (voice.length() > 0){
      if(voice == "*ileri"||voice == "*ileri git") {one_bak(); sensor_olcum_on();  dur();}
      else if(voice == "*geri"||voice == "*geri gel"){one_bak(); geri(); delay(500); dur();}
      else if(voice == "*sağa dön"||voice == "*sağ") {saga_bak(); sensor_olcum_sag(); one_bak(); dur();}
      else if(voice == "*sola dön"||voice == "*sol") {sola_bak(); sensor_olcum_sol(); one_bak(); dur();}
      else if(voice == "*Engele kadar ileri"||voice == "*Tam gaz ileri"){one_bak(); 
      while(i < 20){
        sensor_olcum_on();  dur();
        i++;
      }
      }
      else if(voice == "*kendi etrafında dön") {saga_bak();
        while(i < 20){
         sensor_olcum_sag();  dur();
        i++;
      }
      }
      else if(voice == "*biraz ileri git") {one_bak(); biraz_ileri_on();  dur();}
      else if(voice == "*biraz geri gel") {biraz_geri(); delay(250); dur();}
      else if(voice == "*biraz sola dön") {sola_bak(); biraz_sola_engel();  one_bak(); dur();}
      else if(voice == "*biraz sağa dön") {saga_bak(); biraz_saga_engel();  one_bak(); dur();}
      else if(voice == "*sol ve ileri"){sola_bak(); sensor_olcum_sol(); delay(100); one_bak(); sensor_olcum_on(); delay(500); dur();}
      else if(voice == "*sağ ve ileri"){saga_bak(); sensor_olcum_sag(); delay(100); one_bak(); sensor_olcum_on(); delay(500); dur();}
      else if(voice == "*korna çal") {korna_cal();}
      else if(voice == "*sola bak"||voice == "*soluna bak") {sola_bak();}
      else if(voice == "*sağa bak"||voice == "*sağına bak") {saga_bak();}
      else if(voice == "*önüne bak"||voice == "*öne bak") {one_bak();}
      else if(voice == "*far aç") {far_ac();}
      else if(voice == "*far kapat") {far_kapa();}
  voice=""; 
  }
}

void sensor_olcum_on()
{
  uzaklik = sonar.ping_cm();
  Serial.print(uzaklik);
  delay(100);
  if (uzaklik <= 30){
    dur();
    }
  else{
    ileri();
    delay(500);
    dur();
    }
}
void sensor_olcum_sag()
{
  uzaklik = sonar.ping_cm();
  Serial.print(uzaklik);
  delay(100);
  if (uzaklik <= 16){
    dur();}
  else {
    sag();
    delay(224);
    dur();}
}
void sensor_olcum_sol()
{
  uzaklik = sonar.ping_cm();
  Serial.print(uzaklik);
  delay(100);
  if (uzaklik <= 16){
    dur();}
  else {
    sol();
    delay(224);
    dur();}
}
void biraz_ileri_on()
{
  uzaklik = sonar.ping_cm();
  Serial.print(uzaklik);
  delay(100);
  if (uzaklik <= 15){
    dur();
    }
  else{
    biraz_ileri();
    delay(250);
    dur();
    }
}
void biraz_saga_engel()
{
  uzaklik = sonar.ping_cm();
  Serial.print(uzaklik);
  delay(100);
  if (uzaklik <= 6){
    dur();}
  else {
    biraz_saga();
    delay(112);
    dur();}
}
void biraz_sola_engel()
{
  uzaklik = sonar.ping_cm();
  Serial.print(uzaklik);
  delay(100);
  if (uzaklik <= 6){
    dur();}
  else {
    biraz_sola();
    delay(112);
    dur();}
}
void ileri() 
{
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  digitalWrite(MotorRE, HIGH);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  digitalWrite(MotorLE, HIGH);
}
  
void geri() 
{
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, HIGH);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, HIGH);
}
  
void sag()
{
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, 30);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  digitalWrite(MotorLE, 30);
}
  
void sol()
{
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  digitalWrite(MotorRE, 30);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, 30);
}
void dur()
{
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, 0);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, 0);
}
void biraz_ileri()
{
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  digitalWrite(MotorRE, 100);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  digitalWrite(MotorLE, 100);
}
void biraz_geri()
{
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, 100);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, 100);
  }
void biraz_saga()
{ 
  digitalWrite(MotorR1, HIGH);
  digitalWrite(MotorR2, LOW);
  digitalWrite(MotorRE, 10);

  digitalWrite(MotorL1, LOW);
  digitalWrite(MotorL2, HIGH);
  digitalWrite(MotorLE, 10);
}
void biraz_sola()
{
  digitalWrite(MotorR1, LOW);
  digitalWrite(MotorR2, HIGH);
  digitalWrite(MotorRE, 10);

  digitalWrite(MotorL1, HIGH);
  digitalWrite(MotorL2, LOW);
  digitalWrite(MotorLE, 10);
}
void saga_bak()
{
  myServo.write(0);
  delay(1000);
}
void sola_bak()
{
  myServo.write(180);
  delay(1000);
}
void one_bak()
{
  myServo.write(90);
  delay(1000);
}
void korna_cal()
{
 digitalWrite(buzzerPin,HIGH); 
 delay(1000);                  
 digitalWrite(buzzerPin,LOW); 
}
void far_ac()
{
  digitalWrite(LED1, HIGH);
  digitalWrite(LED2, HIGH);
}
void far_kapa()
{
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
}
