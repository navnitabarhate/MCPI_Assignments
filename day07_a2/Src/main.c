

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "uart.h"
#include "led.h"
#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[32];
	SystemInit();
	LedInit(LED_RED);
	LedInit(LED_BLUE);
	UartInit(BAUD_9600);
	int choice;
	while(1)
	{
	     UartPuts("Enter choice : 1. Red Led On 2. Red Led Off 3. Blue Led On 4. Blue Led Off\r\n");
	     UartGets(str);
	     scanf(str, "%d" , &choice);
	     switch(choice)
	     {
	     case 1 : LedOn(LED_RED);
	             break;

	     case 2 : LedOff(LED_RED);
	             break;

	     case 3 : LedOn(LED_BLUE);
	             break;

	     case 4 : LedOff(LED_BLUE);
	             break;

	     }

	}

	return 0;
}
5
