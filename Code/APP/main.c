#include "APP_Includes.h"


int main(void){
	u16 digitalValue, tempValue;
	ADC_void_Init();
	LCD_init();
	while(1){
		ADC_u8_Get_Digital_ValueSynchNonBlocking(0, &digitalValue);
		tempValue = digitalValue * 0.48828125;
		LCD_GoToXY(0, 0);
		LCD_DisplayInteger(tempValue);
		LCD_displayCharacter(0xdf);
		LCD_displayCharacter('C');
		
			if(tempValue < 20){
				DIO_u8SetPinDirection(3, 0, 1);
				DIO_u8SetPinValue(3, 0, 1);
			}
			
			else if(tempValue > 30){
				DIO_u8SetPinDirection(3, 1, 1);
				DIO_u8SetPinValue(3, 1, 1);
			}
			
			else{
				DIO_u8SetPinDirection(3, 0, 0);
				DIO_u8SetPinDirection(3, 1, 0);
			}
		
	}
	return 0;
}
