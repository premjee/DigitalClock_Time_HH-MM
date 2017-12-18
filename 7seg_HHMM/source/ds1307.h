/* 
 * File:   ds1307.h
 * Author: Prem Jeevan
 *
 * Created on November 24, 2017, 11:45 PM
 */

#ifndef DS1307_H
#define	DS1307_H

#ifdef	__cplusplus
extern "C" {
#endif
#define DS1307_SLAVE_ADD         0xD0
#define DS1307_SLAVE_RD     (DS1307_SLAVE_ADD | 0x01)
#define DS1307_SLAVE_WR     DS1307_SLAVE_ADD
// Register names.
#define DS1307_SECONDS           0x00
#define DS1307_MINUTES           0x01
#define DS1307_HOURS             0x02
#define DS1307_DAY               0x03
#define DS1307_DATE              0x04
#define DS1307_MONTH             0x05
#define DS1307_YEAR              0x06
#define DS1307_CONTROL           0x07
#define DS1307_RAMSTART          0x08
#define DS1307_RAMEND            0x3F
#define DS1307_CLK_HALT_EN       0x80
    
uint8_t seconds, minutes, hours, dayofweek, dayofmonth, month, year;

void init_rtc(void);
#ifdef PRODUCTION_RELEASE
void setup_rtc(void);
#endif
void update_time(void);


#ifdef	__cplusplus
}
#endif

#endif	/* DS1307_H */

