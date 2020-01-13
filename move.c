//J Barrett Chesebrough
//move.c
//movement functions for run_straight, run_rectangle, run_circle, run_figure_eight
//movement state machines

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include "macros.h"

char Last_Time_Sequence;
char cycle_time;
char time_change;
char event;
int delay_start;
char state;
int segment_count;
int right_motor_count;
int left_motor_count;
extern volatile unsigned int Time_Sequence;

void start_case(void)
{
 cycle_time = 0;
 right_motor_count = 0;
 left_motor_count = 0;
 Forward_On();
 segment_count = 0;
 state = RUN;
}


void wait_case(void)
{
 if(time_change)
 {
   time_change = 0;
   if(delay_start++ >= WAITING2START)
   {
     delay_start = 0;
     state = START;
   }
 }
}

void run_case(void)
{
  if(time_change)
  {
    time_change = 0;
    if(segment_count <= TRAVEL_DISTANCE)
    {
      if(right_motor_count++ >= RIGHT_COUNT_TIME)
      {
        P3OUT &= ~R_FORWARD;
      }
      if(left_motor_count++ >= LEFT_COUNT_TIME)
      {
        P3OUT &= ~L_FORWARD;
      }
      if(cycle_time >= WHEEL_COUNT_TIME)
      {
        cycle_time = 0;
        right_motor_count = 0;
        left_motor_count = 0;
        segment_count++;
        //Forward_Move();
      }
    }
    else
    {
      state = END;
    }
  }
}

void end_case(void)
{
 Forward_Off();
 state = WAIT;
 event = NONE;
}

void Forward_On(void)
{
  P3OUT |= R_FORWARD; 
  P3OUT |= L_FORWARD;
}
void Forward_Off(void)
{
  P3OUT &= ~R_FORWARD;
  P3OUT &= ~L_FORWARD; 
}

void Run_Straight(char event)
{
  if(event==STRAIGHT)
  {
    state=WAIT;
  }
 switch(state)
 {
 case WAIT: // Begin
 wait_case();
 state=START;
 break;
 
 case START: // Begin
 start_case();
 state=RUN;
 break; 
 
 case RUN: // Run
 while(Time_Sequence<=20)
 {
 run_case();
 Time_Sequence++;
 }
 state=END;
 break; 
 
 case END: // End
 end_case();
 break; 
 
 default: break;
 
 }
}

 void Run_Circle(void)
 {
   start_case();
   
 }

   
 
 