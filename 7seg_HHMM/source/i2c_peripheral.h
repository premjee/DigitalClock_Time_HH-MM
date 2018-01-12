/* 
 * File:   i2c_peripheral.h
 * Author: Prem Jeevan
 *
 * Created on December 27, 2017, 3:51 AM
 */

#ifndef I2C_PERIPHERAL_H
#define	I2C_PERIPHERAL_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define I2C_INTERRUPT_EN //I2C functionality is performed on interrupt basis
    
#define IIC_SCL_MODE    TRISCbits.TRISC3
#define IIC_SDA_MODE    TRISCbits.TRISC4
#define IIC_SCL_PIN     PORTCbits.RC3
#define IIC_SDA_PIN     PORTCbits.RC4
#define IIC_CLK_FREQ    100000 // 100khz

ubyte i2cTxBuff[10],i2cRxBuff[10],i2cTxCount,i2cRxCount;
ubyte i2cBuffCount,i2cRdBuffsize;

//volatile ubyte i2c_reg_addr = 0;
//volatile ubyte i2c_reg_map[16 ] = {0,};
//volatile ubyte i2c_byte_count = 0;
void send_data(ubyte slave_add, ubyte sub_add, ubyte bytes, ubyte *data_in);
void recv_data(ubyte slave_add, ubyte sub_add, ubyte byte_cnt, ubyte *recv_buf);
unsigned short I2C_Master_Read(unsigned short a);
void I2C_Master_Write(unsigned d);
void I2C_Master_Stop(void);
void I2C_Master_RepeatedStart(void);
void I2C_Master_Start(void);
void I2C_Master_Wait(void);
void i2c_init (void);
void enable_interrupts(void);



#ifdef	__cplusplus
}
#endif

#endif	/* I2C_PERIPHERAL_H */

