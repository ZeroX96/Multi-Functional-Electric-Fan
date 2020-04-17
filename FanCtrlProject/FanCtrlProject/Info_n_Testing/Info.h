/*
 * Info.h
 *
 * Created: 3/20/2020 1:02:00 AM
 *  Author: Mahmo
 */ 


#ifndef INFO_H_
#define INFO_H_
//INFO
#if 0

#include "Gpio.h"
#include "Lcd.h"
#include "Timer.h"
#include "MotorSwing.h"
#include "SevenSeg.h"
#include "Adc.h"
#include "Pwm.h"
//one second >> used for the timer and sevensegment and button
//TimeOutValues			{1h	   ,2h	  ,4h     };
uint32_t TimeOutValues ={360000,720000,1440000};
uint32_t RemainingTimeOut;
_Bool EnableOnOffTimer;

//		BUZZER_TIMEOUT = 1 S
#define BUZZER_TIMEOUT 100
#define BUZZER_PIN
uint8_t BuzzerTimeOut;

_Bool SwingStateOld;
_Bool SwingStateCur;
_Bool SwingProcessSt;



"Required"
? Clock 8 MHz
? Analyzing Requirements
? Designing Software 
? Implementing Software
? Testing Software
"Main Fan Features" 
? Speed Control: 3 speeds (max, mid and min)
? Swing Control: 9 angles (0, 45, 90, 135, 180, 225, 270, 315, 360)
? Timer: Turn off fan after (1, 2, or 4 hours) 
? Buzzer: Indicate PB valid press (2 seconds buzz) or a change in the swing value
? SSD and LCD: Indicate current fan mode 
"System Description" 
====================Fan======================
“+” PB              |||         Swing Motor
“-” PB              |||         Buzzer
“Display” PB        |||         Speed Motor"triac"
“Timer” PB          |||         SSD
“Swing” Slider      |||         LCD
#Speed Control 
? 3 speeds are supported (max, mid and min).
? Default is min after power up. 
? AC speed motor is connected to the controller via a "triac".//Page 8
? A triac opens if a pulse is applied on it for 100 µs @ least.
? Please select an empty pin to output the triac pulse 
? Speed is varied by varying the position of the pulse after the zero crossing 
    of the AC line signal. 
? We will use a timer to simulate Zero-Crossing of the mains signal. It should 
    generate an interrupt every 10 ms to simulate a half sinewave. 
? Speed can only be changed as follows:
? “+” PB increases the speed if it is released and the speed is not max.
? “-” PB decreases the speed if it is released and the speed is not min.
"Cautions for AC Motor Control" 
#Startup Delay
? To reduce the startup surge current 
? Initial speed is @ 170 degrees
? Speed is changed gradually till reaching min speed
? Rate of change is 1 degree every 80 ms.
#Soft Switching 
? To controlling the speed smoothly when changing speeds 
? Speed is changed step by step gradually if the current speed is not the
    desired speed. 
? Rate of change is 1 degree every 80 ms.
#Swing Control 
? Swing angle can only be changed through the slider. 
? Please select an empty 4 pins to output the swing angle
Swing Angle Swing Motor Value 
0       0000
45      0001
90      0010
135     0011
180     0100
225     0101
270     0110
315     0111
360     1xxx
#Timer
? A Timer can be used to turn off the fan automatically after the selected time.
? The supported times are 0, 1, 2 and 4 hours.
? Whenever the “Timer” PB is pressed for 10 ms @ least, the timer setting 
    should change and count down restarts. 
? Timer setting changes as follows with every valid press 0h ? 1h ? 2h ?
    4h ? 0h and so on.
#Seven Segment Display 
? After startup “ HI ” should be displayed for 10 seconds on the SSD. 
? SSD can be updated after the 10 seconds to show the timer settings. 
? System should respond to timer settings during the first 10 seconds. 
? SSD should display the remaining time to turn off the fan with the 
    following format “HH.MM”. 
? If the timer setting is 0h, “00.00” is displayed.
? If timer setting is changed and not 0h, “HH.MM” should be displayed 
    showing the current timer setting.
? During timer count down, the fields should be updated and the dot blinks 
    every second. 
#LCD 
? Should display the current speed of the motor by default as follows:
? If the “Display” PB is pressed for 200 ms @ least, the LCD should display 
    the Swing state as follows:
    M o t o r S p e e d
S p e e d = x x x d e g r e e
0 degrees   S w i n g V a l u e
                
45 degrees  S w i n g V a l u e
                    * *
? The LCD should display the motor speed again after 20 seconds or after a 
valid “Display” PB press. 
90 degrees  S w i n g V a l u e
                  * * * *

360 degrees S w i n g V a l u e
        * * * * * * * * * * * * * * * *

//Pins Replacement
//Buttons and Slider and Buzzer >> A
Swing Slider => A0
Pb+			 =>A1
Pb- 		 =>A2
PbDisp		 =>A5
PbTimer		 =>A4
Buzz		 =>A5

