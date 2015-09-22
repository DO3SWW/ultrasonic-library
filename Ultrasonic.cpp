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


#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif


#include "Ultrasonic.h"


Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin) {
	this->_TrigPin = trigPin;
	this->_EchoPin = echoPin;
	pinMode(_TrigPin, OUTPUT);
	pinMode(_EchoPin, INPUT);
}

float Ultrasonic::getDistanceInInch() {
	return Ultrasonic::readDuration() / Sound_per_second_INCH /2;
}


float Ultrasonic::getDistanceInCM() {
	return Ultrasonic::readDuration() / Sound_per_second_CM / 2;
}


float Ultrasonic::readDuration() {
	digitalWrite(_TrigPin, LOW);
	delayMicroseconds(2);
	digitalWrite(_TrigPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(_TrigPin, LOW);
	float pulse = pulseIn(_EchoPin, HIGH);
	return pulse;
}
