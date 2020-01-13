//J Barrett Chesebrough
//shapes.c
//movement functions for run_straight, run_rectangle, run_circle, run_figure_eight, run_triangle
//movement state machines

#include  "msp430.h"
#include  "functions.h"
#include <string.h>
#include "macros.h"

char Last_Time_Sequence;
char cycle_time;
char time_change;
volatile char event;
int delay_start;
volatile char state;
int segment_count;
int right_motor_count;
int left_motor_count;
//extern volatile unsigned int Time_Sequence;

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
        Forward_Move();
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

void Forward_Move(void)
{
 Forward_On();                          //trust my process
}
  
void Run_Straight()
{
 switch(state)
 {
  case WAIT:                            // Begin
    wait_case();
    break;
 
  case START:                           // Begin
    start_case();
    break; 
 
  case RUN:                             // Run
    run_case();
    break; 
 
  case END:                            // End
    end_case();
    break; 
 
  default: 
    state=WAIT;
    break;
 
  }
}
void run_circle_case(void)
{
  if(time_change)
  {
    time_change = 0;
    if(segment_count <= TRAVEL_DISTANCE_CIRCLE)
    {
      if(right_motor_count++ >= RIGHT_COUNT_TIME_CIRCLE)
      {
        P3OUT &= ~R_FORWARD;
      }
      if(left_motor_count++ >= LEFT_COUNT_TIME_CIRCLE)
      {
        P3OUT &= ~L_FORWARD;
      }
      if(cycle_time >= WHEEL_COUNT_TIME)
      {
        cycle_time = 0;
        right_motor_count = 0;
        left_motor_count = 0;
        segment_count++;
        Forward_Move();
      }
    }
    else
    {
      state = END;
    }
  }
}

void Run_Circle(void)
 {
   switch(state)
   {
    case WAIT: // Begin
      wait_case();
      break;
 
    case START: // Begin
      start_case();
      break; 
 
    case RUN: // Run
      run_circle_case();
      break; 
 
    case END: // End
      end_case();
      break; 
 
     default: 
      state=WAIT;
     break;
 
    }
 }
void run_triangle_case(void)
{
  if(time_change)
  {
    int count=0;
    time_change = 0;
    while(count<=6)
    {
      if(segment_count <= TRAVEL_DISTANCE_TRIANGLEa)                       //TURN 1
      {
        if(right_motor_count++ >= RIGHT_COUNT_TIME_TRIANGLE)
        {
          P3OUT &= ~R_FORWARD;
        }
        if(left_motor_count++ >= LEFT_COUNT_TIME_TRIANGLE)
        {
          P3OUT &= ~L_FORWARD;
        }
        if(cycle_time >= WHEEL_COUNT_TIME)
        {
          cycle_time = 0;
          right_motor_count = 0;
          left_motor_count = 0;
          segment_count++;
          Forward_Move();
        }
      }
      else if(segment_count <= TRAVEL_DISTANCE_LEG1)                      //LEG 1
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
          Forward_Move();
        }
      }
      else 
        state = END;      
      count++;
      segment_count=0;
    }
      
  }
}

void Run_Triangle(void)
 {
   switch(state)
   {
    case WAIT: // Begin
      wait_case();
      break;
 
    case START: // Begin
      start_case();
      break; 
 
    case RUN: // Run
      run_triangle_case();
      break; 
 
    case END: // End
      end_case();
      break; 
 
     default: 
      state=WAIT;
     break;
 
    }
 }
   
 
 