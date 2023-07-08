/*-------- SUBROUTINES --------  ACTIONS  */
void check_ptt_status(unsigned int PttInput, bool when) {
  if ((millis() - last_ptt_checking_time) >= delays.PTT_IN_RATE || (when == NOW)) {
      if (!digitalRead(ptt_in[PttInput])) { // False when PTT active because the port is defined as input/pullup
        if (!PTT_Engaged[PttInput]) {

          delay (delays.DEBOUNCE_DELAY);
          if (!digitalRead(ptt_in[PttInput])) { 

            PTT_Engaged[PttInput] = true;
            digitalWrite(ptt_in_led[PttInput], HIGH);
            ptt_engagement_time=millis();
            bool Engagement_Not_Completed = true;
            while (Engagement_Not_Completed) {
              Engagement_Not_Completed = engage_ports();
            }
            sequence_completed(true);
            #ifdef DEBUG
              control_port->print("PTT Control ");
              control_port->print(PttInput);
              control_port->println(" Engaged");
            #endif
          }
          else {
            #ifdef DEBUG
              // control_port->println("PTT0 Activated");
            #endif
          }
        }
      }
      else {
        if (PTT_Engaged[PttInput]) {

          delay (delays.DEBOUNCE_DELAY);
          if (digitalRead(ptt_in[PttInput])) { 

            PTT_Engaged[PttInput] = false;
            digitalWrite(ptt_in_led[PttInput], LOW);
            ptt_disengagement_time = millis();
            bool disengagement_Not_Completed = true;
            while (disengagement_Not_Completed) {
              disengagement_Not_Completed = disengage_ports();
            }
            sequence_completed(true);
            #ifdef DEBUG
              control_port->print("PTT Control ");
              control_port->print(PttInput);
              control_port->println(" De-Engaged");
            #endif   
          }
          else {
            #ifdef DEBUG
              // control_port->println("PTT0 De-activated");
            #endif
          }
        }
      }
    last_ptt_checking_time = millis();
  }
} /* END check_ptt_status() */

bool engage_ports() {
  if (PTT_OUT_0_ENABLED) {
    if (((millis() - ptt_engagement_time) >= delays.PTT_OUT_0_DELAY_ON) && (bitRead(engagement_status, 0) == 0)) {
      #ifdef DEBUG
        control_port->print (ptt_engagement_time);
        control_port->print ("| PTT0 |");
        control_port->println (millis());
      #endif
      if (PTT_OUT_0_NORMAL_LOW) {digitalWrite(ptt_out_0, HIGH);} else {digitalWrite(ptt_out_0, LOW);}
      bitWrite(engagement_status, 0, 1);
    }
  }
  else {
    bitWrite(engagement_status, 0, 1);
  }  

  if (PTT_OUT_1_ENABLED) {
    if (((millis() - ptt_engagement_time) >= delays.PTT_OUT_1_DELAY_ON) && (bitRead(engagement_status, 1) == 0)) {
      #ifdef DEBUG
        control_port->print (ptt_engagement_time);
        control_port->print ("| PTT1 |");
        control_port->println (millis());
      #endif
      if (PTT_OUT_1_NORMAL_LOW) {digitalWrite(ptt_out_1, HIGH);} else {digitalWrite(ptt_out_1, LOW);}
      bitWrite(engagement_status, 1, 1);
    }
  }
  else {
    bitWrite(engagement_status, 1, 1);
  } 

  if (PTT_OUT_2_ENABLED) {
    if (((millis() - ptt_engagement_time) >= delays.PTT_OUT_2_DELAY_ON) && (bitRead(engagement_status, 2) == 0)) {
      #ifdef DEBUG
        control_port->print (ptt_engagement_time);
       control_port->print ("| PTT2 |");
       control_port->println (millis());
      #endif
      if (PTT_OUT_2_NORMAL_LOW) {digitalWrite(ptt_out_2, HIGH);} else {digitalWrite(ptt_out_2, LOW);}
      bitWrite(engagement_status, 2, 1);
    }
  }
  else {
    bitWrite(engagement_status, 2, 1);
  }

  if (PTT_OUT_3_ENABLED) { 
    if (((millis() - ptt_engagement_time) >= delays.PTT_OUT_3_DELAY_ON) && (bitRead(engagement_status, 3) == 0)) {
      #ifdef DEBUG
        control_port->print (ptt_engagement_time);
        control_port->print ("| PTT3 |");
        control_port->println (millis());
      #endif
      if (PTT_OUT_3_NORMAL_LOW) {digitalWrite(ptt_out_3, HIGH);} else {digitalWrite(ptt_out_3, LOW);}
      bitWrite(engagement_status, 3, 1);
    }
  }
  else {
    bitWrite(engagement_status, 3, 1);
  }

  if (DC_CONTROL_0_ENABLED) {
    if (((millis() - ptt_engagement_time) >= delays.DC_CONTROL_0_DELAY_ON) && (bitRead(engagement_status, 4) == 0)) {
      #ifdef DEBUG
        control_port->print (ptt_engagement_time);
        control_port->print ("| DC0 |");
        control_port->println (millis());
      #endif
      if (DC_CONTROL_0_NORMAL_LOW) {digitalWrite(dc_control_0, HIGH);} else {digitalWrite(dc_control_0, LOW);}
      bitWrite(engagement_status, 4 ,1);
    }
  }
  else {
    bitWrite(engagement_status, 4 ,1);
  } 

  if (DC_CONTROL_1_ENABLED) {
    if (((millis() - ptt_engagement_time) >= delays.DC_CONTROL_1_DELAY_ON) && (bitRead(engagement_status, 5) == 0)) {
      #ifdef DEBUG
        control_port->print (ptt_engagement_time);
        control_port->print ("| DC1 |");
        control_port->println (millis());
      #endif
      if (DC_CONTROL_1_NORMAL_LOW) {digitalWrite(dc_control_1, HIGH);} else {digitalWrite(dc_control_1, LOW);}
      bitWrite(engagement_status, 5 ,1);
    }
  }
  else {
    bitWrite(engagement_status, 5 ,1);
  } 

  if (engagement_status == B00111111) {
    #ifdef DEBUG
      control_port->print("Engaged ");
      control_port->println(engagement_status);
    #endif
    return false;
  }
  else {
    #ifdef DEBUG
  //  control_port->println("Still Engaging");
    #endif
    return true;
  }
} /* END engage_ports() */

