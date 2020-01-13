//J Barrett Chesebrough
//ports.c
//all port declarations and pin assignments

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include "macros.h"

void Init_Ports(void)
{
 Init_Port1();
 Init_Port2();
 Init_Port3();
 Init_Port4();
 Init_Port5();
 Init_Port6();
 Init_Port7();
 Init_Port8();
 Init_PortJ();
}
void Init_Port1(void)                   //configure port 1
{
 P1SEL0 = CLEAN;
 P1SEL1 = CLEAN;
 P1DIR  = CLEAN;
 //P1_0
 P1SEL0&= ~P1_0_LED1;
 P1SEL1&= ~P1_0_LED1;
 P1OUT |= P1_0_LED1;
 P1DIR |= P1_0_LED1;
 //P1_1
 P1SEL0&= ~P1_0_LED2;
 P1SEL1&= ~P1_0_LED2;
 P1OUT |= P1_0_LED2;
 P1DIR |= P1_0_LED2;
 //P1_2
 P1SEL0&= ~V_THUMB;
 P1SEL1&= ~V_THUMB;
 P1OUT &= ~V_THUMB;
 P1DIR |= V_THUMB;
 //P1_3
 P1SEL0|= TEST_PROBE;
 P1SEL1|= TEST_PROBE;
 //P1_4
 P1SEL0|= V_DETECT_R;
 P1SEL1|= V_DETECT_R;
 //P1_5
 P1SEL0&= ~V_DETECT_R;
 P1SEL1&= ~V_DETECT_R;
 P1OUT &= ~V_DETECT_R;
 P1DIR &= ~V_DETECT_R;
 //P1_6
 P1SEL0&= ~SD_MOSI;
 P1SEL1|= SD_MOSI;
 //P1_7
 P1SEL0&= ~SD_MISO;
 P1SEL1|= SD_MISO;
}

void Init_Port2(void)                   //configure port 2
{
  P2SEL0 = CLEAN;
  P2SEL1 = CLEAN;
  P2DIR  = CLEAN;
  //P2_0
  P2SEL0&= ~BCLUART_TXD;
  P2SEL1|= BCLUART_TXD;
  //P2_1
  P2SEL0&= ~BCLUART_RXD;
  P2SEL1|= BCLUART_RXD;
  //P2_2
  P2SEL0&= ~SD_SPICLK;
  P2SEL1|= SD_SPICLK;
  //P2_3
  P2SEL0&= ~P2_3;
  P2SEL1&= ~P2_3;
  P2DIR |= P2_3;
  //P2_4
  P2SEL0&= ~P2_4;
  P2SEL1&= ~P2_4;
  P2DIR |= P2_4;
  //P2_5
  P2SEL0&= ~J4_34;
  P2SEL1|= ~J4_34;
  P2DIR |= ~J4_34;
  //P2_6
  P2SEL0&= ~J4_35;
  P2SEL1&= ~J4_35;
  P2DIR |= J4_35;
  //P2_7
  P2SEL0&= ~P2_7;
  P2SEL1&= ~P2_7;
  P2DIR |= P2_7;
}

void Init_Port3(void){
  P3SEL0 = CLEAN;  
  P3SEL1 = CLEAN;  
  P3DIR  = CLEAN;
  
  //P3_4
  P3OUT &= ~L_REVERSE;   // Set the initial value Low so N-FET is off
  P3DIR |= L_REVERSE;    // Set direction to output
  //P3_5
  P3SEL0 &= ~L_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~L_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL1
  P3OUT &= ~L_FORWARD;   // Set the initial value Low so N-FET is off
  P3DIR |= L_FORWARD;    // Set direction to output
  //P3_6
  P3SEL0 &= ~R_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~R_REVERSE;  // Logically AND the inverse #define value with the Peripheral Register P3SEL1
  P3OUT &= ~R_REVERSE;   // Set the initial value Low so N-FET is off
  P3DIR |= R_REVERSE;    // Set direction to output
  //P3_7
  P3SEL0 &= ~R_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL0
  P3SEL1 &= ~R_FORWARD;  // Logically AND the inverse #define value with the Peripheral Register P3SEL1
  P3OUT &= ~R_FORWARD;   // Set the initial value Low so N-FET is off
  P3DIR |= R_FORWARD;    // Set direction to output
}

