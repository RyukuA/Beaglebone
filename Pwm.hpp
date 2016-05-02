/*
 * Pwm.hpp
 *
 *  Created on: 21 Dec 2015
 *      Author: pi
 */

#ifndef RASPBERRY_PWM_HPP_
#define RASPBERRY_PWM_HPP_

class Pwm {
public:
	Pwm();
	virtual ~Pwm();
	int SetDuty(unsigned int PWMPin, char* duty, unsigned int PWMSecond, unsigned int Pval);
	int SetPeriod(unsigned int pin, char* period, unsigned int second, unsigned int pval);

};

#endif /* RASPBERRY_PWM_HPP_ */
