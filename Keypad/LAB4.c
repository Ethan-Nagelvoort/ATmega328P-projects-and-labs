	/*
 * LAB4.c
 *
 * Created: 2/24/2020 2:28:49 PM
 * Author : Ethan
 */ 
#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>

#define BAUD 9600


#define MYUBBR ((F_CPU)/(BAUD * 16UL) - 1) //Use UBBR for USART baud rate

void init_uart() {
	UBRR0H = (MYUBBR >> 8); //set UBBR high
	UBRR0L = (MYUBBR); //set UBBR low
	//UCSR0C = (1 << UCSZ00) | (1 << UCSZ01) | (0 << USBS0); // 8-bit 1-stop bit mode
	UCSR0B = (1 << TXEN0); //enable transmitter
}

int main(void)
{
    init_uart();
	DDRB &=~ (1<<0)&~(1<<1)&~(1<<2)&~(1<<3);//inputs
	
	DDRD	|=	(1<<4|1<<5|1<<6|1<<7);//output
	PORTD	|=	(1<<4)|(1<<5)|(1<<6)|(1<<7);//set to high
	PORTB  |= (1<<0) | (1<<1) | (1<<2) |(1<<3);//pullups
	DDRB |=(1<<5);//B5 is output
    while (1) 
    {
		char key[4][4] = {{'1', '2' , '3' , 'A' }, {'4' ,'5' ,'6' ,'B'}, {'7', '8' ,'9' ,'C'}, {'*' ,'0' , '#' ,'D'}};//keypad characters
		PORTD	|=	(1<<4)|(1<<5)|(1<<6)|(1<<7);//set to high
		for(int i=4;i<8;i++)
		{
			PORTD &= ~(1<<i);//set to 0
		    for(int j=0; j<4; j++)
			{
				if(!(PINB&(1<<j)))
				{
					
					 while(!( UCSR0A & (1<<UDRE0)));
					 UDR0 = key[i-4][j];//returns the key
					 _delay_ms(200); //so only one character is printed at a time
					 

					/*PORTB|=(1<<5);//turn LED on
					_delay_ms(1000);
					PORTB &=~ (1<<5);//turn off led*/
				}	
			}	
			
			PORTD |= (1<<i);//set back to 1
		}
		
    }
}