void Init_Port4(void)                   //configure port 4
{
  P4SEL0 = CLEAN;
  P4SEL1 = CLEAN;
  P4DIR  = CLEAN;
  //P4_0
  P4SEL0&= ~SD_CS;
  P4SEL1&= SD_CS;
  P4DIR &= SD_CS;
  //P4_1
  P4SEL0&= ~J4_31;
  P4SEL1&= ~J4_31;
  P4DIR &= ~J4_31;
  //P4_2
  P4SEL0&= ~J4_32;
  P4SEL1&= ~J4_32;
  P4DIR &= ~J4_32;
  //P4_3
  P4SEL0&= ~J4_33;
  P4SEL1&= ~J4_33;
  P4DIR &= ~J4_33;
  //P4_4
  P4SEL0|= UCB1_CS_LCD;
  P4SEL1&= ~UCB1_CS_LCD;
  P4DIR |= UCB1_CS_LCD;
  //P4_5
  P4SEL0&= ~P4_4;
  P4SEL1&= ~P4_4;
  P4DIR &= ~P4_4;
  //P4_6
  P4SEL0&= ~P4_5;
  P4SEL1&= ~P4_5;
  P4DIR &= ~P4_5;
  //P4_7
  P4SEL0&= ~J3_29;
  P4SEL1&= ~J3_29;
  P4DIR &= ~J3_29; 
}

void Init_Port5(void)                   //configure port 5
{
  P5SEL0 = CLEAN;
  P5SEL1 = CLEAN;
  P5OUT  = CLEAN;
  P5DIR  = CLEAN;
  //P5_0
  P5SEL0|= UCB1SIMO;
  P5SEL1&=~UCB1SIMO;
  P5OUT &=~UCB1SIMO;
  P5SEL1|= UCB1SIMO;
  
  //P5_1
  P5SEL0|= UCB1SOMI;
  P5SEL1&= ~UCB1SOMI;
  P5OUT &= ~UCB1SOMI;
  P5DIR |= UCB1SOMI;
  
  //P5_2
  P5SEL0|= UCB1SCK;
  P5SEL1&= UCB1SCK;
  P5OUT &= UCB1SCK;
  P5DIR |= UCB1SCK;
  //P5_3
  P5SEL0&= ~RESET_LCD;
  P5SEL1&= ~RESET_LCD;
  P5OUT |= RESET_LCD;
  P5DIR |= RESET_LCD;
  //P5_4
  P5SEL0&= ~P5_4;
  P5SEL1&= ~P5_4;
  P5DIR &= ~P5_4;
  //P5_5
  P5SEL0&= ~SW2;
  P5SEL1&= ~SW2;
  P5OUT &= ~SW2;
  P5DIR |= SW2;
  P5REN |= SW2;
  //P5_6
  P5SEL0&= ~SW1;
  P5SEL1&= ~SW1;
  P5OUT &= ~SW1;
  P5DIR |= SW1;
  P5REN |= SW1;
  //P5_7
  P5SEL0&= ~LCD_BACKLITE;
  P5SEL1&= ~LCD_BACKLITE;
  P5OUT |= LCD_BACKLITE;
  P5DIR |= LCD_BACKLITE;
}

void Init_Port6(void)                   //configure port 6
{
  P6SEL0 = CLEAN;
  P6SEL1 = CLEAN;
  P6DIR  = CLEAN;
  //P6_0
  P6SEL0&= ~UCA3TXD;
  P6SEL1&= ~UCA3TXD;
  P6OUT &= ~UCA3TXD;
  P6DIR &= ~UCA3TXD;
  //P6_1
  P6SEL0&= ~UCA3RXD;
  P6SEL1&= ~UCA3RXD;
  P6OUT &= ~UCA3RXD;
  P6DIR &= ~UCA3RXD;
  //P6_2
  P6SEL0&= ~J1_5;
  P6SEL1&= ~J1_5;
  P6OUT &= ~J1_5;
  P6DIR &= ~J1_5;
  //P6_3
  P6SEL0&= ~MAG_INT;
  P6SEL1&= ~MAG_INT;
  P6OUT &= ~MAG_INT;
  P6DIR &= ~MAG_INT;
  //P6_4
  P6SEL0&= ~P6_4;
  P6SEL1&= ~P6_4;
  P6OUT &= ~P6_4;
  P6DIR &= ~P6_4;
  //P6_5
  P6SEL0&= ~P6_5;
  P6SEL1&= ~P6_5;
  P6OUT &= ~P6_5;
  P6DIR &= ~P6_5;
  //P6_6
  P6SEL0&= ~P6_6;
  P6SEL1&= ~P6_6;
  P6OUT &= ~P6_6;
  P6DIR &= ~P6_6;
  //P6_7
  P6SEL0&= ~P6_7;
  P6SEL1&= ~P6_7;
  P6OUT &= ~P6_7;
  P6DIR &= ~P6_7;
}

