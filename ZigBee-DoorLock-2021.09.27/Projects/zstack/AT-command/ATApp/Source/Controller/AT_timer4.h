/******************************************************************************
  Filename:       AT_timer4.h
  Author:         Yang Wang
******************************************************************************/
#ifndef AT_TIMER4_H
#define AT_TIMER4_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "ZComDef.h"
#include "hal_board.h"
  
extern uint8 tim4_tick_peroid;
extern bool head_flag;
extern void AT_Timer4_Set_Clear_Start_US(uint8 us);
extern uint8 AT_Timer4_Stop_Get(void);

#ifdef __cplusplus
}
#endif

#endif /* AT_TIMER1_H */
