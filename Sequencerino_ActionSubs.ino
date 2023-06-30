/*-------- SUBROUTINES --------  ACTIONS  */
void check_ptt_status(unsigned int PttInput, bool when) {
  //static int DegreesPttReturnTo;
  if ((millis() - last_ptt_checking_time) > delays.PTT_IN_RATE || (when == NOW)) {
      if (!digitalRead(ptt_in_1)) {
        if (!PTT_1_Engaged) {
          PTT_1_Engaged = true;
          control_port->println("PTT 1 Engaged");
          control_port->println(NOW);
        }
        else {
          control_port->println("PTT 1 Activated");
        }
      }
      else {
        if (PTT_1_Engaged) {
          PTT_1_Engaged = false;
          control_port->println("PTT 1 De-engaged");      
        }
        else {
          control_port->println("PTT 1 De-activated");
        }
      }
    last_ptt_checking_time=millis();
  }
} /* END check_ptt_status() */

