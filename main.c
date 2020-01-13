//J Barrett Chesebrough
//main.c
//ya main c bby

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include "macros.h"

#define RESET_STATE             (0)
#define ALWAYS                  (1)
#define RED_LED              (0x01) // RED LED 0
#define GRN_LED              (0x02) // GREEN LED 1



// Global Variables
extern char pwm;
volatile char slow_input_down;
extern char display_line[4][11];
extern char *display[4];
unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned int update_display_count;
extern volatile unsigned char update_display;
extern volatile unsigned int Time_Sequence;
extern volatile char one_time;
//project 4 globals
extern char Last_Time_Sequence;
extern char cycle_time;
extern char time_change;
extern volatile char state;
extern volatile char event;

void main(void)
{
// Main Program
// This is the main routine for the program. Execution of code starts here.
// The operating system is Back Ground Fore Ground.


  Init_Ports();      
// Disable the GPIO power-on default high-impedance mode to activate
// previously configured port settings
  PM5CTL0 &= ~LOCKLPM5;
  Init_Clocks();                       // Initialize Clock System
  Init_Conditions();                   // Initialize Variables and Initial Conditions
  Init_Timers();                       // Initialize Timers

  Init_SPI_B1();                       // Initialize SPI Bus
  Init_LCD();                          // Initialize LCD
  five_msec_sleep(2);                  // 375 msec delay for the clock to settle
  Init_Switches();                     // Initialize Switches

  five_msec_sleep(2);
  display_mode = ORIGINAL;

  strcpy(display_line[0], "   NCSU   ");
  update_string(display_line[0], 0);
  strcpy(display_line[1], " WOLFPACK ");
  update_string(display_line[1], 1);
  strcpy(display_line[2], " ECE-306  ");
  update_string(display_line[3], 3);
  enable_display_update();


// Begining of the while OS

  while(ALWAYS)                         // Can the Operating system run
  {
    if(Last_Time_Sequence != Time_Sequence)
    {
      Last_Time_Sequence = Time_Sequence;
      cycle_time++;
      time_change = 1;
    }
    switch(event)
    {
    case STRAIGHT:                      // Straight
      Run_Straight();
      break;
      
    case CIRCLE:                        // Circle
      Run_Circle();
      break;
        
    case TRIANGLE:
      Run_Triangle();                   //Triangle
      break;
        
    default: break;
    
    } 

    switch(Time_Sequence)
    {
      case 125:                        // 1000 msec
        if(one_time)
        {
          Init_LEDs();                 // Initialize LEDs
          lcd_BIG_mid();
          display_changed = 1;
          one_time = 0;
        }
        Time_Sequence = 0;             //
        break;
        
      case 100:                        // 1000 msec
        if(one_time)
        {
          P1OUT |= GRN_LED;            // Change State of LED 5
          one_time = 0;
        }
        break;
        
      case 75:                         // 750 msec
        if(one_time)
        {
          P1OUT |= RED_LED;            // Change State of LED 4
          P1OUT &= ~GRN_LED;           // Change State of LED 5
          one_time = 0;
        }
        break;
        
      case 50:                         // 500 msec
        if(one_time)
        {
          P1OUT |= GRN_LED;            // Change State of LED 5
          lcd_4line();
          display_changed = 1;
          one_time = 0;
        }
        break;
        
      case  25:                        // 250 msec
        if(one_time)
        {
          P1OUT &= ~RED_LED;           // Change State of LED 4
          P1OUT &= ~GRN_LED;           // Change State of LED 5
          one_time = 0;
        }
        break;   
        
      default: break;
      
    }
    Switches_Process();                // Check for switch state change
    Display_Process();
  }
}

