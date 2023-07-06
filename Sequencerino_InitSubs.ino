/*-------- SUBROUTINES --------  INITIALIZATIONS  */

void initialize_eeprom(bool when) {
  #ifdef USE_EEPROM
    byte value = EEPROM.read(0);
    if (value != 1 || (when == NOW)) {
      #ifdef DEBUG
        control_port->println("Init EEPROM");
      #endif
      EEPROM.write(0, 1);
      EEPROM.put(1, delays);
    } else {
      EEPROM.get(1, delays);
    }
    #ifdef DEBUG
      control_port->print("PTT_IN_RATE \t");
      control_port->println(delays.PTT_IN_RATE);
      control_port->print("PTT_OUT_0_DELAY_ON \t");
      control_port->println(delays.PTT_OUT_0_DELAY_ON);
      control_port->print("PTT_OUT_1_DELAY_ON \t");
      control_port->println(delays.PTT_OUT_1_DELAY_ON);
      control_port->print("PTT_OUT_2_DELAY_ON \t");
      control_port->println(delays.PTT_OUT_2_DELAY_ON);
      control_port->print("PTT_OUT_3_DELAY_ON \t");
      control_port->println(delays.PTT_OUT_3_DELAY_ON);
      control_port->print("DC_CONTROL_0_DELAY_ON \t");
      control_port->println(delays.DC_CONTROL_0_DELAY_ON);
      control_port->print("DC_CONTROL_1_DELAY_ON \t");
      control_port->println(delays.DC_CONTROL_1_DELAY_ON);
      control_port->print("PTT_OUT_0_DELAY_OFF \t");
      control_port->println(delays.PTT_OUT_0_DELAY_OFF);
      control_port->print("PTT_OUT_1_DELAY_OFF \t");
      control_port->println(delays.PTT_OUT_1_DELAY_OFF);
      control_port->print("PTT_OUT_2_DELAY_OFF \t");
      control_port->println(delays.PTT_OUT_2_DELAY_OFF);
      control_port->print("PTT_OUT_3_DELAY_OFF \t");
      control_port->println(delays.PTT_OUT_3_DELAY_OFF);
      control_port->print("DC_CONTROL_0_DELAY_OFF \t");
      control_port->println(delays.DC_CONTROL_0_DELAY_OFF);
      control_port->print("DC_CONTROL_1_DELAY_OFF \t");
      control_port->println(delays.DC_CONTROL_1_DELAY_OFF);
      control_port->print("SEQUENCE_LED_ON_TIME \t");
      control_port->println(delays.SEQUENCE_LED_ON_TIME);
      control_port->print("DEBOUNCE_DELAY \t");
      control_port->println(delays.DEBOUNCE_DELAY);
    #endif
  #endif
} /* END initialize_eeprom() */

void initialize_serial() {
  #ifdef DEBUG
    control_port = CONTROL_PORT_MAPPED_TO;
    control_port->begin(CONTROL_PORT_BAUD_RATE);
    control_port->flush();
    control_port->println(F("\r\n---\r\nApp started"));
    control_port->flush();
    control_port->println("initialize_serial(control_port) complete");
    control_port->flush();
  #endif
} /* END initialize_serial() */

