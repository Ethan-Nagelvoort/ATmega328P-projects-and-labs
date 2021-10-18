/*
 * Lab2.c
 *
 * Created: 2/10/2020 2:06:47 PM
 * Author : Ethan
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void dash (void)
{
	PORTB|= (1<<PORTB5);// turn on pin B5
	_delay_ms(600);// delay 600ms
	PORTB &=~ (1<<PORTB5);//turn off pin B5
}

void dot (void)
{
	PORTB|= (1<<PORTB5);//turn on pin B5
	_delay_ms(200);//delay 200ms
	PORTB &=~ (1<<PORTB5);//turn off pin B5
}

void wordSpace (void)
{
	_delay_ms(1400);//delay 1400ms
}

void letterSpace (void)
{
	_delay_ms(600);//delay 600ms
}

void dotDashSpace (void)
{
	_delay_ms(200);//delay 200ms
}

int main(void)
{
	DDRB |= (1<<DDB5);
    /* Replace with your application code */
	unsigned char nameREDID[] = "Ethan Nagelvoort 821234668";
	while(1)
	{
		int i =0;
   while(nameREDID[i] != '\0') {
	   switch(nameREDID[i])
	   {
		   case 'a':
		   dot(); dotDashSpace(); dash();letterSpace();
		   break;
		   
		   case 'A':
		   dot(); dotDashSpace(); dash();letterSpace();
		   break;
		   
		   case 'b':
		   dash();dotDashSpace();dot();dotDashSpace();dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'B':
		   dash();dotDashSpace();dot();dotDashSpace();dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'c':
		   dash();dotDashSpace();dot();dotDashSpace();dash();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'C':
		   dash();dotDashSpace();dot();dotDashSpace();dash();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'd':
		   dash();dotDashSpace();dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'D':
		   dash();dotDashSpace();dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'e':
		   dot();letterSpace();
		   break;
		   
		    case 'E':
		    dot();letterSpace();
		    break;
		   
		   case 'f':
		   dot();dotDashSpace();dot();dotDashSpace();dash();dot();letterSpace();
		   break;
		   
		    case 'F':
		    dot();dotDashSpace();dot();dotDashSpace();dash();dot();letterSpace();
		    break;
		   
		   case 'g':
		   dash();dotDashSpace();dash();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'G':
		   dash();dotDashSpace();dash();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'h':
		   dot();dotDashSpace();dot();dotDashSpace();dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'H':
		   dot();dotDashSpace();dot();dotDashSpace();dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'i':
		   dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'I':
		   dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'j':
		   dot();dotDashSpace(); dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		    case 'J':
		    dot();dotDashSpace(); dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); letterSpace();
		    break;
		   
		   case 'k':
		   dash(); dotDashSpace(); dot(); dotDashSpace();dash(); letterSpace();
		   break;
		   
		   case 'K':
		   dash(); dotDashSpace(); dot(); dotDashSpace();dash(); letterSpace();
		   break;
		   
		   case 'l':
		   dot();dotDashSpace();dash();dotDashSpace();dot();dotDashSpace();dot();letterSpace();
		   break;
		   
		    case 'L':
		    dot();dotDashSpace();dash();dotDashSpace();dot();dotDashSpace();dot();letterSpace();
		    break;
		   
		   case 'm':
		   dash(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'M':
		   dash(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'n':
		   dash(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case 'N':
		   dash(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case 'o':
		   dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		    case 'O':
		    dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); letterSpace();
		    break;
		   
		   case 'p':
		   dot();dotDashSpace();dash();dotDashSpace();dash();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'P':
		   dot();dotDashSpace();dash();dotDashSpace();dash();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'q':
		   dash();dotDashSpace();dash();dotDashSpace();dot();dotDashSpace();dash();letterSpace();
		   break;
		   
		    case 'Q':
		    dash();dotDashSpace();dash();dotDashSpace();dot();dotDashSpace();dash();letterSpace();
		    break;
		   
		   case 'r':
		   dot(); dotDashSpace(); dash();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case 'R':
		   dot(); dotDashSpace(); dash();dotDashSpace();dot();letterSpace();
		   break;
		   
		   case'S':
		   dot();  dotDashSpace(); dot(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case's':
		   dot();  dotDashSpace(); dot(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case 't':
		   dash();letterSpace();
		   break;
		   
		    case 'T':
		    dash();letterSpace();
		    break;
			
		   case 'U':
		   dot(); dotDashSpace(); dot(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'u':
		   dot(); dotDashSpace(); dot(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'V':
		   dot();dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'v':
		   dot();dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'W':
		   dot(); dotDashSpace(); dash();dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'w':
		   dot(); dotDashSpace(); dash();dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'X':
		   dash(); dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'x':
		   dash(); dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'Y':
		   dash(); dotDashSpace(); dot(); dotDashSpace(); dash(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'y':
		   dash(); dotDashSpace(); dot(); dotDashSpace(); dash(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case 'Z':
		   dash(); dotDashSpace(); dash(); dotDashSpace(); dot(); dotDashSpace(); dot(); letterSpace();
		   break; 
		   
		   case 'z':
		   dash(); dotDashSpace(); dash(); dotDashSpace(); dot(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case '1':
		   dot();dotDashSpace(); dash();dotDashSpace(); dash();dotDashSpace(); dash();dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case '2':
		   dot();dotDashSpace(); dot();dotDashSpace(); dash();dotDashSpace(); dash();dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case '3':
		   dot();dotDashSpace(); dot(); dotDashSpace();  dot(); dotDashSpace(); dash(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case '4':
		   dot();dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace();  dot(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case'5':
		   dot(); dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case '6':
		   dash(); dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace(); dot(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case '7':
		   dash();dotDashSpace(); dash(); dotDashSpace(); dot();dotDashSpace(); dot(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case '8':
		   dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); dotDashSpace(); dot(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case '9':
		   dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); dotDashSpace(); dot(); letterSpace();
		   break;
		   
		   case '0':
		   dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); dotDashSpace(); dash(); letterSpace();
		   break;
		   
		   case ' ':
		   wordSpace();
		   break;
		   
		   default:
		   break;
	   }
	   
	   i++;
   }
	}
}

