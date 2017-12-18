/* 
 * File:   segment_LED.c
 * Author: Prem Jeevan
 *
 * Created on November 24, 2017, 11:45 PM
 */
#include "clock_pjt.h"
#include "segment_LED.h"

/*
 * Function: init_segment_leds
 *
 * Purpose: Initialize peripherals as output and make it low for common cathode   
 *          7 segment LED.
 * Parameters: void
 * 
 * Return: void
 */
void init_segment_leds(void){
    /* make all pins to output*/
    LED_7_SEG_A_MODE = OUTPUT;
    LED_7_SEG_B_MODE = OUTPUT;
    LED_7_SEG_C_MODE = OUTPUT;
    LED_7_SEG_D_MODE = OUTPUT;
    LED_7_SEG_E_MODE = OUTPUT;
    LED_7_SEG_F_MODE = OUTPUT;
    LED_7_SEG_G_MODE = OUTPUT;
    HRS_DISP_H_MODE = OUTPUT;
    HRS_DISP_L_MODE = OUTPUT;
    MIN_DISP_H_MODE = OUTPUT;
    MIN_DISP_L_MODE = OUTPUT;
   
 // SEC_LED_PIN_MODE = OUTPUT;     // commented since the RTC-swq 
                                   // can toggle seconds LED at 1Hz 
    /* make all pins to level 0*/
    LED_7_SEG_A_PIN = LOW;
    LED_7_SEG_B_PIN = LOW;
    LED_7_SEG_C_PIN = LOW;
    LED_7_SEG_D_PIN = LOW;
    LED_7_SEG_E_PIN = LOW;
    LED_7_SEG_F_PIN = LOW;
    LED_7_SEG_G_PIN = LOW;
    HRS_DISP_H_PIN = LOW;
    HRS_DISP_L_PIN = LOW;
    MIN_DISP_H_PIN = LOW;
    MIN_DISP_L_PIN = LOW;
//  SEC_LED_PIN = LOW; 
}
/*
 * Function: display_digit
 *
 * Purpose: identify the cc-7segLED and turn on each segment of it's LED for 1uS   
 *          
 * Parameters: void
 * 
 * Return: void
 */
void display_digit(unsigned char digit, unsigned char segModuleNo){
    unsigned char number = CC[digit];
    switch (segModuleNo){
        case MIN_DISP_L: 
            MIN_DISP_H_PIN = LOW;
            HRS_DISP_L_PIN = LOW; 
            HRS_DISP_H_PIN = LOW;  
            MIN_DISP_L_PIN = HIGH; 
            break;
        case MIN_DISP_H:
            MIN_DISP_L_PIN = LOW; 
            HRS_DISP_L_PIN = LOW; 
            HRS_DISP_H_PIN = LOW;  
            MIN_DISP_H_PIN = HIGH;
            break;   
        case HRS_DISP_L: 
            MIN_DISP_L_PIN = LOW; 
            MIN_DISP_H_PIN = LOW;            
            HRS_DISP_H_PIN = LOW;
            HRS_DISP_L_PIN = HIGH; 
            break;
        case HRS_DISP_H:
            MIN_DISP_L_PIN = LOW; 
            MIN_DISP_H_PIN = LOW;
            HRS_DISP_L_PIN = LOW; 
            HRS_DISP_H_PIN = HIGH;  
            break;

        default:
            MIN_DISP_L_PIN = LOW; 
            MIN_DISP_H_PIN = LOW;
            HRS_DISP_L_PIN = LOW; 
            HRS_DISP_H_PIN = LOW;
            break;
    }
    

    if(number & (1<<0))
        LED_7_SEG_A_PIN = HIGH;
    else
        LED_7_SEG_A_PIN = LOW;
    __delay_us( 1); LED_7_SEG_A_PIN = LOW;
    if(number & (1<<1))
        LED_7_SEG_B_PIN = HIGH;
    else
        LED_7_SEG_B_PIN = LOW;
    __delay_us( 1); LED_7_SEG_B_PIN = LOW;
    if(number & (1<<2))
        LED_7_SEG_C_PIN = HIGH;
    else
        LED_7_SEG_C_PIN = LOW;
    __delay_us( 1); LED_7_SEG_C_PIN = LOW;
    if(number & (1<<3))
        LED_7_SEG_D_PIN = HIGH;
    else
        LED_7_SEG_D_PIN = LOW;
    __delay_us( 1); LED_7_SEG_D_PIN = LOW;
    if(number & (1<<4))
        LED_7_SEG_E_PIN = HIGH;
    else
        LED_7_SEG_E_PIN = LOW;
    __delay_us( 1); LED_7_SEG_E_PIN = LOW;
    if(number & (1<<5))
        LED_7_SEG_F_PIN = HIGH;
    else
        LED_7_SEG_F_PIN = LOW;
    __delay_us( 1);LED_7_SEG_F_PIN = LOW;
    if(number & (1<<6))
        LED_7_SEG_G_PIN = HIGH;
    else
        LED_7_SEG_G_PIN = LOW;
    __delay_us( 1);LED_7_SEG_G_PIN = LOW;
    
    MIN_DISP_L_PIN = LOW; 
    MIN_DISP_H_PIN = LOW;
    HRS_DISP_L_PIN = LOW; 
    HRS_DISP_H_PIN = LOW;        
}
/*
 * Function: test_segment_led
 *
 * Purpose: To visually check each led of the 7seg Led's are working fine.    
 *          
 * Parameters: void
 * 
 * Return: void
 */
