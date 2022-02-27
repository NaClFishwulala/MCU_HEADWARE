#ifndef __JOYSTICK_H
#define __JOYSTICK_H	

#include "stdio.h"
#include "adc.h" 

enum DIRECTION
{
		up,down,left,right
};

extern unsigned short adc_buff[50];
extern int dirction;

void GetJoyStickStatus(void);
#endif 
