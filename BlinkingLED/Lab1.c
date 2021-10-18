	/*/*
 * Lab1.c
 *
 * Created: 7/24/2018 7:05:14 PM
 * Author : ANUP
 */ 
#define F_CPU 16000000UL  // 16MHz clock from the debug processor
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		DDRB |= (1<<DDB5);  //0x20 (hex) // Set port bit B5 in data direction register to 1: an OUTput
		while(1){
			PORTB |= (1<<PORTB5); //Set port bit B5 to 1 to turn on the LED
			_delay_ms(100);  //delay 100ms
			PORTB &= ~(1<<PORTB5); //Clear port bit B5 to 0 to turn off the LED
			_delay_ms(100);
		}
		
    }
}

