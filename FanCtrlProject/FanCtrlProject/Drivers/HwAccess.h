/*
 * HwAccess.h
 *
 * Created: 3/25/2020 2:00:55 AM
 *  Author: Mahmo
 */ 


#ifndef HWACCESS_H_
#define HWACCESS_H_
#include <stdint.h>
#define TRUE (1U)
#define FALSE (0U)
//#define HwWritePort(X,V)	(*((volatile uint8_t*)(X)) = V)

static inline void HwWriteReg(uint8_t Reg, uint8_t Val){
	(*(volatile uint8_t*)Reg) = Val;
}

static inline void HwWriteRegOring(uint8_t Reg, uint8_t Val){
	(*(volatile uint8_t*)Reg) |= Val;
}

static inline uint8_t HwReadReg(uint8_t Reg){
	return (*(volatile uint8_t*)Reg);
}

static inline void HwSetRegBit(uint8_t Reg, uint8_t Bit){
	(*(volatile uint8_t*)Reg) |= (1<<Bit);
}

static inline void HwClrRegBit(uint8_t Reg, uint8_t Bit){
	(*(volatile uint8_t*)Reg) &= ~(1<<Bit);
}

static inline uint8_t HwReadBit(uint8_t Reg, uint8_t Bit){
	return (*(volatile uint8_t*)Reg) & (1<<Bit);
}

static inline uint8_t HwIsBitSet(uint8_t Reg, uint8_t Bit){
	if(((*(volatile uint8_t*)Reg) & (1<<Bit)) != 0U){
		return TRUE;
	}else{
		return FALSE;
	}
}

#endif /* HWACCESS_H_ */