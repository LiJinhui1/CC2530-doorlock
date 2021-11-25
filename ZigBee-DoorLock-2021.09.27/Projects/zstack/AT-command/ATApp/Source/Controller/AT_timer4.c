/******************************************************************************
  Filename:       AT_timer4.c
  Author:         Yang Wang
******************************************************************************/
#include "AT_timer4.h"
#include "hal_defs.h"
uint8 tim4_tick_peroid=0;
void AT_Timer4_Set_Clear_Start_US(uint8 us)
{
  // Set timer 4 channel 0 compare mode 
  T4CCTL0 |= BV(2);

  // Set the overflow value
  /*T1CC0L = LO_UINT8( us );
  T1CC0H = HI_UINT8( us );*/
  T4CC0 = us;
  T4IE=1;
  // Set the 8-bit counter to 0x0000
  /*T1CNTL = 0x00;
  T1CNTH = 0x00; // actually invalid*/
  T4CNT = 0x00;
  // Set prescaler divider value, operating mode and start timer 1
  T4CTL |= 0xFE;         //128分频,开始计数，重复计数到设定值，清空counter
  tim4_tick_peroid = 0;
  T4IF = 0;
}
uint8 AT_Timer4_Stop_Get(void)
{
  T4CTL = 0x00;
  T4IE=0;
  return T4CNT;
}

HAL_ISR_FUNCTION( timer4_ovf_Isr, T4_VECTOR )
{
  HAL_ENTER_ISR();
  tim4_tick_peroid++;
  HAL_EXIT_ISR();
}
