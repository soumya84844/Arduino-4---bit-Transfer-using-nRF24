/*
 * This is a 1 channel nrf24l01 transmitter and receiver code.
 * There is a single input(push button) in the transmitter which can control the led in receiver;
 * 
 * To know more refer the below links:
 *  https://youtu.be/UoeU79G09Dk
 *  https://dhirajkushwaha.com/elekkrypt
 *  
 */


#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

RF24 radio(7,8);   // declaring CE and CSN pins
const byte address[] = "node1"; 

String d2 = "0";
String d3 = "0";
String d5 = "0";
String d6 = "0";

void setup() {
  radio.begin();  // initializes the operations of the chip
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();    
  Serial.begin(9600);
 
  pinMode(2, INPUT); // declares pushButton as an input
  pinMode(3, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);

}
                                                                          

void loop() {
  d2 = String(digitalRead(2));
  d3 = String(digitalRead(3));
  d5 = String(digitalRead(5));
  d6 = String(digitalRead(6));

  String command = d2 + d3 + d5 + d6;
  
  radio.write(&command, sizeof(command));
  
}
