#define CALLSIGN "  N5NHJ  "          // ATTENTION!: Max 9 characters

/* Serial Port Settings */
#define CONTROL_PORT_MAPPED_TO &Serial
#define CONTROL_PORT_BAUD_RATE 115200

#define DEBUG
// #define USE_EEPROM                 // It can be usefull to add some external configuration methods

/* PROGRAM FEATURES */
bool PTT_0_ENABLED = true;
bool PTT_1_ENABLED = true;

bool PTT_OUT_0_ENABLED = true;
bool PTT_OUT_1_ENABLED = true;
bool PTT_OUT_2_ENABLED = true;
bool PTT_OUT_3_ENABLED = true;
bool DC_CONTROL_0_ENABLED = true;
bool DC_CONTROL_1_ENABLED = true;

bool PTT_OUT_0_NORMAL_LOW = true;
bool PTT_OUT_1_NORMAL_LOW = true;
bool PTT_OUT_2_NORMAL_LOW = true;
bool PTT_OUT_3_NORMAL_LOW = true;
bool DC_CONTROL_0_NORMAL_LOW = true;
bool DC_CONTROL_1_NORMAL_LOW = true;

/* TIMING CONFIGURATION 
  About timing between PTT IN closure and any PPT OUT or DC OUT closure:
    The closure Delay is the sum of those delays:
        machine_main_loop (<< microseconds, negligeble) +
        PTT_IN_RATE (milliseconds, configurable, the timeing the PTT closure is checked) +
        DEBOUNCE_DELAY (milliseconds, configurable, debounce time to make sure PTT IN has been engaged) +
        machine_action_loops (microseconds, negligeble) +
        PTT_OUT_x_DELAY_ON or DC_CONTROL_x_DELAY_ON (milliseconds, configurable, your desidered delay) +
        relay_operating_time and release_time (milliseconds, the delay of the relay or driving circuit of your choice. JQC-3F5VDC-5 Operate Time < 10 ms, Release Time < 5 ms)
    This logic applies to both engage and disengage.
    If you need accurate delay us an oscilloscope or other lab devices to verify.
    Always BE CONSERVATIVE!
*/ 

struct timing {
  unsigned int PTT_IN_RATE = 0;

  unsigned int PTT_OUT_0_DELAY_ON = 100;
  unsigned int PTT_OUT_1_DELAY_ON = 50;
  unsigned int PTT_OUT_2_DELAY_ON = 0;
  unsigned int PTT_OUT_3_DELAY_ON = 0;

  unsigned int DC_CONTROL_0_DELAY_ON = 0;
  unsigned int DC_CONTROL_1_DELAY_ON = 0;
  
  unsigned int PTT_OUT_0_DELAY_OFF = 0;
  unsigned int PTT_OUT_1_DELAY_OFF = 10;
  unsigned int PTT_OUT_2_DELAY_OFF = 0;
  unsigned int PTT_OUT_3_DELAY_OFF = 0;

  unsigned int DC_CONTROL_0_DELAY_OFF = 20;
  unsigned int DC_CONTROL_1_DELAY_OFF = 25;
  
  unsigned int SEQUENCE_LED_ON_TIME = 1000;
  unsigned int DEBOUNCE_DELAY = 5;
};







