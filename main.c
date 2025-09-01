#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "servo.h"

void servo1_position();
void servo2_position();
void servo3_position();
void servo4_position();
void servo5_position();
void servo6_position();

int main(void){
	servo_setup();
	
	while(1){
		//start servo1 at -90 deg, move to 90 deg
		for(int pulse = 500; pulse <= 2500; pulse += 10){
			servo1_position(pulse);
			_delay_ms(10);
		}
		//start servo2 at 90 deg, move to -90 deg
		for(int pulse = 2500; pulse >= 500; pulse -= 10){
			servo2_position(pulse);
			_delay_ms(10);
		}
		//start servo3 at -90 deg, move to 90 deg
		for(int pulse = 500; pulse <= 2500; pulse += 10){
			servo3_position(pulse);
			_delay_ms(9);
		}
		//start servo4 at 90 deg, move to -90 deg
		for(int pulse = 2500; pulse >= 500; pulse -= 10){
			servo4_position(pulse);
			_delay_ms(9);
		}
		//start servo5 at -90 deg, move to 90 deg
		for(int pulse = 500; pulse <= 2500; pulse += 10){
			servo5_position(pulse);
			_delay_ms(9);
		}
		//start servo6 at 90 deg, move to -90 deg
		for(int pulse = 2500; pulse >= 500; pulse -= 10){
			servo6_position(pulse);
			_delay_ms(9);
		}
		//start servo1 at 90 deg, move to -90 deg
		for(int pulse = 2500; pulse >= 500; pulse -= 10){
			servo1_position(pulse);
			_delay_ms(10);
		}
		//start servo2 at -90 deg, move to 90 deg
		for(int pulse = 500; pulse <= 2500; pulse += 10){
			servo2_position(pulse);
			_delay_ms(10);
		}
		//start servo3 at 90 deg, move to -90 deg
		for(int pulse = 2500; pulse >= 500; pulse -= 10){
			servo3_position(pulse);
			_delay_ms(9);
		}
		//start servo4 at -90 deg, move to 90 deg
		for(int pulse = 500; pulse <= 2500; pulse += 10){
			servo4_position(pulse);
			_delay_ms(9);
		}
		//start servo5 at 90 deg, move to -90 deg
		for(int pulse = 2500; pulse >= 500; pulse -= 10){
			servo5_position(pulse);
			_delay_ms(9);
		}
		//start servo6 at -90 deg, move to 90 deg
		for(int pulse = 500; pulse <= 2500; pulse += 10){
			servo6_position(pulse);
			_delay_ms(9);
		}
	}
	
	return 0;
}

void servo1_position(int pulse_width){
	//OCR1A because we need output control on PB1
	OCR1A = pulse_width * 2; // pulse width is in micro seconds
}

void servo2_position(int pulse_width){
	//OCR1B because we need output control on PB2
	OCR1B = pulse_width * 2; // pulse width is in micro seconds
}

void servo3_position(int pulse_width){
	OCR2A = pulse_width/16; // each tick is 16 microseconds
}

void servo4_position(int pulse_width){
	OCR2B = pulse_width/16; // each tick is 16 microseconds
}

void servo5_position(int pulse_width){
	OCR0A = pulse_width/16; // each tick is 16 microseconds
}

void servo6_position(int pulse_width){
	OCR0B = pulse_width/16; // each tick is 16 microseconds
}
