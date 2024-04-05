
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "stm32f4xx.h"
#include "system_stm32f4xx.h"
#include "eeprom.h"
#include "uart.h"

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

int main(void)
{
	char str[90];
	int choice;
	char str1[90];

	SystemInit();
	UartInit(BAUD_9600);
	EEPROM_Init();

	do{
		  sprintf(str,"\n\r"
				  "menu : \n\r ,write string : 1\n\r,read string : 2\n\r");
		  UartPuts(str);

		   sprintf(str,"select your choice ");
		   UartPuts(str);
		   UartPuts(str);

		   sscanf(str,"%d",&choice);

		   switch(choice){

		   case 0 :
		      sprintf(str,"\n\r Thank You ! \n\r");
		      UartPuts(str);
		      break;

		   case 1 :
			     sprintf(str,"\n\rEnter the string :");
			     UartPuts(str);
			     UartGets(str);
			     sscanf(str,"%s",str1);
			     EEPROM_Write(0x0028,(uint8_t*)str1,32);
			     break;


			case 2 :
			   sprintf(str,"\n\rRead the string :\n\r");
			   UartPuts(str);
			   EEPROM_Read(0x0020,(uint8_t*)str1,32);
			   UartPuts(str1);
		   }
	}

			while(choice !=0);

	        while(1);

	        return 0;

}





























