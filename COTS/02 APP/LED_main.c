#include		"util_delay.h"
#include		"Std_Types.h"
#include		"Bit_Math.h"


#include		"DIO_interface.h"
#include		"LED_interface.h"

int main(void)
{
	/*	Init 				*/
	/*	LED0 = OUTPUT 		*/
	LED_voidLedInit(LED0);
	
	while(1)
	{
		/*	LED ON C7 			*/
		LED_voidSetLedValue(LED0,HIGH);
		LED_voidSetLedValue(LED1,HIGH);
		LED_voidSetLedValue(LED2,HIGH);
		_delay_ms(2000);
		LED_voidSetLedValue(LED0,LOW);
		LED_voidSetLedValue(LED1,LOW);
		LED_voidSetLedValue(LED2,LOW);
		_delay_ms(2000);	
	}
	return 0 ;
}