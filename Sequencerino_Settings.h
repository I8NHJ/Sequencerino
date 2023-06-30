#define CALLSIGN "  N5NHJ  "          // ATTENTION!: Max 9 characters

/* Serial Port Settings */
#define CONTROL_PORT_MAPPED_TO &Serial
#define CONTROL_PORT_BAUD_RATE 115200

/* Nextion Serial Port Settings */
// #define NEXTION_PORT_MAPPED_TO &Serial3
// #define NEXTION_PORT_BAUD_RATE 115200

/* PROGRAM FEATURES */
//#define PTT_2_ENABLED

/* TIMING CONFIGURATION */
struct timing {
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
};







