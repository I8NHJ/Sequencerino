#define CALLSIGN "  N5NHJ  "          // ATTENTION!: Max 9 characters

/* Serial Port Settings */
#define CONTROL_PORT_MAPPED_TO &Serial
//#define CONTROL_PORT_MAPPED_TO SerialUSB
#define CONTROL_PORT_BAUD_RATE 115200

#define DEBUG
// #define USE_EEPROM

/* PROGRAM FEATURES */
bool PTT_0_ENABLED = true;
bool PTT_1_ENABLED = true;

bool PTT_OUT_0_ENABLED = true;
bool PTT_OUT_1_ENABLED = true;
bool PTT_OUT_2_ENABLED = true;
bool PTT_OUT_3_ENABLED = true;
bool DC_CONTROL_0_ENABLED = true;
bool DC_CONTROL_1_ENABLED = true;

bool PTT_OUT_0_NORMAL_LOW = false;
bool PTT_OUT_1_NORMAL_LOW = false;
bool PTT_OUT_2_NORMAL_LOW = false;
bool PTT_OUT_3_NORMAL_LOW = false;
bool DC_CONTROL_0_NORMAL_LOW = false;
bool DC_CONTROL_1_NORMAL_LOW = false;

/* TIMING CONFIGURATION */
struct timing {
  unsigned int PTT_IN_RATE = 10;

  unsigned int PTT_OUT_0_DELAY_ON = 0;
  unsigned int PTT_OUT_1_DELAY_ON = 1000;
  unsigned int PTT_OUT_2_DELAY_ON = 2000;
  unsigned int PTT_OUT_3_DELAY_ON = 3000;
  unsigned int DC_CONTROL_0_DELAY_ON = 0;
  unsigned int DC_CONTROL_1_DELAY_ON = 100;
  
  unsigned int PTT_OUT_0_DELAY_OFF = 0;
  unsigned int PTT_OUT_1_DELAY_OFF = 0;
  unsigned int PTT_OUT_2_DELAY_OFF = 0;
  unsigned int PTT_OUT_3_DELAY_OFF = 0;
  unsigned int DC_CONTROL_0_DELAY_OFF = 0;
  unsigned int DC_CONTROL_1_DELAY_OFF = 100;
  
  unsigned int SEQUENCE_LED_ON_TIME = 1000;
  unsigned int DEBOUNCE_DELAY = 10;
};

/* Nextion Serial Port Settings */
// #define NEXTION_PORT_MAPPED_TO &Serial3
// #define NEXTION_PORT_BAUD_RATE 115200






