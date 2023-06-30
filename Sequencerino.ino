/*
  N5NHJ Arduino Sequencer
  2 PTT inputs
  2 DC carring outputs with no delay
  4 Sequenced PTT outputs
  Remote Controlled and Nextion Interfaced?
  Copyright 2023 Massimo 'Max' Mucci, N5NHJ
  max.i8nhj@gmail.com
  n5nhj@yahoo.com
  
  Sequencerino is distributed under the MIT license.
*/
 
#define CODE_VERSION "V1-" __DATE__ " N5NHJ"
// #define DEBUG

#define CONTROL_PORT_SERIAL_PORT_CLASS HardwareSerial
// #define NEXTION_PORT_SERIAL_PORT_CLASS HardwareSerial

#include <EEPROM.h>

#include "Sequencerino_Settings.h"
#include "Sequencerino_Pins.h"
// #include "FaraRotation_Commands.h"
#include "Sequencerino_Enums.h"

/*-------- VARIABLES --------*/
CONTROL_PORT_SERIAL_PORT_CLASS *control_port;

// NEXTION_PORT_SERIAL_PORT_CLASS *nextion_port;
// char nextion_port_buffer[COMMAND_BUFFER_SIZE];

unsigned long last_ptt_checking_time = 0;

//struct Conf {
//  unsigned int Ptt_in;
//  unsigned int Ptt_out_1;
//  unsigned int Ptt_out_2;
//  unsigned int Ptt_out_3;
//  unsigned int Ptt_out_4;
//  unsigned int Dc_control_1;
//  unsigned int Dc_control_2;
//} configuration_data;

bool Ptt_1 = false;
bool Ptt_2 = false;
bool PTT_1_Engaged = false;
bool PTT_2_Engaged = false;
timing delays;

void setup() {
  initialize_serial();
  initialize_pins();
  initialize_eeprom(NOW);
  // send_info_to_nextion(NOW);
  // send_status_to_nextion(NOW);
  #ifdef DEBUG
    control_port->println(CODE_VERSION);
  #endif
}

void loop() {
  check_ptt_status(1,TIMED);
  // #if defined (PTT_2_ENABLED)
  //  check_ptt_status(2,TIMED);
  // #endif
  // send_info_to_nextion(TIMED);
  // send_status_to_nextion(TIMED);
}
