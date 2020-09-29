#include"pitches.h"

int led1 = 2;
//int led2 = 3;
int led3 = 4;
int led4 = 5;
int led5 = 6;
int led6 = 7;
int led7 = 8;
int led8 = 9;
int led9 = 10;
int led10 = 11;
//int led11 = 12;
int led12 = 13;

int buttonPin = 52;
int buttonValue;

int eredusMass[5] = {255, 64, 32, 16, 0};
int jarjestusMassVasak[5] = {led7, led8, led9, led10, led12};
int jarjestusMassParem[5] = {led6, led5, led4, led3, led1};

int melody[] = {
  NOTE_D4, NOTE_G4, END};

int noteDurations[] = {       //duration of the notes
2,4
};
int speed=90;  //higher value, slower notes

void setup() {
Serial.begin(9600);
pinMode(52, INPUT);
digitalWrite(52, HIGH);
pinMode(led1,OUTPUT);
//pinMode(led2,OUTPUT);
pinMode(led3,OUTPUT);
pinMode(led4,OUTPUT);
pinMode(led5,OUTPUT);
pinMode(led6,OUTPUT);
pinMode(led7,OUTPUT);
pinMode(led8,OUTPUT);
pinMode(led9,OUTPUT);
pinMode(led10,OUTPUT);
//pinMode(led11,OUTPUT);
pinMode(led12,OUTPUT);
pinMode(50,OUTPUT);

}

void loop() {
 buttonValue=digitalRead(buttonPin);
 if (buttonValue == 0){
  melody1();
  for (int i = 0; i<=4; i++){
     for (int n = 0; n<= 4; n++){
       analogWrite(jarjestusMassVasak[n], eredusMass[i]);
      analogWrite(jarjestusMassParem[n], eredusMass[i]);
      delay(50);
  }
 }
 digitalWrite(50,HIGH);
 delay(2);
 digitalWrite(50,LOW);
 delay(2);
 
}
}
void melody1() {
  for (int thisNote = 0; melody[thisNote]!=-1; thisNote++) {
    int noteDuration = speed*noteDurations[thisNote];
    tone(3, melody[thisNote],noteDuration*.95);
    delay(noteDuration);
    noTone(3);
  }
  }
