

#include "timer.h"

void TimerInit(void) {

	RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;

	TIM6->PSC = TIM_PR-1;
}

void TimerDelayMs(uint32_t ms) {

	uint16_t cnt = (TCLK / 1000) * ms / TIM_PR;
	TIM6->ARR = cnt - 1;

	TIM6->CNT = 0;

	TIM6->CR1 |= TIM_CR1_CEN;

	while(! (TIM6->SR & TIM_SR_UIF))
		;

	TIM6->SR &= ~TIM_SR_UIF;

	TIM6->CR1 &= ~TIM_CR1_CEN;
}




