/*-------- SUBROUTINES --------  ACTIONS  */
void check_ptt_status(unsigned int PttInput, bool when) {
  //static int DegreesPttReturnTo;
  if ((millis() - last_ptt_checking_time) > delays.PTT_IN_RATE || (when == NOW)) {
      if (!digitalRead(ptt_in_1)) {
        if (!PTT_1_Engaged) {
          PTT_1_Engaged = true;
          bool Engagement_Completed = false;
          int Actions_Completed = 0;
          #if defined (debug)
            control_port->println("PTT 1 Engaged");
          #endif
          digitalWrite(builtin_led, HIGH);
          digitalWrite(ptt_out_1, HIGH);
          digitalWrite(ptt_out_2, HIGH);
          digitalWrite(ptt_out_3, HIGH);
          digitalWrite(ptt_out_4, HIGH);
          digitalWrite(dc_control_1, HIGH);
          digitalWrite(dc_control_2, HIGH);
          /*
            unsigned int PTT_IN_RATE = 100;
            unsigned int PTT_OUT_1_DELAY_ON = 0;
            unsigned int PTT_OUT_2_DELAY_ON = 50;
            unsigned int PTT_OUT_3_DELAY_ON = 100;
            unsigned int PTT_OUT_4_DELAY_ON = 150;
            unsigned int DC_CONTROL_1_DELAY_ON = 0;
            unsigned int DC_CONTROL_2_DELAY_ON = 100;
            unsigned int PTT_OUT_1_DELAY_OFF = 0;
            unsigned int PTT_OUT_2_DELAY_OFF = 50;
            unsigned int PTT_OUT_3_DELAY_OFF = 100;
            unsigned int PTT_OUT_4_DELAY_OFF = 150;
            unsigned int DC_CONTROL_1_DELAY_OFF = 0;
            unsigned int DC_CONTROL_2_DELAY_OFF = 100;
            unsigned int DEBOUNCE_DELAY = 10;
  */
        }
        else {
//           control_port->println("PTT 1 Activated");
        }
      }
      else {
        if (PTT_1_Engaged) {
          PTT_1_Engaged = false;
          #if defined (debug)
            control_port->println("PTT 1 De-engaged");
          #endif
          digitalWrite(builtin_led, LOW);
          digitalWrite(ptt_out_1, LOW);
          digitalWrite(ptt_out_2, LOW);
          digitalWrite(ptt_out_3, LOW);
          digitalWrite(ptt_out_4, LOW);
          digitalWrite(dc_control_1, LOW);
          digitalWrite(dc_control_2, LOW);      
        }
        else {
//          control_port->println("PTT 1 De-activated");
        }
      }
    last_ptt_checking_time=millis();
  }
} /* END check_ptt_status() */

