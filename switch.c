//J Barrett Chesebrough
//switch.c
//switch functions for interrupts. button mapping. 

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include "macros.h"

// Global Variables
extern char display_line[4][11];
extern char *display[4];
extern unsigned char display_mode;
extern volatile unsigned char display_changed;
extern volatile unsigned int update_display_count;
extern volatile unsigned char update_display;
extern volatile char event;
extern volatile char end;

void enable_switch_SW1(void)
{
// Enable switch SW1 interrupt
  P5OUT |= SW1;                // Configure pullup resistor
  P5REN |= SW1;                // Enable pullup resistor
}

void enable_switch_SW2(void)
{
// Enable switch SW2 interrupt
  P5OUT |= SW2;                // Configure pullup resistor
  P5REN |= SW2;                // Enable pullup resistor
}

void Switches_Process(void)
{
//  unsigned char trouble;
  if (!(P5IN & SW1))
  {
    strcpy(display_line[0], "--------");
    update_string(display_line[0], 0);
    strcpy(display_line[1], "triangle ");
    update_string(display_line[1], 1);
    strcpy(display_line[2], "--------");
    update_string(display_line[3], 3);
    enable_display_update();
    event= TRIANGLE;
  }
  
  if (!(P5IN & SW2)) 
  {
    strcpy(display_line[0], "---------");
    update_string(display_line[0], 0);
    strcpy(display_line[1], " circle  ");
    update_string(display_line[1], 1);
    strcpy(display_line[2], "---------");
    update_string(display_line[3], 3);
    enable_display_update();
    event=CIRCLE;
  }
}