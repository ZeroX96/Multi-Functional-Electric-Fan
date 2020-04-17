/*
 * Testing.h
 *
 * Created: 4/15/2020 7:27:23 AM
 *  Author: Mahmo
 */ 


#ifndef TESTING_H_
#define TESTING_H_





#ifdef TESTING
//#ifdef TIMER_TESTING
void msa(void)
{
	PORTB =0X96;
	_delay_ms(10);
	PORTB =0X00;
	_delay_ms(10);
}
//#endif //TIMER_TESTING
#ifdef ADC_TESTING
void msa(void)
{
	PORTB =0X96;
	_delay_ms(10);
	PORTB =0X00;
	_delay_ms(10);
}
#endif //ADC_TESTING
int main(void)
{
	//testing the gpio driver
	#ifdef GPIO_TESTING
	GpioInitPort(BASE_A,PORT_OUT);
	GpioInitPin(BASE_B,PIN_5,PIN_IN);
	GpioInitPin(BASE_B,PIN_4,PIN_OUT);
	GpioWritePort(BASE_A,0x96);
	GpioInitPort(BASE_C,PORT_IN);
	uint8_t pin5st = GpioReadPin(BASE_B,PIN_5);
	GpioWritePin(BASE_B,PIN_4,pin5st);
	uint8_t val=0;
	while (1)
	{
		val++;
		GpioWritePort(BASE_A,val);
		uint8_t pin5st = GpioReadPin(BASE_B,PIN_5);
		GpioWritePin(BASE_B,PIN_4,pin5st);
	}
	#endif //GPIO_TESTING
	//testing lcd driver
	#ifdef LCD_TESTING
	LcdT LcdTest;
	LcdTest.DataBase = BASE_B;
	LcdTest.CommBase = BASE_B;
	LcdInit(&LcdTest);
	while(1){
		LcdCharDataOut(&LcdTest,'E');
		_delay_ms(500);
		LcdArrDataOut(&LcdTest,"MSA");
		_delay_ms(500);
		LcdCommOut(&LcdTest,BEGIN_FROM_2ND_LINE);
		LcdArrDataOut(&LcdTest,"MMA");
		_delay_ms(500);
		LcdGotoXnY(&LcdTest,2,2);
		LcdCharDataOut(&LcdTest,'A');
		_delay_ms(500);
	}
	LcdDeInit(&LcdTest);
	#endif //LCD_TESTING
	#ifdef TIMER_TESTING
	//testing timer
	DDRA = 0xff;
	DDRB = 0xff;
	TimerT test;
	test.Base = TIMER_0;
	test.Clk = CLK_PRESCALER_8;
	test.CompMatchMode = OC_TOGGLE;
	test.Int = INT_OV;	//handle the isr
	test.Mode = NORMAL_OP_MODE;
	test.OcrVal = 150;
	test.TcntVal = 2;
	test.OvCallBkFunc = msa;
	TimerInit(&test);
	TimerFOC(&test);
	uint8_t read = TimerRead(&test);
	TimerCountUpdate(&test,20);
	TimerOcrUpdate(&test,20);
	//TimerDeInit(&test);
	while (1)
	{
		PORTA =0X96;
		_delay_ms(10);
		PORTA =0X00;
		_delay_ms(10);
	}
	#endif //TIMER_TESTING
	//testing swing motor
	#if SWING_TESTING
	SwingMotoInit(BASE_A,4);
	while(1){
		SwingMotoSetAngle(BASE_A,DEG_90);
		_delay_ms(500);
		SwingMotoSetAngle(BASE_A,DEG_270);
		_delay_ms(500);
		SwingMotoSetAngle(BASE_A,DEG_45);
		_delay_ms(500);
	}
	#endif //SWING_TESTING
	//testing the 7segment disp
	#ifdef SEVSEG_TESTING
	SevenSegT DispTest;
	DisplayInit(&DispTest,BASE_A,DISP_COMMON_CATHODE);
	while(1){
		DisplayWrite(&DispTest,5);
		_delay_ms(500);
		DisplayWrite(&DispTest,7);
		_delay_ms(500);
		DisplayReset(&DispTest);
		_delay_ms(500);
	}
	DisplayDeInit(&DispTest);
	#endif //SEVSEG_TESTING
	//testing the 7segment Mux disp
	#ifdef SEVSEG_MUX_TESTING
	SevenSegT DispTest;
	uint8_t data[4]= {5,6,7,8};
	DisplayMuxInit(&DispTest,BASE_C,BASE_D,DISP_COMMON_CATHODE);
	//DisplayMuxWrite(&DispTest,data);
	//data[2] = 0;
	//data[0] = 3;
	//DisplayMuxWrite(&DispTest,data);
	//uint8_t i=1;
	//DDRA = DDRB = 0xff;
	while(1){
		//data[0] = i%10;
		//data[1] = (i+6)%10;
		//data[2] = (i*2)%10;
		//data[3] = (i+7)%10;
		DisplayMuxWrite(&DispTest,data);
		//i++;
		//_delay_ms(5);
		//DisplayMuxReset(&DispTest);
		//_delay_ms(500);

	}
	DisplayMuxDeInit(&DispTest);
	#endif //SEVSEG_MUX_TESTING
	//testing adc
	#ifdef ADC_TESTING
	DDRD =0xff;
	DDRC =0xff;
	DDRB =0xff;
	DDRA =0x00;
	AdcT adcTst;
	adcTst.AutoTrig = AT_DISABLE;
	adcTst.CALLBackFunc = msa;
	adcTst.Channel = ADC_CH0_SINGLE;
	adcTst.IntMode = INTURREPT_DISABLE;
	adcTst.PrescSel = DIV_BY_128;
	adcTst.RefSel = INTERNAL256;
	adcTst.ResAdj = LEFT_ADJ;
	adcTst.TrigSrc = FREE_RUNNING_M;
	AdcInit(&adcTst);
	uint16_t adcres=0;
	while(1){
		//ADCSRA |=(1<<ADSC);
		//while(ADCSRA&(1<<ADIF) == 0);
		AdcRead(&adcTst,&adcres);
		PORTC = adcres & 0x00FF;
		PORTD = (adcres>>8);
		//PORTC = ADC_L;
		//PORTD = ADC_H;
		_delay_ms(50);
		//PORTB++;
		
	}
	//AdcRead(&adcTst,&adcres);
	#endif //ADC_TESTING
	//pwm testing
	#ifdef PWM_TESTING
	PwmT tstPwm;
	uint8_t i=0,j=0;
	PwmInit(&tstPwm,PWM_TIMER_0,INVERTING_OUTPUT,TWENTY_PERCENT,FAST_PWM,155);
	while (1)
	{
		PwmEdit(&tstPwm,INVERTING_OUTPUT,TWENTY_PERCENT+i,FAST_PWM,155);
		i+=10;
		//j+=20;
		_delay_ms(500);
	}
	#endif //PWM_TESTING
}
#endif //TESTING




#endif /* TESTING_H_ */