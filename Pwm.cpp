/*
 * Pwm.cpp
 *
 *  Created on: 21 Dec 2015
 *      Author: pi
 */

#include "Pwm.hpp"
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;
#define MAX 64

Pwm::Pwm() {
	// TODO Auto-generated constructor stub

}

Pwm::~Pwm() {
	// TODO Auto-generated destructor stub
}

int Pwm::SetDuty(unsigned int PWMPin, double duty, unsigned int PWMSecond, unsigned int Pval) {
	//FILE* FileHandle = NULL;
	char setValue[7], PWMValue[MAX];
	sprintf(PWMValue, "/sys/devices/ocp.3/pwm_test_P%d_%d.%d/duty", Pval, PWMPin, PWMSecond);
	ofstream FileHandle(PWMValue);
	if(FileHandle.is_open()) {
		FileHandle << duty;
		FileHandle.close();
	}
	/*
	if((FileHandle = fopen(PWMValue, "rb+")) == NULL) {
		cout << "Cannot open duty handle" << endl;
		return 1;
	}
	strcpy(setValue, duty);
	fwrite(&setValue, sizeof(char), 7, FileHandle);
	fclose(FileHandle);
	*/
	return 0;
}
int Pwm::SetPeriod(unsigned int pin, char* period, unsigned second, unsigned int pval) {
	//FILE* FileHandle = NULL;
	char setValue[8], PWMValue[MAX];
	sprintf(PWMValue, "/sys/devices/ocp.3/pwm_test_P%d_%d.%d/period", pval, pin, second);
	ofstream FileHandle(PWMValue);
	if(FileHandle.is_open()) {
		FileHandle << period;
		FileHandle.close();
	}
	/*
	if((FileHandle = fopen(PWMValue, "rb+")) == NULL) {
		cout << "Cannot open duty handle" << endl;
		return 1;
	} */
	cout << "Got past opening the file" << endl; 
	//strcpy(setValue, period);
	//fwrite(&setValue, sizeof(char), 8, FileHandle);
	//fclose(FileHandle);
	return 0;
}

