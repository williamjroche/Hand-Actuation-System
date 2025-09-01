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
	DDRB |= (1 << PORTB3); //set data direction of PWM to output of timer 2 to PB3/D11 ------> servo 3
	DDRD |= (1 << PORTD3); //set data direction of PWM to output of timer 2 to PD3/D3 -------> servo 4
	
	TCCR2A |= (1 << WGM21) | (1 << WGM20); //mode 3 -> fast PWM with Top = 0xFF or 255 (timer 2 is 8 bit)
	
	//COM2A1 for OC2A, which PB3 is connected | COM2B1 for OC2B which PD3 is connected
	TCCR2A |= (1 << COM2A1) | (1 << COM2B1); //non-inverting
	TCCR2B |= (1 << CS22) | (1 << CS21); //prescaler of 256 --> 16MHz/(256*256) = 244Hz freq
}

void servo5_6_setup(void){
//This function sets up for servo 5 and servo 6 using Timer 0
	DDRD |= (1 << PORTD6) | (1 << PORTD5); //set data direction of PWM to output of timer 0 to PD6/D6 -> servo 5 | PD5/D5 -> servo 6
	
	TCCR0A |= (1 << WGM01) | (1 << WGM00); //mode 3 -> fast PWM with Top = 0xFF or 255 (timer 0 is 8 bit)
	
	//COM0A1 for OC0A, which PD6 is connected | COM0B1 for OC0B, which PD5 is connected
	TCCR0A |= (1 << COM0A1) | (1 << COM0B1);//non-inverting
	TCCR0B |= (1 << CS02); //prescaler of 256 --> 16MHz/(256*256) = 244Hz freq
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

int main(void){
	servo1_2_setup();
	servo3_4_setup();
	servo5_6_setup();
	
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