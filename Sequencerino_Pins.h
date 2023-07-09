/*-------- PTT IN pins definitions --------*/
#define ptt_in_0 2                            // Ground to activate
#define ptt_in_1 3                            // Ground to activate

/*-------- Sequenced PTT OUT pins definitions --------*/
#define ptt_out_0 4                           // Grounded when active
#define ptt_out_1 5
#define ptt_out_2 6
#define ptt_out_3 7

/*-------- DC OUT pins definitions --------*/
#define dc_control_0 8                        // If enabled carries 12V when PTT active
#define dc_control_1 9                       // If enabled carries 12V when PTT active

/*-------- LEDs pins definitions --------*/
#define ptt_in_0_engaged_led 11               // set to 0 to disable 
#define ptt_in_1_engaged_led 12            

#define sequence_completed_led 13             // Arduino built In LED   

#define ptt_out_0_engaged_led 14
#define ptt_out_1_engaged_led 15
#define ptt_out_2_engaged_led 16
#define ptt_out_3_engaged_led 17

#define dc_0_engaged_led 18
#define dc_1_engaged_led 19

     