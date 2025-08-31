#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

void servo_setup(void){
	DDRB |= (1 << DDB1); //PWM output pin PB1/D9
	
	//select Fast PWM mode 14
	TCCR1B |= (1 << WGM13) | (1 << WGM12); //upper waveform generation bits
	TCCR1A |= (1 << WGM11); //lower waveform generation bits
	
	ICR1 = 39999; //top value
	
	TCCR1A |= (1 << COM1A1); //non inverting mode
	TCCR1B |= (1 << CS11); //prescaler of 8 --> 16MHz/8 = 2MHz clock
}

void servo_position(int pulse_width){
	OCR1A = pulse_width * 2; // pulse width is in micro seconds 
}

int main(void){
	servo_setup();
	
	while(1){
		//start servo at -90 deg, move to 90 deg
		for(int pulse = 500; pulse <= 2500; pulse += 10){
			servo_position(pulse);
			_delay_ms(10);
		}
		//start servo at 90 deg, move to -90 deg
		for(int pulse = 2500; pulse >= 500; pulse -= 10){
			servo_position(pulse);
			_delay_ms(10);
		}
	}
	
	return 0;
}