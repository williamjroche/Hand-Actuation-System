#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>
//custom header files
#include "servo.h"
#include "servo_position.h"

int main(void){
	servo_setup();
	
	while(1){
		DDRB |= (1 << PORTB4) | (1 << PORTB5);
		PORTC |= 0x01;
		for(int counter = 0; counter <= 6400 ; counter++){
			PORTC != PORTC;
			_delay_ms(1);
		}
		move_servo(1, 10, 500, 2500, true);//start servo1 at -90 deg, move to 90 deg
		move_servo(2, 10, 2500, 500, false);//start servo2 at 90 deg, move to -90 deg
		move_servo(3, 9, 500, 2500, true);//start servo3 at -90 deg, move to 90 deg
		move_servo(4, 9, 2500, 500, false);//start servo4 at 90 deg, move to -90 deg
		move_servo(5, 9, 500, 2500, true);//start servo5 at -90 deg, move to 90 deg
		move_servo(6, 9, 2500, 500, false);//start servo6 at 90 deg, move to -90 deg
		move_servo(1, 10, 2500, 500, false);//start servo1 at 90 deg, move to -90 deg
		move_servo(2, 10, 500, 2500, true);//start servo2 at -90 deg, move to 90 deg
		move_servo(3, 9, 2500, 500, false);//start servo3 at 90 deg, move to -90 deg
		move_servo(4, 9, 500, 2500, true);//start servo4 at -90 deg, move to 90 deg
		move_servo(5, 9, 2500, 500, false);//start servo5 at 90 deg, move to -90 deg
		move_servo(6, 9, 500, 2500, true);//start servo6 at -90 deg, move to 90 deg
	}
	
	return 0;
}


