#include "iodefine.h"
#include "timerA.h"
#include "led.h"

void initTimerA(void)
{
	
	st_ta.TMA.BYTE=0x10;// 0001 0000
	un_irr1.BIT.IRRTA=0;
  	un_ienr1.BI.IENTA=1;
}

#pragma section
 __interrupt(vect=19) void INT_TimerA(void) 
{
	IO.PDR8.BIT.B1=0;
}