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

#include <Ultrasonic.h>

Ultrasonic ultrasonic(9, 8);   // Trig PIN, Echo Pin

void setup() {
   Serial.begin(9600);   // initialize serial communication:
}

void loop() {
   Serial.print(ultrasonic.getDistanceInCM(40));   // Ouptut in cm at 40°C
   Serial.println(" cm" );
   delay(500);
   Serial.print(ultrasonic.getDistanceInInch(40));   // Output in inch at 40°C
   Serial.println(" inch" );
   delay (500);  
}

