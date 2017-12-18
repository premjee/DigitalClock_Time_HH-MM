/* 
 * File:   segment_LED.h
 * Author: Prem Jeevan
 *
 * Created on November 24, 2017, 11:45 PM
 */
#ifndef SEGMENT_LED_H
#define	SEGMENT_LED_H

#ifdef	__cplusplus
extern "C" {
#endif

    #define LED_7_SEG_A_PIN          PORTAbits.RA1
#define LED_7_SEG_B_PIN          PORTAbits.RA0
#define LED_7_SEG_C_PIN          PORTAbits.RA4
#define LED_7_SEG_D_PIN          PORTAbits.RA5
#define LED_7_SEG_E_PIN          PORTCbits.RC1
#define LED_7_SEG_F_PIN          PORTCbits.RC5
#define LED_7_SEG_G_PIN          PORTCbits.RC2
#define LED_7_SEG_A_MODE         TRISAbits.TRISA1
#define LED_7_SEG_B_MODE         TRISAbits.TRISA0
#define LED_7_SEG_C_MODE         TRISAbits.TRISA4
#define LED_7_SEG_D_MODE         TRISAbits.TRISA5
#define LED_7_SEG_E_MODE         TRISCbits.TRISC1
#define LED_7_SEG_F_MODE         TRISCbits.TRISC5
#define LED_7_SEG_G_MODE         TRISCbits.TRISC2
#define HRS_DISP_H_PIN           PORTBbits.RB2
#define HRS_DISP_L_PIN           PORTBbits.RB4
#define MIN_DISP_H_PIN           PORTBbits.RB5
#define MIN_DISP_L_PIN           PORTBbits.RB0

#define HRS_DISP_H_MODE          TRISBbits.TRISB2
#define HRS_DISP_L_MODE          TRISBbits.TRISB4
#define MIN_DISP_H_MODE          TRISBbits.TRISB5
#define MIN_DISP_L_MODE          TRISBbits.TRISB0
    
//#define SEC_LED_PIN              PORTBbits.RB7
//#define SEC_LED_PIN_MODE         TRISBbits.TRISB7

#define MIN_DISP_L   0
#define MIN_DISP_H   1
#define HRS_DISP_L   2
#define HRS_DISP_H   3


    

unsigned char CA[10] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char CC[10] = {0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

void init_segment_leds(void);
void display_digit(unsigned char digit, unsigned char segModuleNo);
#ifdef DEBUG_7SEG_LED
void test_segment_led(void);
#endif
#ifdef	__cplusplus
}
#endif

#endif	/* SEGMENT_LED_H */

