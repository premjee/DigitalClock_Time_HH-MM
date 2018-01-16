/* 
 * File:   ds1307.c
 * Author: Prem Jeevan
 *
 * Created on November 24, 2017, 11:45 PM
 */
 
#include "clock_pjt.h"
#include "ds1307.h"
#include "i2c.h"

/*
 * Function: update_time
 *
 * Purpose: Get time from RTC and store it in global variable   
 * 
 * Parameters: void
 * 
 * Return: void
 */
void update_time(void){
  unsigned char dateTimestamp[8];
    recv_data(DS1307_SLAVE_ADD,DS1307_SECONDS,3,&dateTimestamp[0]);
	hours= dateTimestamp[2] & 0x3F;
    hours = bcd2bin((hours>>4),(hours & 0x0f));    
	minutes= dateTimestamp[1] & 0x7F;
    minutes= bcd2bin((minutes>>4),(minutes & 0x0f)); 
	seconds= dateTimestamp[0] & 0x7F;
    seconds= bcd2bin((seconds>>4),(seconds & 0x0f));
}
/*
 * Function: setup_rtc
 *
 * Purpose: To set date and time of RTC for the first time during board bring up   
 * 
 * Parameters: void
 * 
 * Return: void
 */
//#ifdef PRODUCTION_RELEASE
void setup_rtc(void)
{      
  enum {rtc_sec=0,rtc_min,rtc_hrs,rtc_day, rtc_date, rtc_mth, rtc_year,rtc_cnt};
  unsigned char configRTC[9];
        configRTC[rtc_sec]=(0x00);
		configRTC[rtc_min]=0x59;
		configRTC[rtc_hrs]=0x23;
		configRTC[rtc_day]=0x06;
		configRTC[rtc_date]=0x11;
		configRTC[rtc_mth]=0x11;
		configRTC[rtc_year]=0x17;
		configRTC[rtc_cnt]=0x10; //config reg - enabling square wave at 1hz
		configRTC[8]=0x01; //config reg	
        send_data(DS1307_SLAVE_ADD,DS1307_SECONDS,8,configRTC);
}
//#endif
/*
 * Function: init_rtc
 *
 * Purpose: Initialize peripheral pins/ functional registers to establish    
 *          communication with RTC
 * Parameters: void
 * 
 * Return: void
 */
void init_rtc(void){
  i2c_init();   
  check_rtc();
}
/*
 * Function: update_date_time
 *
 * Purpose: Get date and time from RTC and store it in global variable    
 *           
 * Parameters: void
 * 
 * Return: void
 */
void update_date_time(void){
  unsigned char dateTimestamp[8];
    recv_data(DS1307_SLAVE_ADD,DS1307_SECONDS,7,&dateTimestamp[0]);
    year = dateTimestamp[6] & 0xFF;
    year = bcd2bin((year>>4),(year & 0x0f));        
    month = dateTimestamp[5] & 0x1F;
    month = bcd2bin((month>>4),(month & 0x0f));
	dayofmonth= dateTimestamp[4] & 0x3F;
    dayofmonth = bcd2bin((dayofmonth>>4),(dayofmonth & 0x0f));            
            
    dayofweek = dateTimestamp[3] & 0x07;
    dayofweek = bcd2bin((dayofweek>>4),(dayofweek & 0x0f));
	hours= dateTimestamp[2] & 0x3F;
    hours = bcd2bin((hours>>4),(hours & 0x0f));    
	minutes= dateTimestamp[1] & 0x7F;
    minutes= bcd2bin((minutes>>4),(minutes & 0x0f)); 
	seconds= dateTimestamp[0] & 0x7F;
    seconds= bcd2bin((seconds>>4),(seconds & 0x0f));
}
/*
 * Function: check_rtc
 *
 * Purpose: initializes RTC register value when RTC is in reset/idle state.     
 *           
 * Parameters: void
 * 
 * Return: void
 */
void check_rtc(void){
    unsigned int i=0;
    uint8_t prevSec=0;
    update_date_time();
    if((dayofmonth == 0x01)&&(month == 0x01)&&(year == 0)&&(dayofmonth == 0x01) \
            &&(hours == 0)&&(minutes == 0)&&(seconds == 0)){
        setup_rtc();
    }
    prevSec = seconds;
    for(i=0;i<20;i++) // delay for 2 sec
    __delay_ms(100);
    update_time();
    if(prevSec == seconds){
        setup_rtc();
    }
    
}