void Init_Port7(void)                   //configure port 7
{
  P7SEL0 = CLEAN;
  P7SEL1 = CLEAN;
  P7DIR  = CLEAN;
  //P7_0
  P7SEL0|= ~I2CSDA;
  P7SEL1|= ~I2CSDA;
  P7OUT &= ~I2CSDA;
  P7DIR &= ~I2CSDA;
  //P7_1
  P7SEL0|= ~I2CSCL;
  P7SEL1|= ~I2CSCL;
  P7OUT &= ~I2CSDA;
  P7DIR &= ~I2CSDA;
  //P7_2
  P7SEL0&= ~SD_DETECT;
  P7SEL1&= ~SD_DETECT;
  P7OUT &= ~SD_DETECT;
  P7DIR &= ~SD_DETECT;
  //P7_3
  P7SEL0&= ~J4_36;
  P7SEL1&= ~J4_36;
  P7OUT &= ~J4_36;
  P7DIR &= ~J4_36;
  //P7_4
  P7SEL0&= ~P7_4;
  P7SEL1&= ~P7_4;
  P7OUT &= ~P7_4;
  P7DIR &= ~P7_4;
  //P7_5
  P7SEL0&= ~P7_5;
  P7SEL1&= ~P7_5;
  P7OUT &= ~P7_5;
  P7DIR &= ~P7_5;
  //P7_6
  P7SEL0&= ~P7_6;
  P7SEL1&= ~P7_6;
  P7OUT &= ~P7_6;
  P7DIR &= ~P7_6;
  //P7_7
  P7SEL0&= ~P7_7;
  P7SEL1&= ~P7_7;
  P7OUT &= ~P7_7;
  P7DIR &= ~P7_7;
}

void Init_Port8(void)                   //configure port 8
{
  P8SEL0 = CLEAN;
  P8SEL1 = CLEAN;
  P8DIR  = CLEAN;
  //P8_0
  P8SEL0&= ~IR_LED;
  P8SEL1&= ~IR_LED;
  //P8_1
  P8SEL0&= ~OPT_INT;
  P8SEL1&= ~OPT_INT;
  //P8_2
  P8SEL0&= ~TMP_INT;
  P8SEL1&= ~TMP_INT;
  //P8_3
  P8SEL0&= ~INT2;
  P8SEL1&= ~INT2;
}

void Init_PortJ(void)                   //configure port J
{
  PJSEL0 = CLEAN;
  PJSEL1 = CLEAN;
  PJDIR  = CLEAN;
  //PJ_0
  PJSEL0&= ~PJ_0;
  PJSEL1&= ~PJ_0;
  PJOUT &= ~PJ_0;
  PJDIR &= ~PJ_0;
  //PJ_1
  PJSEL0&= ~PJ_1;
  PJSEL1&= ~PJ_1;
  PJOUT &= ~PJ_1;
  PJDIR &= ~PJ_1;
  //PJ_2
  PJSEL0&= ~PJ_2;
  PJSEL1&= ~PJ_2;
  PJOUT &= ~PJ_2;
  PJDIR &= ~PJ_2;
  //PJ_3
  PJSEL0&= ~PJ_3;
  PJSEL1&= ~PJ_3;
  PJOUT &= ~PJ_3;
  PJDIR &= ~PJ_3;
  //PJ_4
  PJSEL0|= LFXIN;
  PJSEL1&= ~LFXIN;
  // PJOUT &= ~LFXIN;
  // PJDIR |= LFXIN;
  //PJ_5
  PJSEL0|= LFXOUT;
  PJSEL1&= ~LFXOUT;
  //PJOUT &= ~LFXOUT;
  // PJDIR |= LFXOUT;
  //PJ_6
  PJSEL0&= ~HFXOUT;
  PJSEL1&= ~HFXOUT;
  PJOUT &= ~HFXOUT;
  PJDIR |= HFXOUT;
  //PJ_7
  PJSEL0&= ~HFXOUT;
  PJSEL1&= ~HFXOUT;
  PJOUT &= ~HFXOUT;
  PJDIR |= HFXOUT;
}


