#pragma once
//Beep(frequency,time);
#include <windows.h>
////////////////////////////////////
//frequency:

#define qdo 262 
#define qre 294
#define qmi 330
#define qfa 349
#define qso 392
#define qla 440
#define qsi 494 //低音（-8）


#define do 523
#define re 578
#define mi 659
#define fa 698
#define so 784
#define la 880
#define si 988 //中央


#define do1 1108 //1046
#define re1 1175
#define mi1 1318
#define fa1 1396 //1480
#define so1 1568
#define la1 1760
#define si1 1976 //高音 （+8）


#define sqdo 277
#define sqre 311
#define sqfa 370
#define sqso 415
#define sqla 466 //#低音 （#-8）


#define sdo 554
#define sre 622
#define sfa 740
#define sso 831
#define sla 932
#define sdo1 1046
#define sre1 1245
#define sfa1 1480
#define sso1 1661
#define sla1 1865 //#高音（#+8）



////////////////////////////////////
//time:

#define hfhxpad 50
#define hxpad 100
#define oppad 200
#define qtpad 400
#define hfpad 800
#define sfpad 1000 //(seventy-five percent)
#define pad 1200
#define point 1800

/////////////////////
//sim time counter
/*
*                   float hhour, mmin, ssec,ct;
					ct = 0;
					hhour = 01;
					mmin = 23;
					ssec = 07;
					ssec = ct + ssec;
					if (ssec >= 60)
					{
						ssec = 00;
						mmin = mmin + 1;
					}
					if (mmin >= 60)
					{
						mmin = 00;
						hhour = hhour + 1;
					}







*/
////