//Motors and 7seg En >> B
I11			 =>B0		//wait one will use PWM >> Speed	//ToDo:Revise
I12			 =>B1
I13			 =>B2
I14			 =>B3
S0			 =>B4
S1	 		 =>B5
M0			 =>B6
M1	 		 =>B7

//LCD >> C
RS			 =>C0	
E			 =>C1
D4			 =>C2
D5			 =>C3
D6			 =>C4
D7	 		 =>C5

//7Seg Data Bus	>> D
0			 =>D0		//wait one will use PWM >> Speed	//ToDo:Revise
1			 =>D1
2			 =>D2
3			 =>D3
4			 =>D4
5	 		 =>D5
6			 =>D6

https://www.google.com/search?q=geeksforgeeks+c+questions&rlz=1C1CHBF_enEG875EG876&oq=geeksforgeeks+c+q&aqs=chrome.2.69i57j0l7.10207j0j7&sourceid=chrome&ie=UTF-8
https://www.geeksforgeeks.org/c-programming-language/
http://a4academics.com/interview-questions/57-c-plus-plus/722-embedded-c-interview-questions
https://www.google.com/search?rlz=1C1CHBF_enEG875EG876&ei=enaVXpi3G4eQlwTs-LrwCg&q=embedded+c+hard+questions&oq=embedded+c+hard+questions&gs_lcp=CgZwc3ktYWIQAzIICCEQFhAdEB4yCAghEBYQHRAeMggIIRAWEB0QHjIICCEQFhAdEB4yCAghEBYQHRAeMggIIRAWEB0QHjIICCEQFhAdEB4yCAghEBYQHRAeMggIIRAWEB0QHjIICCEQFhAdEB46BAgAEEdKCggXEgYxMi0xNDlKCAgYEgQxMi0zULMVWLMVYKYZaABwAngAgAGdA4gBnQOSAQM0LTGYAQCgAQGqAQdnd3Mtd2l6&sclient=psy-ab&ved=0ahUKEwiY3Nf4wefoAhUHyIUKHWy8Dq4Q4dUDCAw&uact=5
https://community.arm.com/developer/tools-software/tools/f/keil-forum/36860/enum-vs-define
https://www.geeksforgeeks.org/static-const-vs-define-vs-enum/
https://stackoverflow.com/questions/3134757/define-or-enum/3134870#3134870
https://www.quora.com/what-is-the-difference-between-enum-and-define-in-c-language
https://stackoverflow.com/questions/136946/difference-between-enum-and-define-statements
https://www.geeksforgeeks.org/enumeration-enum-c/
https://www.vector-events.com/tms/frontend/index.cfm?l=1000&modus=
https://www.vector.com/int/en/events/global-de-en/2020/vector-virtual-week-2020-stayhome-stayinformed/
https://www.youtube.com/watch?v=KDs3qlvmcvY







#endif //0
//END INFO


#if 0
speeds max, mid and min	>> PWM,Default is min
9 angles #USe Servo??
Timer can be used to turn off the fan automatically
The supported times are 0, 1, 2 and 4 hours.
0h ? 1h ? 2h ?
4h ? 0h and so on.
Buzzer
SSD
LCD
====================Fan======================
“+” PB              |||         Swing Motor
“-” PB              |||         Buzzer
“Display” PB        |||         Speed Motor"triac"
“Timer” PB          |||         SSD
“Swing” Slider      |||         LCD
use a timer to simulate Zero-Crossing generate an interrupt every 10 ms

? Swing angle can only be changed through the slider.
? Please select an empty 4 pins to output the swing angle
Swing Angle Swing Motor Value
0       0000
45      0001
90      0010
135     0011
180     0100
225     0101
270     0110
315     0111
360     1xxx

//timer
timer auto sys-off 1,2 or 4 hours
Default is min after power up
Whenever the “Timer” PB is pressed for 10 ms @ least, the timer setting	//we can check in the 10ms isr
should change and count down restarts
Timer setting changes as follows with every valid press 0h ? 1h ? 2h ?
4h ? 0h and so on
//buzzer
Indicate PB valid press or a change in the swing value
(2 seconds buzz)
//speed motor
“+” PB increases the speed if it is released and the speed is not max.
“-” PB decreases the speed if it is released and the speed is not min.
//swing motor
9 angles possible

//Seven Segment Display
? After startup “ HI ” should be displayed for 10 seconds on the SSD.
? SSD can be updated after the 10 seconds to show the timer settings.
? System should respond to timer settings during the first 10 seconds.
? SSD should display the remaining time to turn off the fan with the
following format “HH.MM”.
? If the timer setting is 0h, “00.00” is displayed.
? If timer setting is changed and not 0h, “HH.MM” should be displayed
showing the current timer setting.
? During timer count down, the fields should be updated and the dot blinks
every second.
//LCD
? Should display the current speed of the motor by default as follows:
? If the “Display” PB is pressed for 200 ms @ least, the LCD should display
the Swing state as follows:
M o t o r S p e e d
S p e e d = x x x d e g r e e
S w i n g V a l u e
0 degrees
S w i n g V a l u e
* *
The LCD should display the motor speed again after 20 seconds or after a
valid “Display” PB press.
#endif //0


#endif /* INFO_H_ */