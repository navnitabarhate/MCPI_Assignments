

#include <stdint.h>
#include <stdio.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"

#include "led.h"
#include "timer.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif


		int main(void)
		{
			SystemInit();
			DelayMs(1);
			LedInit(LED_GREEN);
			LedInit(LED_ORANGE);
			LedInit(LED_RED);
			LedInit(LED_BLUE);
			while(1) {
				LedOn(LED_GREEN);
				LedOn(LED_ORANGE);
				LedOn(LED_RED);
				LedOn(LED_BLUE);
				DelayMs(3000);
				LedOff(LED_GREEN);
				LedOff(LED_ORANGE);
				LedOff(LED_RED);
				LedOff(LED_BLUE);
				DelayMs(7000);
			}
			return 0;
		}




