/*-------- SUBROUTINES --------  INITIALIZATIONS  */

void initialize_eeprom(bool when) {
  byte value = EEPROM.read(0);
  if (value != 1|| (when == NOW)) {
    control_port->println("Init EEPROM");
    EEPROM.write(0, 1);
//    delays.PTT_IN_RATE = 1000;
//    delays.PTT_OUT_1_DELAY_ON = 0;
//    configuration_data.Ptt_out_1 = 0;
//    configuration_data.Ptt_out_2 = 50;
//    configuration_data.Ptt_out_3 = 100;
//    configuration_data.Ptt_out_4 = 150;
//    configuration_data.Dc_control_1 = 0;
//    configuration_data.Dc_control_2 = 100;
    EEPROM.put(1, delays);
  } else {
    EEPROM.get(1, delays);
  }
  #ifdef DEBUG
    control_port->println(delays.PTT_IN_RATE);
    control_port->println(delays.PTT_OUT_1_DELAY_ON);
  //  control_port->println(configuration_data.Ptt_out_2);
  //  control_port->println(configuration_data.Ptt_out_3);
  //  control_port->println(configuration_data.Ptt_out_4);
  //  control_port->println(configuration_data.Dc_control_1);
  //  control_port->println(configuration_data.Dc_control_2);
  #endif
} /* END initialize_eeprom() */

void initialize_serial() {
  control_port = CONTROL_PORT_MAPPED_TO;
  control_port->begin(CONTROL_PORT_BAUD_RATE);
  control_port->flush();
  #ifdef DEBUG
    control_port->println(F("\r\n---\r\nApp started"));
    control_port->flush();
    control_port->println("initialize_serial(control_port) complete");
    control_port->flush();
  #endif
  //nextion_port = NEXTION_PORT_MAPPED_TO;
  //nextion_port->begin(NEXTION_PORT_BAUD_RATE);
  //nextion_port->flush();
  //#ifdef DEBUG
  //  control_port->println("initialize_serial(nextion_port) complete");
  //  control_port->flush();
  //#endif
} /* END initialize_serial() */

void initialize_pins() {
  // define pins
  pinMode(ptt_in_1, INPUT_PULLUP);
  #if defined (PTT_2_ENABLED)
    pinMode(ptt_in_2, INPUT_PULLUP);
  #endif
  pinMode(ptt_out_1, OUTPUT);
  pinMode(ptt_out_2, OUTPUT);
  pinMode(ptt_out_3, OUTPUT);
  pinMode(ptt_out_4, OUTPUT);
  pinMode(dc_control_1, OUTPUT);
  pinMode(dc_control_2, OUTPUT);

  // set output controls to low
  digitalWrite(ptt_out_1, LOW);
  digitalWrite(ptt_out_2, LOW);
  digitalWrite(ptt_out_3, LOW);
  digitalWrite(ptt_out_4, LOW);
  digitalWrite(dc_control_1, LOW);
  digitalWrite(dc_control_2, LOW);
} /* END initialize_pins() */