void initialize_pins() {
  // LEDs
  if (ptt_in_0_engaged_led != 0) {
    #ifdef DEBUG
      control_port->println("LED PTT0 defined");
    #endif
    pinMode(ptt_in_0_engaged_led, OUTPUT);
    digitalWrite(ptt_in_0_engaged_led, LOW);
  }

  if (ptt_in_1_engaged_led != 0) {    
    pinMode(ptt_in_1_engaged_led, OUTPUT);
    #ifdef DEBUG
      control_port->println("LED PTT1 defined");
    #endif
    digitalWrite(ptt_in_1_engaged_led, LOW);
  }

  if (sequence_completed_led != 0) {
    pinMode(sequence_completed_led, OUTPUT);
    #ifdef DEBUG
      control_port->println("LED SEQUENCE defined");
    #endif
    digitalWrite(sequence_completed_led, LOW);
  }

  if (ptt_out_0_engaged_led != 0) {
    pinMode(ptt_out_0_engaged_led, OUTPUT);
    #ifdef DEBUG
      control_port->println("LED PTT OUT0 defined");
    #endif
    digitalWrite(ptt_out_0_engaged_led, LOW);
  }

  if (ptt_out_1_engaged_led != 0) {
    pinMode(ptt_out_1_engaged_led, OUTPUT);
    #ifdef DEBUG
      control_port->println("LED PTT OUT1 defined");
    #endif
    digitalWrite(ptt_out_1_engaged_led, LOW);
  }
  
  if (ptt_out_2_engaged_led != 0) {
    pinMode(ptt_out_2_engaged_led, OUTPUT);
    #ifdef DEBUG
      control_port->println("LED PTT OUT2 defined");
    #endif
    digitalWrite(ptt_out_2_engaged_led, LOW);
  }

  if (ptt_out_3_engaged_led != 0) {
    pinMode(ptt_out_3_engaged_led, OUTPUT);
    #ifdef DEBUG
      control_port->println("LED PTT OUT3 defined");
    #endif
    digitalWrite(ptt_out_3_engaged_led, LOW);
  }

  if (dc_0_engaged_led != 0) {
    pinMode(dc_0_engaged_led, OUTPUT);
    #ifdef DEBUG
      control_port->println("LED DC0 defined");
    #endif
    digitalWrite(dc_0_engaged_led, LOW);
  }
 
  if (dc_1_engaged_led != 0) {
    pinMode(dc_1_engaged_led, OUTPUT);
    #ifdef DEBUG
      control_port->println("LED DC1 defined");
    #endif
    digitalWrite(dc_1_engaged_led, LOW);
  }

  // define pins and set controls to default status
  if (PTT_0_ENABLED) {pinMode(ptt_in_0, INPUT_PULLUP);}
  if (PTT_1_ENABLED) {pinMode(ptt_in_1, INPUT_PULLUP);}

  if (PTT_OUT_0_ENABLED) {
    pinMode(ptt_out_0, OUTPUT);
      if (PTT_OUT_0_NORMAL_LOW) {digitalWrite(ptt_out_0, LOW);} else {digitalWrite(ptt_out_0, HIGH);}
    }

  if (PTT_OUT_1_ENABLED) {
    pinMode(ptt_out_1, OUTPUT);
    if (PTT_OUT_1_NORMAL_LOW) {digitalWrite(ptt_out_1, LOW);} else {digitalWrite(ptt_out_1, HIGH);}
  }
  
  if (PTT_OUT_2_ENABLED) {
    pinMode(ptt_out_2, OUTPUT);
    if (PTT_OUT_2_NORMAL_LOW) {digitalWrite(ptt_out_2, LOW);} else {digitalWrite(ptt_out_2, HIGH);}
  }

  if (PTT_OUT_3_ENABLED) {
    pinMode(ptt_out_3, OUTPUT);
    if (PTT_OUT_3_NORMAL_LOW) {digitalWrite(ptt_out_3, LOW);} else {digitalWrite(ptt_out_3, HIGH);}
  }

  if (DC_CONTROL_0_ENABLED) {
    pinMode(dc_control_0, OUTPUT);
    if (DC_CONTROL_0_NORMAL_LOW) {digitalWrite(dc_control_0, LOW);} else {digitalWrite(dc_control_0, HIGH);}
  }

  if (DC_CONTROL_1_ENABLED) {
    pinMode(dc_control_1, OUTPUT);
    if (DC_CONTROL_1_NORMAL_LOW) {digitalWrite(dc_control_1, LOW);} else {digitalWrite(dc_control_1, HIGH);}
  }
  
  // set engagement status to default
  // bit 0 PTT_OUT_0 (0=DEACTIVATED, 1=ACTIVATED)
  // bit 1 PTT_OUT_1
  // bit 2 PTT_OUT_2
  // bit 3 PTT_OUT_3 
  // bit 4 DC_CONTROL_0
  // bit 5 DC_CONTROL_1
  // bit 7 NOT USED
  // bit 7 NOT USED
  engagement_status = B00000000;
} /* END initialize_pins() */
