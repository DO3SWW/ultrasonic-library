/*
Simple to use Arduino Libary to use with the Ultrasonic HC-SR04 Modul.

#### LICENSE ####
Ultrasonic-Arduino-Library 
Copyright (C) 2015  Simon Weber

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#ifndef Ultrasonic_h
#define Ultrasonic_h


#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#define Sound_per_second_CM 29.1
#define Sound_per_second_INCH 74


class Ultrasonic {
	
	public:
		Ultrasonic(uint8_t trigPin, uint8_t echoPin);
		float getDistanceInInch();
		float getDistanceInCM();

	private:
		uint8_t _TrigPin;
		uint8_t _EchoPin;
		float readDuration();
		
};

#endif
