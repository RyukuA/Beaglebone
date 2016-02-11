/*
 * Gpio.cpp
 *
 *  Created on: 21 Dec 2015
 *      Author: pi
 */

#include "Gpio.hpp"

Gpio::Gpio() {
	// TODO Auto-generated constructor stub
	gpio = "";
	directory = "";
	value = "";
	direction = "";

}

Gpio::~Gpio() {
	// TODO Auto-generated destructor stub
	unexport();
}

char* Gpio::GetDirection() {
	return "";
}

char* Gpio::GetGpio() {
	return "";
}

char* Gpio::GetValue() {
	return "";
}

void Gpio::SetDirection() {

}

void Gpio::SetGpio() {

}

void Gpio::SetValue() {

}

void Gpio::exportV() {

}

void Gpio::unexport() {

}

