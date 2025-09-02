#ifndef servo_position_h
#define servo_position_h

void move_servo(int servo_number, int delay, int pulse, int pulse_end, bool to_pos){
	if(to_pos == true){
		for(pulse; pulse <= pulse_end; pulse+=10){
			switch(servo_number){
				case 1:
					//OCR1A because we need output control on PB1
					OCR1A = pulse * 2; // pulse width is in micro seconds
					break;
				case 2:
					//OCR1B because we need output control on PB2
					OCR1B = pulse * 2; // pulse width is in micro seconds
					break;
				case 3:
					OCR2A = pulse / 16; // each tick is 16 microseconds
					break;
				case 4:
					OCR2B = pulse / 16; // each tick is 16 microseconds
					break;
				case 5:
					OCR0A = pulse / 16; // each tick is 16 microseconds
					break;
				case 6:
					OCR0B = pulse / 16; // each tick is 16 microseconds
					break;
			}
			_delay_ms(delay);
		}
	}
	else{
		for(pulse; pulse >= pulse_end; pulse-=10){
			switch(servo_number){
				case 1:
				//OCR1A because we need output control on PB1
				OCR1A = pulse * 2; // pulse width is in micro seconds
				break;
				case 2:
				//OCR1B because we need output control on PB2
				OCR1B = pulse * 2; // pulse width is in micro seconds
				break;
				case 3:
				OCR2A = pulse / 16; // each tick is 16 microseconds
				break;
				case 4:
				OCR2B = pulse / 16; // each tick is 16 microseconds
				break;
				case 5:
				OCR0A = pulse / 16; // each tick is 16 microseconds
				break;
				case 6:
				OCR0B = pulse / 16; // each tick is 16 microseconds
				break;
			}
			_delay_ms(delay);
		}
	}
}

#endif