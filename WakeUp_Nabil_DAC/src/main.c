#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "STICK_interface.h"

#include "GPIO_private.h"

#include "wake.h"

volatile u16 i;

void voidSetDAC(void)
{
	GPIOA_ODR = wake_raw[i];
	i++;
	if (i==6649)
	{
		i=0;
	}
}

void main(void)
{

 	RCC_voidInitSystemClock();  /*system clk*/
	RCC_voidEnableClock(RCC_APB2,2);/*GPIOA*/

	MGPIO_voidSetPinDirection(GPIOA,0,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,1,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,2,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,3,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,4,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,5,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,6,0b0010);
	MGPIO_voidSetPinDirection(GPIOA,7,0b0010);

	MSTICK_voidInit();
	MSTICK_voidSetIntervalPeriodic(125,voidSetDAC);

while(1);


}
