/*
 * Gpio.hpp
 *
 *  Created on: 21 Dec 2015
 *      Author: pi
 */

#ifndef RASPBERRY_GPIO_HPP_
#define RASPBERRY_GPIO_HPP_

class Gpio {
public:
	Gpio();
	virtual ~Gpio();

	char* GetDirection();
	void SetDirection();

	char* GetGpio();
	void SetGpio();

	char* GetValue();
	void SetValue();

	void exportV();
	void unexport();

private:
	char* gpio;
	char* directory;
	char* direction;
	char* value;
};

#endif /* RASPBERRY_GPIO_HPP_ */
