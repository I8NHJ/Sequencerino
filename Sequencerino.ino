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

#define CONTROL_PORT_SERIAL_PORT_CLASS HardwareSerial
// #define NEXTION_PORT_SERIAL_PORT_CLASS HardwareSerial



#include "Sequencerino_Settings.h"
#include "Sequencerino_Pins.h"
#include "Sequencerino_Enums.h"

#ifdef USE_EEPROM
  #include <EEPROM.h>
#endif

/*-------- VARIABLES --------*/
CONTROL_PORT_SERIAL_PORT_CLASS *control_port;
// NEXTION_PORT_SERIAL_PORT_CLASS *nextion_port;
// char nextion_port_buffer[COMMAND_BUFFER_SIZE];

unsigned long last_ptt_checking_time = 0;
unsigned long ptt_engagement_time = 0;
unsigned long ptt_disengagement_time = 0;
unsigned long last_sequence_completed_time = 0;

const int ptt_in[2] = {ptt_in_0, ptt_in_1};
const int ptt_in_led[2] = {ptt_in_0_engaged_led, ptt_in_1_engaged_led};
// const int ptt_out[4] = {ptt_out_0, ptt_out_1, ptt_out_2, ptt_out_3};
// const int dc_out[2] = {dc_control_0, dc_control_1};

bool PTT_Engaged[2] = {false, false};
timing delays;

uint8_t engagement_status;

void setup() {
  #ifdef DEBUG
    initialize_serial();
    control_port->println(CODE_VERSION);
  #endif

  #ifdef USE_EEPROM
    initialize_eeprom(NOW);
  #endif

  initialize_pins();
}

void loop() {
  if (PTT_0_ENABLED) {check_ptt_status(0,TIMED);}
  if (PTT_1_ENABLED) {check_ptt_status(1,TIMED);}
  sequence_completed(false);
}
