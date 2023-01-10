#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7,8);
const byte address[] = "node1";

String command = "";

void setup() {
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MAX);
  radio.startListening();
  
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  
}


void loop() {
  while(radio.available()){
    int state = 0;  
    radio.read(&state, sizeof(state));

    if(state == 0) command = "0000";
    else if(state == 1) command = "1010";
    else if(state == 2) command = "0101";
    else if(state == 3) command = "1000";
    else if(state == 4) command = "0010";
    else if(state == 5) command = "0100";
    else if(state == 6) command = "0001";
    else if(state == 7) command = "0110";
    else if(state == 8) command = "1001";
    
    digitalWrite(2, value(command[0]));
    digitalWrite(3, value(command[1]));
    digitalWrite(4, value(command[2]));
    digitalWrite(5, value(command[3]));
  }

}

int value(char c)
{
  return String(c).toInt();
}
