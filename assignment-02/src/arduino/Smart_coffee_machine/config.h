/*
 *  This header file stores symbols that concerns 
 *  the configuration of the system.
 *
 */
#ifndef __CONFIG__
#define __CONFIG__
#define __DEBUG__

#define POT_PIN A0
#define TEMP_PIN A1
#define DISPLAY_SDA_PIN A4
#define DISPLAY_SCL_PIN A5

#define PIR_PIN 2
#define BUTTON_DOWN 3
#define BUTTON_MAKE 4
#define BUTTON_UP 5
#define SERVO_PIN 9

#define SONAR_TRIG_PIN 12
#define SONAR_ECHO_PIN 13

#define DISTANCE_FOR_DRINK_EXTRACTION 0.4
#define LIMITE_SERVO 180

#define SELF_CHECK_TIME 9000
#define INITIAL_MESSAGE_WAITING_TIME 500
#define IDLE_TIME 30000
#define TIME_MAKING_DRINK 6000//6s
#define TIME_TIMEOUT_BTN_MAKE 5000
#define TIME_WAITING_EXTRACTION 10000
 
#define SUGAR_QUANT 5
#define DRINKS_QUANTITY 10

#define TEMP_MIN 17
#define TEMP_MAX 24
  
#endif
