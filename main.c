#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void servo1_2_setup(void){ 
//This function sets up for servo 1 and servo 2 using Timer 1
	DDRB |= (1 << PORTB1) | (1 << PORTB2); //set data direction of PWM to output pin PB1/D9 (servo1) and PWM output pin PB2/D10 (servo2)
	
	//select Fast PWM mode 14
	TCCR1B |= (1 << WGM13) | (1 << WGM12); //upper waveform generation bits
	TCCR1A |= (1 << WGM11); //lower waveform generation bits
	
	ICR1 = 39999; //top value
	
	//COM1A1 for OC1A, which PB1 is connected | COM1B1 for OC1B, which PB2 is connected
	TCCR1A |= (1 << COM1A1) | (1 << COM1B1); //non inverting mode
	TCCR1B |= (1 << CS11); //prescaler of 8 --> 16MHz/8 = 2MHz clock (2MHz / 39999 = 50Hz)
}

void servo3_4_setup(void){
//This function sets up for servo 3 and servo 4 using Timer 2
	DDRB |= (1 << PORTB3); //set data direction of PWM to output of timer 2 to PB3/D11
	
	TCCR2A |= (1 << WGM21) | (1 << WGM20); //mode 3 -> fast PWM with Top = 0xFF or 255 (timer 2 is 8 bit)
	
	//COM2A1 for OC2A, which PB3 is connected
	TCCR2A |= (1 << COM2A1); //non-inverting
	TCCR2B |= (1 << CS22) | (1 << CS21); //prescaler of 256 --> 16MHz/(256*256) = 244Hz freq
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
int main(void){
	servo1_2_setup();
	servo3_4_setup();
	
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
	}
	
	return 0;
}