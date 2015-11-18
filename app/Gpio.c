#include "Gpio.h"
#include "stm32f4xx_hal_rcc.h"

void configurePinAsInput(int pinNum, GPIO *port, int pullMode)
{
	gpioUnresetEnableClock(port);
	port->PUPDR &= ~(3 << (pinNum * 2));
	port->PUPDR |= (pullMode << (pinNum * 2));
}

void configurePin(int mode, int pinNum, GPIO *port)
{
//	GPIO_InitTypeDef GpioInfo;

	gpioUnresetEnableClock(port);

	//((gpio *)GPIOG_BASE_ADDRESS)
	port->MODER &= ~(3 << (pinNum * 2));
	port->MODER |= (mode << (pinNum * 2));
	port->OTYPER &= ~(1 << pinNum);
	port->OSPEED &= ~(3 << (pinNum * 2));
	port->OSPEED |= (GPIO_HIGH_SPEED << (pinNum * 2));

//	HAL_GPIO_Init(port, &GpioInfo);

}

void writeOne(uint16_t pinNum, GPIO *port)
{
	port->BSRR |= 1 << pinNum;
}

void writeZero(uint16_t pinNum, GPIO *port)
{
	port->BSRR |= 1 << (pinNum + 16);
}


void readPin(uint16_t readPinNumber, GPIO *readPort, uint16_t writePin, GPIO *writePort)
{
	int signal = readPort->IDR & (1 << readPinNumber);
	if(signal)
		writeOne(writePin, writePort);
	else
		writeZero(writePin, writePort);
}


