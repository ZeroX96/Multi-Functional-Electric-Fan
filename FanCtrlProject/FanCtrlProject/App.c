/*
 * FanCtrlProject.c
 *
 * Created: 3/20/2020 12:53:04 AM
 * Author : Mahmo
 */ 
#include "App.h"

extern _Bool SysAutoOffSt;

extern int16_t DispBDelay;
extern int8_t BuzzDelay;

int main(void){
	
	systemInit();
	
	while (1){
		
		if (SysAutoOffSt != TRUE){
			
			ProcessSwingChange();
			
			ProcessPBChange();
			ProcessNBChange();
			
			ProcessTimeOut();
			
			ProcessTimerBChange();
			
			DisplayMuxAppShow();
			
			ProcessDispBChange();
			
			ProcessBuzz();
		}
		else{
			DisplayMuxAppReset();
			//Stop the spee motor
			//power Sleep mode
		}
	}
	
	return 0;
}

void SysTimerCallback(){
	CheckTimeOut();
	
	CheckTimerBChange();
	
	CheckNBChange();
	CheckPBChange();
	
	CheckSwingChange();
	
	CheckDispBChange();
	
	DispBDelay--;
	BuzzDelay--;
}

void systemInit(){
	DisplayMuxAppInit();
	
	SwingMotoInit();
	
	LcdAppInit();
	
	SpeedButtonsInit();
	
	SysTimerInit(SysTimerCallback);//set timer callbck func to the timer
	
	InitBuzz();
	
	BuzzDelay = 20;
}
