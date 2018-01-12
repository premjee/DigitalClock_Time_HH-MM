/*
 * File:   clock_pjt.c
 * Author: Prem Jeevan
 *
 * Created on November 19, 2017, 11:34 PM
 */

#include "clock_pjt.h"
#include "i2c_peripheral.h"
#include "ds1307.h"
#include "segment_LED.h"


void main(void) {
   OPTION_REG = 0x00;
    INTCON = 0x00;
    PIE1 = 0x00;    
    TRISA = 0x00;
    TRISB = 0x00;
    TRISC = 0x00;
    ANSEL = 0x00;

    __delay_ms(10);    
    init_RTC_config_switches();
    init_segment_leds();
    __delay_ms( 1);

    init_rtc();
#ifdef DEBUG_7SEG_LED
    test_segment_led();
#endif      
    while(1){        
        update_time();
        display_digit(bin2bcd_h(hours),HRS_DISP_H);
        display_digit(bin2bcd_l(hours),HRS_DISP_L);
        display_digit(bin2bcd_h(minutes),MIN_DISP_H);
        display_digit(bin2bcd_l(minutes),MIN_DISP_L);
        check_switch_status();
    }    
    return;
}
/*
 * Function: init_RTC_config_switches
 *
 * Purpose: Initialization of hrs & min configuration switches as input   
 * 
 * Parameters: void
 * 
 * Return: void
 */
void init_RTC_config_switches(void){
    HOURS_SWITCH_PIN_MODE = INPUT; 
    MIN_SWITCH_PIN_MODE = INPUT;
}
/*
 * Function: check_switch_status
 *
 * Purpose: Checks if hrs/ min switch is pressed.   
 * 
 * Parameters: void
 * 
 * Return: void
 */
void check_switch_status(void){
    unsigned char temp;
    if(!MIN_SWITCH_PIN){
      __delay_ms(100);   /* Extra debounce delay required for type of switch */
      if(!MIN_SWITCH_PIN){
        __delay_ms(50);      /* key debounce delay */
        if(!MIN_SWITCH_PIN){
            minutes ++;
            if ((minutes>59) || (minutes<0)){
                minutes = 0;
            } 
            temp = (bin2bcd_h(minutes)<<4) |(bin2bcd_l(minutes));
            send_data(DS1307_SLAVE_ADD,DS1307_MINUTES,1,&temp);
        }  
      }                
    }
    if(!HOURS_SWITCH_PIN){
      __delay_ms(100); /* Extra debounce delay required for type of switch */
      if(!HOURS_SWITCH_PIN){
        __delay_ms(50);  /* key debounce delay */
        if(!HOURS_SWITCH_PIN){
            hours ++;
            if ((hours>23) || (hours<0)){
                hours = 0;
            } 
            temp = (bin2bcd_h(hours)<<4) |(bin2bcd_l(hours));
            send_data(DS1307_SLAVE_ADD,DS1307_HOURS,1,&temp);
        }  
      }                
}
}
