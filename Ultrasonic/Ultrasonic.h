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


#ifndef Ultrasonic_h
#define Ultrasonic_h


#if ARDUINO >= 100
   #include "Arduino.h"
#else
   #include "WProgram.h"
#endif


#define SPEED_OF_SOUND_BASE 331.5
#define SPEED_OF_SOUND_FACTOR 0.6


class Ultrasonic {

   public:
      Ultrasonic(uint8_t trigPin, uint8_t echoPin);
      Ultrasonic(uint8_t trigPin, uint8_t echoPin, long timeOut);
      long getDistanceInInch(long temperature = 22);
      long getDistanceInCM(long temperature = 22);

   private:
      uint8_t _TrigPin;
      uint8_t _EchoPin;
      long _timeOut;
      long readDuration();
      long speedOfSound(long temperature);
		
};

#endif
