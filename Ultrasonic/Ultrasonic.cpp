/*
Ultrasonic-Library: Simple to use Arduino Library for the Ultrasonic HC-SR04 Module.
Github: https://github.com/DO3SWW/ultrasonic-library

#### LICENSE ####
Ultrasonic Arduino Library 
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
   _timeOut = 5800; // 5800 µs ≈ 100 cm at 22 °C
}


Ultrasonic::Ultrasonic(uint8_t trigPin, uint8_t echoPin, long timeOut) {
   this->_TrigPin = trigPin;
   this->_EchoPin = echoPin;
   this->_timeOut = timeOut;
   pinMode(_TrigPin, OUTPUT);
   pinMode(_EchoPin, INPUT);
}


long Ultrasonic::getDistanceInInch(long temperature) {   
   long speedPerMicorsecondCM = Ultrasonic::speedOfSound(temperature);
   return Ultrasonic::readDuration() / (speedPerMicorsecondCM * 2.54) /2;
}


long Ultrasonic::getDistanceInCM(long temperature) {
   long speedPerMicorsecondCM = Ultrasonic::speedOfSound(temperature);
   return Ultrasonic::readDuration() / speedPerMicorsecondCM / 2;
}


long Ultrasonic::speedOfSound(long temperature){
   long ultrasonicspeed = SPEED_OF_SOUND_BASE + (SPEED_OF_SOUND_FACTOR * temperature);
   return 10000 / ultrasonicspeed;
}


long Ultrasonic::readDuration() {
   digitalWrite(_TrigPin, LOW);
   delayMicroseconds(2);
   digitalWrite(_TrigPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(_TrigPin, LOW);
   long duration = pulseIn(_EchoPin, HIGH, _timeOut);
   if( duration == 0){
      duration = _timeOut;
   }
   return duration;
}
