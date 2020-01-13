//------------------------------------------------------------------------------
//
//  Description: This file contains the Main Routine - "While" Operating System
//
//
//  Jim Carlson
//  Aug 2017
//  Built with IAR Embedded Workbench Version: V7.10.2 (8.0.6.4651)
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include "macros.h"

#define R_FORWARD            (0x80) // P3_8   1000 0000    0111 1111
#define L_REVERSE            (0x10) // P3_5   0001 0000    1110 1111
#define L_FORWARD            (0x20) // P3_6   0010 0000    1101 1111
#define R_REVERSE            (0x40) // P3_7   0100 0000    1011 1111


void Init_Port3(void){
  P3SEL0 &= ~L_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0  
  P3SEL1 &= ~L_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL1

// The previous 2 lines set the P3SEL0 and P3SEL1 for Bit P3_5 to "0"

  P3OUT &= ~L_REVERSE;   // Set the initial value Low so N-FET is off
  P3DIR |= L_REVERSE;    // Set direction to output

  P3SEL0 &= ~L_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~L_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL1
  P3OUT &= ~L_FORWARD;   // Set the initial value Low so N-FET is off
  P3DIR |= L_FORWARD;    // Set direction to output

  P3SEL0 &= ~R_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~R_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL1
  P3OUT &= ~R_REVERSE;   // Set the initial value Low so N-FET is off
  P3DIR |= R_REVERSE;    // Set direction to output

  P3SEL0 &= ~R_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~R_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL1
  P3OUT &= ~R_FORWARD;   // Set the initial value Low so N-FET is off
  P3DIR |= R_FORWARD;    // Set direction to output
//------------------------------------------------------------------------------
}
