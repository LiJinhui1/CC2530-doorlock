/******************************************************************************
  Filename:       AT_timer4.c
  Author:         Yang Wang
******************************************************************************/
#include "AT_timer4.h"
#include "hal_defs.h"

void AT_Timer4_Set_Clear_Start_US(uint8 us)
{
  // Set timer 4 channel 0 compare mode 
  T4CCTL0 |= BV(2);

  // Set the overflow value
  /*T1CC0L = LO_UINT8( us );
  T1CC0H = HI_UINT8( us );*/
  T4CC0 = us;

  // Set the 16-bit counter to 0x0000
  /*T1CNTL = 0x00;
  T1CNTH = 0x00; // actually invalid*/
  T4CNT = 0x00;
  // Set prescaler divider value, operating mode and start timer 1
  T1CTL = 0x0A;         //32分频,重复计数到设定值

  T4IF = 0;
}
uint8 AT_Timer4_Stop_Get(void)
{
  T4CTL = 0x00;

  return T4CNT;
}
