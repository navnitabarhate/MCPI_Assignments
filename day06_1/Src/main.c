

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "lcd.h"
#include"switch.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	SystemInit();
	LcdInit();
	uint8_t count=0;
	char str[16];
	SwitchInit(SWITCH);

	while(1)
	{

		while(exti0_flag==0)
			;

	LcdPuts(LCD_LINE1, "NAVNITA BARHATE");
	//LcdPuts(LCD_LINE2, "GOD BLESS YOU");

	sprintf(str,"count=%d",count);
	count++;
	LcdPuts(LCD_LINE2,str);
	exti0_flag=0;
	}
	return 0;
}