bool disengage_ports() {
  if (PTT_OUT_0_ENABLED) {
    if (((millis() - ptt_disengagement_time) >= delays.PTT_OUT_0_DELAY_OFF) && (bitRead(engagement_status, 0) == 1) ) {
      #ifdef DEBUG
        control_port->print (ptt_disengagement_time);
        control_port->print ("| PTT0 |");
        control_port->println (millis());
      #endif
      if (PTT_OUT_0_NORMAL_LOW) {digitalWrite(ptt_out_0, LOW);} else {digitalWrite(ptt_out_0, HIGH);}
      bitWrite(engagement_status, 0, 0);
    }
  }
  else {
    bitWrite(engagement_status, 0, 0);
  }

  if (PTT_OUT_1_ENABLED) { 
    if (((millis() - ptt_disengagement_time) >= delays.PTT_OUT_1_DELAY_OFF) && (bitRead(engagement_status, 1) == 1) ) {
      #ifdef DEBUG
        control_port->print (ptt_disengagement_time);
        control_port->print ("| PTT1 |");
        control_port->println (millis());
      #endif
      if (PTT_OUT_1_NORMAL_LOW) {digitalWrite(ptt_out_1, LOW);} else {digitalWrite(ptt_out_1, HIGH);}
      bitWrite(engagement_status, 1, 0);
    }
  }
  else {
    bitWrite(engagement_status, 1, 0);
  }

  if (PTT_OUT_2_ENABLED) { 
    if (((millis() - ptt_disengagement_time) >= delays.PTT_OUT_2_DELAY_OFF) && (bitRead(engagement_status, 2) == 1) ) {
      #ifdef DEBUG
        control_port->print (ptt_disengagement_time);
        control_port->print ("| PTT2 |");
        control_port->println (millis());
      #endif
      if (PTT_OUT_2_NORMAL_LOW) {digitalWrite(ptt_out_2, LOW);} else {digitalWrite(ptt_out_2, HIGH);}
      bitWrite(engagement_status, 2, 0);
    }
  }
  else {
    bitWrite(engagement_status, 2, 0);
  }

  if (PTT_OUT_3_ENABLED) { 
    if (((millis() - ptt_disengagement_time) >= delays.PTT_OUT_3_DELAY_OFF) && (bitRead(engagement_status, 3) == 1) ) {
      #ifdef DEBUG
        control_port->print (ptt_disengagement_time);
        control_port->print ("| PTT3 |");
        control_port->println (millis());
      #endif
      if (PTT_OUT_3_NORMAL_LOW) {digitalWrite(ptt_out_3, LOW);} else {digitalWrite(ptt_out_3, HIGH);}
      bitWrite(engagement_status, 3, 0);
    }
  }
  else {
    bitWrite(engagement_status, 3, 0);
  } 

  if (DC_CONTROL_0_ENABLED) {
    if (((millis() - ptt_engagement_time) >= delays.DC_CONTROL_0_DELAY_ON) && (bitRead(engagement_status, 4) == 1) ) {
      #ifdef DEBUG
        control_port->print (ptt_disengagement_time);
        control_port->print ("| DC0 |");
        control_port->println (millis());
      #endif
      if (DC_CONTROL_0_NORMAL_LOW) {digitalWrite(dc_control_0, LOW);} else {digitalWrite(dc_control_0, HIGH);}
      bitWrite(engagement_status, 4 ,0);
    }
  }
  else {
    bitWrite(engagement_status, 4 ,0);
  } 
  
  if (DC_CONTROL_0_ENABLED) {
    if (((millis() - ptt_engagement_time) >= delays.DC_CONTROL_1_DELAY_ON) && (bitRead(engagement_status, 5) == 1) ) {
      #ifdef DEBUG
        control_port->print (ptt_disengagement_time);
        control_port->print ("| DC1 |");
        control_port->println (millis());
      #endif
      if (DC_CONTROL_1_NORMAL_LOW) {digitalWrite(dc_control_1, LOW);} else {digitalWrite(dc_control_1, HIGH);}
      bitWrite(engagement_status, 5 ,0);
    }
  }
  else {
    bitWrite(engagement_status, 5 ,0);    
  }

  if (engagement_status == B00000000) {
    #ifdef DEBUG
      control_port->print("Disengaged ");
      control_port->println(engagement_status);
    #endif
    return false;
  }
  else {
    #ifdef DEBUG
    //control_port->println("Still Engaged");
    #endif
    return true;
  }
} /* END disengage_ports() */

void sequence_completed(bool light_on) {
  if (light_on) {
    last_sequence_completed_time = millis();
    digitalWrite(sequence_completed_led, HIGH);
  }
  else {
    if (((millis() - last_sequence_completed_time) >= delays.SEQUENCE_LED_ON_TIME) && (digitalRead(sequence_completed_led))) {
      digitalWrite(sequence_completed_led, LOW);
    }
  }
}