#ifdef DEBUG_7SEG_LED
void test_segment_led(void){
    while (1){
        /* */
        HRS_DISP_H_PIN = HIGH;
        LED_7_SEG_A_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_A_PIN = LOW;
        LED_7_SEG_B_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_B_PIN = LOW;
        LED_7_SEG_C_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_C_PIN = LOW;
        LED_7_SEG_D_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_D_PIN = LOW;
        LED_7_SEG_E_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_E_PIN = LOW;
        LED_7_SEG_F_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_F_PIN = LOW;
        LED_7_SEG_G_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_G_PIN = LOW;
        HRS_DISP_H_PIN = LOW;

        /* */
        HRS_DISP_L_PIN = HIGH;
        LED_7_SEG_A_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_A_PIN = LOW;
        LED_7_SEG_B_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_B_PIN = LOW;
        LED_7_SEG_C_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_C_PIN = LOW;
        LED_7_SEG_D_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_D_PIN = LOW;
        LED_7_SEG_E_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_E_PIN = LOW;
        LED_7_SEG_F_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_F_PIN = LOW;
        LED_7_SEG_G_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_G_PIN = LOW;
        HRS_DISP_L_PIN = LOW;

        /* */
        MIN_DISP_H_PIN = HIGH;
        LED_7_SEG_A_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_A_PIN = LOW;
        LED_7_SEG_B_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_B_PIN = LOW;
        LED_7_SEG_C_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_C_PIN = LOW;
        LED_7_SEG_D_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_D_PIN = LOW;
        LED_7_SEG_E_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_E_PIN = LOW;
        LED_7_SEG_F_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_F_PIN = LOW;
        LED_7_SEG_G_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_G_PIN = LOW;
        MIN_DISP_H_PIN = LOW;

        /* */

        MIN_DISP_L_PIN = HIGH;
        LED_7_SEG_A_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_A_PIN = LOW;
        LED_7_SEG_B_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_B_PIN = LOW;
        LED_7_SEG_C_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_C_PIN = LOW;
        LED_7_SEG_D_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_D_PIN = LOW;
        LED_7_SEG_E_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_E_PIN = LOW;
        LED_7_SEG_F_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_F_PIN = LOW;
        LED_7_SEG_G_PIN = HIGH; __delay_ms(1);
        LED_7_SEG_G_PIN = LOW;
        MIN_DISP_L_PIN = LOW;

//       SEC_LED_PIN = HIGH; __delay_ms(1);
//       SEC_LED_PIN = LOW;
    }
}
#endif

