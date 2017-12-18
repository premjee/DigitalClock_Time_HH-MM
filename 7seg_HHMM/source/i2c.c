/* 
 * File:   i2c.c
 * Author: Prem Jeevan
 *
 * Created on November 24, 2017, 11:45 PM
 */
#include "clock_pjt.h"
#include "i2c.h"
#define HOLD __delay_us(3)

/*
 * Function: i2c_init
 *
 * Purpose: Since this is a bitbang implementation of IIC protocol, initialize     
 *          peripherals pins for enabling I2c communication with RTC.
 * Parameters: void
 * 
 * Return: void
 */
void i2c_init(void){
   IIC_SCL_PIN_MODE = OUTPUT;
   IIC_SDA_PIN_MODE = OUTPUT;
}

/*
 * Function: send_stop
 *
 * Purpose: Send a stop to indicate end of communication by     
 *          toggling SDA from low to high when SCL is high.
 * Parameters: void
 * 
 * Return: void
 */

void send_stop()
{
	sda = 0;
	scl = 1;
	HOLD;
	sda = 1;
	i2c_busy = 0;
}

/*
 * Function: master
 *
 * Purpose: To check if the bus is idle and then send a start condition by       
 *          toggling SDA from high to low when SCL is high. After toggling SDA
 *          then pull SCL low and then start sending slave address with read
 *          or write condition. 
 * Parameters: 8 bit slave address 
 * 
 * Return: void
 */

void master(ubyte slave_addr)
{
   IIC_SCL_PIN_MODE = INPUT;
   IIC_SDA_PIN_MODE = INPUT;
	i2c_busy = 1;
	no_ack = 0;
	bus_fault = 0;
	if(!scl||!sda)
		bus_fault = 1;
	else
	{
        IIC_SCL_PIN_MODE = OUTPUT;
        IIC_SDA_PIN_MODE = OUTPUT;
		sda = 0;
		HOLD;
		scl = 0;
		HOLD;
		send_byte(slave_addr);
	}
}

/*
 * Function: send_byte
 *
 * Purpose: Transfer 8 bit data in SDA, place each bit in SDA and 
 *          toggling SLC from low to high. MSB has to be transfered first.
 *          After transfering all 8 bits, pull SDA & SCL high and then check 
 *          the status of SDA for ACK signal. 
 *          
 * Parameters: 8 bit data
 * 
 * Return: void
 */

void send_byte(ubyte i2c_data)
{
	ubyte i;
	a=i2c_data;
   IIC_SCL_PIN_MODE = OUTPUT;
   IIC_SDA_PIN_MODE = OUTPUT;
	for(i=0;i<8;i++)
	{
		scl=0;
		HOLD;
        MSB =(a & 0x80)? 1:0;           
		sda=MSB;     
		a<<=1;
		__delay_us(1);
		scl=1;
		HOLD;
		scl=0;
	}
	sda = 1;
	scl = 1;
	HOLD;
	if(!sda)
	{
		scl = 0;
		HOLD;
	}
	else
	{
		no_ack = 1;
		scl = 0;
		HOLD;
	}
}
/*
 * Function: send_data
 *
 * Purpose: To transfer a set of data to the slave device. 
 * 
 * 
 * Parameters: slave address, starting address of data to be placed, 
 *             no of bytes, initial Buffer address.
 * 
 * Return: void
 */

void send_data(ubyte slave_add, ubyte sub_add, ubyte bytes, ubyte *data_in)
{
	master(slave_add);
	send_byte(sub_add);
	if(no_ack)
		send_stop();
	else
	{
		for(bytes;bytes>0;bytes--)
		{
			send_byte(*data_in++);
			if(no_ack)
				break;
		}
		send_stop();
	}
}

/*
 * Function: recv_byte
 *
 * Purpose: Receive 8 bit of data from SDA by toggeling SCL. 
 *          After receiving 8 bit of data check if this is the last 
 *          expected byte. Do not send an ack for the last byte 
 *          i.e. make SDA line high after receiving the last byte of data. 
 *          
 * Parameters: byte count No. 
 * 
 * Return: received byte
 */

ubyte recv_byte(ubyte cnt)
{
	ubyte i,rcv_data;
    //LSB = (a & 0x01); //appended
    a=0; //appended
	for(i=0;i<8;i++)
	{
		sda=1;
		scl=1;
		HOLD;
        //IIC_SCL_PIN_MODE = OUTPUT;
         IIC_SDA_PIN_MODE = INPUT;
		LSB = sda ? 1:0;
        a |= LSB;
		if(i<7)
			a<<=1;
		HOLD;
		scl=0;
		HOLD;
	}
    IIC_SCL_PIN_MODE = OUTPUT;
    IIC_SDA_PIN_MODE = OUTPUT;
	if(cnt==1)
		sda = 1;
	else
		sda = 0;
	scl =1;
	HOLD;
	scl = 0;
	sda = 1;
	HOLD;
	rcv_data = a;
	return rcv_data;
}

/*
 * Function: recv_data
 *
 * Purpose: Receive a set of data from slave device 
 * 
 * Parameters: slave address, starting address of data to be placed, 
 *             no of bytes, initial Buffer address from which data to be stored.
 * Return: void
 */

void recv_data(ubyte slave_add, ubyte sub_add, ubyte byte_cnt, ubyte *recv_buf)
{
	ubyte i;
    IIC_SCL_PIN_MODE = OUTPUT;
    IIC_SDA_PIN_MODE = OUTPUT;
	scl = sda = 1;
	master(slave_add);
	send_byte(sub_add);
	slave_add+=1;
	scl = sda = 1;
	master(slave_add);
	if(no_ack)
	{
		send_stop();
		goto exit;
	}
	for(i=0;i<byte_cnt;i++)
		recv_buf[i]=recv_byte(byte_cnt-i);
	send_stop();
exit: ;
}
