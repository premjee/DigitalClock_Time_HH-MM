/* 
 * File:   clock_pjt.h
 * Author: Prem Jeevan
 *
 * Created on November 24, 2017, 11:45 PM
 */

#ifndef CLOCK_PJT_H
#define	CLOCK_PJT_H

#ifdef	__cplusplus
extern "C" {
#endif
// PIC16F886 Configuration Bit Settings

// 'C' source line config statements
#define _XTAL_FREQ (18432000ULL) 
// CONFIG1
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator: High-speed crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = ON       // RE3/MCLR pin function select bit (RE3/MCLR pin function is MCLR)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = ON         // Low Voltage Programming Enable bit (RB3/PGM pin has PGM function, low voltage programming enabled)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
    
//#define DEBUG_7SEG_LED //Uncomment it for testing LED 
/* Uncomment PRODUCTION_RELEASE macro for programming the device
 *   for the first time. This initializes date and time to RTC register.
 */
#define PRODUCTION_RELEASE    



#define HOURS_SWITCH_PIN         PORTCbits.RC7
#define MIN_SWITCH_PIN           PORTCbits.RC6
#define HOURS_SWITCH_PIN_MODE    TRISCbits.TRISC7
#define MIN_SWITCH_PIN_MODE      TRISCbits.TRISC6   
    
#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0

#define bcd2bin(h,l)    (((h)*10) + (l))
#define bin2bcd_h(x)   ((x)/10)
#define bin2bcd_l(x)    ((x)%10)

typedef unsigned int uint8_t;
void check_switch_status(void);
void init_RTC_config_switches(void);
#ifdef	__cplusplus
}
#endif

#endif	/* CLOCK_PJT_H */

