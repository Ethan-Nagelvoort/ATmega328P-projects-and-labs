	/*
 * LAB5.c
 *
 * Created: 3/8/2020 9:09:20 PM
 * Author : Ethan
 */ 


#define F_CPU 16000000
#include <avr/io.h>
#include <util/delay.h>
#define LEDON PORTB|=(1<<5)
#define LEDOFF PORTB&=~(1<<5)

#define BAUD 9600


#define MYUBBR ((F_CPU)/(BAUD * 16UL) - 1) //Use UBBR for USART baud rate

void init_uart() {
	UBRR0H = (MYUBBR >> 8); //set UBBR high
	UBRR0L = (MYUBBR); //set UBBR low
	 UCSR0B |= (1 << TXEN0) | (1 << RXEN0) | (1 << RXCIE0) | (1 << TXCIE0); 
}

void delay_time(int a)//function that lets us use any amount of delay
{
	int count =0;
	while(count < a)
	{
		_delay_us(1);
		count++;
	}
}


int main(void)
{
	init_uart();
    DDRB |= (1<<5);//set LED pin as output
	DDRB &=~ (1<<7);//set button pin to input
	PORTB |= (1<<7);//set b7 as pullup
	TCCR0A |=  (1<<WGM01) | (1<<COM0A1) | (1<<COM0B1); // set timer to CTC mode through (1<<WGM01), use (1<<COM0A1) to clear OCOA, use(1<<COM0B1) to clear OCOB
	LEDOFF;
	OCR0A = 0x9B; // represents 10ms timer/ number we want timer to count to which is 155
	OCR0B = 0x00; // represents 0% duty cycle
	TCCR0B |= (1<<CS02) | (1<<CS00); // set timer to 1024 prescaler and start timer
    while (1) 
    {
		while((PINB&(1<<7))==0)//if button is pressed
		{
			while(OCR0B<0x9B)//if statment instead of while, so if button isn't pressed loop will end
			{
				LEDON;
				while((TIFR0 & (1<<OCF0B))==0){};//wait for overflow event of OCF0B
					TIFR0 |= (1 << OCF0B); // reset overflow flag of OCF0B
				LEDOFF;
				while((TIFR0 & (1<<OCF0A))==0){};//wait for overflow event of OCF0A
					TIFR0 |= (1 << OCF0A); // reset overflow flag of OCF0A
				OCR0B++; // increment OCR0B
			}
			LEDON;//once at full brightness, leave LED on
				}
		while(OCR0B>0)//while loop that decreases brightness
		{
			OCR0B--;//decrement OCR0B
			LEDON;
			while((TIFR0 & (1<<OCF0B))==0){};//wait for overflow event of OCF0B
				TIFR0 |= (1 << OCF0B); // reset overflow flag of OCF0B
			LEDOFF;
			while((TIFR0 & (1<<OCF0A))==0){};//wait for overflow event of OCF0A
				TIFR0 |= (1 << OCF0A); // reset overflow flag of OCF0A
			}
			LEDOFF;//once at lowest brightness, leave LED off
			
		
		
		//checkpoint code below
		/*int count = 0;
	    while((PINB&(1<<7))==0)//if button is pressed
		{
			if(count<1000)//if count is less than a second
			{             //our period is one second which is 1000 ms 
				count++;//increment to increase brightness
				LEDON;
				delay_time(count);
				LEDOFF;
				delay_time(1000-count);//brightness is controlled by duty cycle
			}
			else//if greater than period then LED is left on at full brightness
			{
				LEDON;
			}
		}
		
		while(count>0)
		{
			count--;//decrement count so brightness will go down
			LEDOFF;
			delay_time(1000-count);
			LEDON;
			delay_time(count);
		}
		LEDOFF;//after While statement, LED stays off*/
		
		
    }
return(0); 
}

