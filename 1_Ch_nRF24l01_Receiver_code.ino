/*
 * This is a 1 channel nrf24l01 transmitter and receiver code.
 * There is a single output(led control) in the receiver which can controlled with the pushbutton in transmitter;
 * 
 * To know more refer the below links:
 *  https://youtu.be/UoeU79G09Dk
 *  https://dhirajkushwaha.com/elekkrypt
 *  
 */


#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7,8); // declaring CE and CSN pins
const byte address[] = "node1";

String command = "";

void setup() {
  radio.begin(); // initializes the operations of the chip
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  
  pinMode(10, OUTPUT); // declares LEDpin as an output
  pinMode(9, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  
}


void loop() {
  while(radio.available()){  
    radio.read(&command, sizeof(command));
    analogWrite(10, value(command[0]));
    analogWrite(9, value(command[1]));
    analogWrite(4, value(command[2]));
    analogWrite(3, value(command[3]));
  }

}

int value(char c)
{
  int d = String(c).toInt();
  if(d == 0)
    return 0;
  else if(d == 1)
    return 1;
}
