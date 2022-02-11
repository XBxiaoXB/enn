#include "iodefine.h"
#include "machine.h"
#include "intsw.h"
#include "led.h"
void initSWint(void)
{
    unsigned char i=IO.PCR1;
	
	IO.PMR1.BIT.IRQ2=1;
	IO.PMR1.BIT.IRQ3=1;	
	
	//IEGR1.BIT.NMIEG=1;
	IEGR1.BIT.IEG2=1;
	IEGR1.BIT.IEG3=1;
	IRR1.BIT.IRRI2=0;
	IRR1.BIT.IRRI3=0;
	IENR1.BIT.IEN2=1;
	IENR1.BIT.IEN3=1;
	
	IO.PCR1=0x00;
	IO.PDR8.BIT.B1=1;
	IO.PCR8=0x46;
	
}
#pragma section IntPRG
__interrupt(vect=16) void INT_IRQ2(void) {
	IRR1.BIT.IRRI2=0;
	IO.PDR8.BIT.B1=1;
	}
__interrupt(vect=17) void INT_IRQ3(void) {
	IRR1.BIT.IRRI3=0;
	IO.PDR8.BIT.B1=0;
	}

