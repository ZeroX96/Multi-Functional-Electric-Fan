/*
 * Gpio.c
 *
 * Created: 3/20/2020 5:38:06 AM
 *  Author: Mahmo
 */ 
#include "Gpio.h"

//Gpio APIs
GpioRetT GpioInitPort(GpioBaseT Base,GpioStateT State){
	if ((Base >= BASE_D) && (Base <= BASE_A)){
		//*((volatile uint8_t*)(Base+DDRx_OFFSET)) = State;
		HwWriteReg(Base + DDRx_OFFSET, State);
#ifdef INTERNAL_PULL_UP_EN
		if (PORT_IN == State){
			//*((volatile uint8_t*)Base+PORTx_OFFSET) = 0xff;	//enable the internal pull-up
			HwWriteReg(Base + PORTx_OFFSET, 0xff);
		}
#endif //INTERNAL_PULL_UP_EN
		return GPIO_ERR_NO;
	} 
	else{
		return GPIO_ERR_INV_PARAMS;
	}
}

GpioRetT GpioInitPin(GpioBaseT Base,GpioPinT Pin,GpioStateT State){
	if ((Base >= BASE_D) && (Base <= BASE_A)){
		if(PIN_IN == State){
			//*((volatile uint8_t*)(Base+DDRx_OFFSET)) &= ~(1<<Pin);
			HwClrRegBit(Base+DDRx_OFFSET, Pin);
			//*((volatile uint8_t*)(Base+PORTx_OFFSET)) |= (1<<Pin);	//enable the internal pull-up
#ifdef INTERNAL_PULL_UP_EN
			HwSetRegBit(Base+PORTx_OFFSET, Pin);
#endif //INTERNAL_PULL_UP_EN
		}
		else if(PIN_OUT == State){
			//*((volatile uint8_t*)(Base+DDRx_OFFSET)) |= (1<<Pin);
			HwSetRegBit(Base+DDRx_OFFSET, Pin);
		}
		return GPIO_ERR_NO;
	}
	else{
		return GPIO_ERR_INV_PARAMS;
	}
}
GpioRetT GpioWritePort(GpioBaseT Base,uint8_t Val){
	if ((Base >= BASE_D) && (Base <= BASE_A)){
		//*((volatile uint8_t*)(Base+PORTx_OFFSET)) = Val;
		HwWriteReg(Base+PORTx_OFFSET, Val);
		return GPIO_ERR_NO;
	}
	else{
		return GPIO_ERR_INV_PARAMS;
	}
}
GpioRetT GpioWritePin(GpioBaseT Base,GpioPinT Pin,GpioStateT State){
	if ((Base >= BASE_D) && (Base <= BASE_A)){
		if(PIN_LOW == State){
			//*((volatile uint8_t*)(Base+PORTx_OFFSET)) &= ~(1<<Pin);
			HwClrRegBit(Base+PORTx_OFFSET, Pin);
		}
		else if(PIN_HIGH == State){
			//*((volatile uint8_t*)(Base+PORTx_OFFSET)) |= (1<<Pin); //error fixed :D !!??
			HwSetRegBit(Base+PORTx_OFFSET, Pin);
		}
		else{
			return GPIO_ERR_INV_PARAMS;
		}
		return GPIO_ERR_NO;
	}
	else{
		return GPIO_ERR_INV_PARAMS;
	}
}
//required you confirm the correctness of the parameter
uint8_t  GpioReadPort(GpioBaseT Base){
	//return(*((volatile uint8_t*)Base));
	return (HwReadReg(Base));
}
uint8_t  GpioReadPin(GpioBaseT Base,GpioPinT Pin){
	//if ( (*((volatile uint8_t*)Base)) & (1<<Pin)){
	if(HwReadBit(Base, Pin)){
		return PIN_HIGH;
	}else{
		return PIN_LOW;
	}
}