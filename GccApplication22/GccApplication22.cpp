#include <avr/io.h>
#include <util/delay.h>

void Pause(int ms)
{
	PORTB = 0xFF;
	_delay_loop_2 (ms);
}

void P(void)
{
	PORTB = 0;
	_delay_loop_2 (50);
	Pause(50);
}

void D(void)
{
	PORTB = 0;
	_delay_loop_2 (200);
	Pause(50);
}

int main(void)
{
	DDRB = 0xFF;
	while(1)
	{
		P(); P(); P(); //...
		D(); D(); D(); //---
		P(); P(); P(); //...
		Pause(1000);
	}
}