/* 
 * File:   i2c.h
 * Author: Prem Jeevan
 *
 * Created on November 24, 2017, 11:45 PM
 */

#ifndef I2C_H
#define	I2C_H

#ifdef	__cplusplus
extern "C" {
#endif

#define IIC_SDA_PIN         PORTCbits.RC4
#define IIC_SCL_PIN         PORTCbits.RC3
#define IIC_SDA_PIN_MODE    TRISCbits.TRISC4
#define IIC_SCL_PIN_MODE    TRISCbits.TRISC3
#define scl IIC_SCL_PIN
#define sda IIC_SDA_PIN 


bit i2c_busy, no_ack, bus_fault;
typedef unsigned char ubyte;

ubyte a;

bit LSB; 
bit MSB; 

void send_stop();
void master(ubyte);
void send_byte(ubyte);
void send_data(ubyte, ubyte, ubyte, ubyte *);
ubyte recv_byte(ubyte);
void recv_data(ubyte, ubyte, ubyte, ubyte *);
void i2c_init(void);

#ifdef	__cplusplus
}
#endif

#endif	/* I2C_H */

