/*
 * Lab3a.c
 *
 * Created: 2/17/2020 1:27:45 PM
 * Author : Ethan
 */ 
#define F_CPU 16000000// Clock Speed
#define BAUD 9600
#define MYUBRR ((F_CPU)/(BAUD * 16UL) - 1)
#include <avr/io.h>
#include <util/delay.h> 

void USART_Init()
{
 /*Set baud rate */
 UBRR0H = (MYUBRR>>8);
 UBRR0L = MYUBRR;
 UCSR0B = (1<<TXEN0); //enable transmitter
 UCSR0C = (0<<USBS0)|(1<<UCSZ00)| (1<<UCSZ01);// 8-bit 1-stop
}

int main()
{
    USART_Init();
    int i = 0;
    unsigned char data[] = "821234668 \n";
    
    while(1) 
    {
        i = 0; 
        while(data[i] != 0) 
        {
            while (!( UCSR0A & (1<<UDRE0)));
            UDR0 = data[i]; 
			
            //_delay_ms(600); 
            i++; 
        }
    }
}

