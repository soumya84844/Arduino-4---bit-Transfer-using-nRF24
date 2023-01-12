#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7,8);
const byte address[] = "node1"; 

String d2 = "0";
String d3 = "0";
String d5 = "0";
String d6 = "0";

int sp = 0;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MAX);
  radio.stopListening();    
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0, INPUT);

}
                                                                          

void loop() {
  d2 = String(digitalRead(2));
  d3 = String(digitalRead(3));
  d5 = String(digitalRead(5));
  d6 = String(digitalRead(6));

  sp = map(analogRead(A0), 0, 1023, 0, 255);

  int state = 0;

  String command = d2 + d3 + d5 + d6;

  if(command == "0000") state = 0;
  else if(command == "1010") state = 1;
  else if(command == "0101") state = 2;
  else if(command == "1000") state = 3;
  else if(command == "0010") state = 4;
  else if(command == "0100") state = 5;
  else if(command == "0001") state = 6;
  else if(command == "0110") state = 7;
  else if(command == "1001") state = 8;
  
  radio.write(&state, sizeof(state));
  radio.write(&sp, sizeof(sp));
  
}
