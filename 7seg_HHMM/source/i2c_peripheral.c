#include "clock_pjt.h"
#include "i2c_peripheral.h"


#ifdef I2C_INTERRUPT_EN
void __interrupt i2c_isr (void){
    if (PIR1bits.SSPIF) {
        if(i2cTxCount){
//            if (SSPSTATbits.S) {
            if(i2cBuffCount == 0){
                I2C_Master_Wait();
                SSPBUF = i2cTxBuff[i2cBuffCount++];        
            }
//            else if((!SSPCON2bits.ACKSTAT)&&(i2cBuffCount < i2cTxCount)){
            else if((i2cBuffCount < i2cTxCount)){
                I2C_Master_Wait();
                SSPBUF = i2cTxBuff[i2cBuffCount++];
            }
//            else if((!SSPCON2bits.ACKSTAT)&&(i2cBuffCount == i2cTxCount)){
            else if((i2cBuffCount == i2cTxCount)){
//                PEN = 1; // set stop enable bit
                I2C_Master_Stop();
                i2cTxCount=0;
                i2cBuffCount=0;                
            }
//            if (SSPSTATbits.P) {
//                i2cTxCount=0;
//                i2cBuffCount=0;
//            }
        }
        else if(i2cRxCount){
//           if (SSPSTATbits.S) {
            if(i2cBuffCount == 0){ 
                I2C_Master_Wait();
                SSPBUF = i2cTxBuff[i2cBuffCount++];        
            }
//           else if((!SSPCON2bits.ACKSTAT)&&(i2cBuffCount == 1)){
           else if((i2cBuffCount == 1)){
               I2C_Master_Wait();
                SSPBUF = i2cTxBuff[i2cBuffCount++];
            }            
//           else if((!SSPCON2bits.ACKSTAT)&&(i2cBuffCount == 2)){
           else if((i2cBuffCount == 2)){
                I2C_Master_RepeatedStart();
                I2C_Master_Wait();
                SSPBUF = i2cTxBuff[i2cBuffCount++];
            }
//           else if((SSPSTATbits.BF) && (i2cBuffCount >=3)){
           else if((i2cBuffCount >=3)){  
               I2C_Master_Wait();
               RCEN = 1;
               I2C_Master_Wait();
               i2cRxBuff[i2cBuffCount-3] = SSPBUF;
               i2cBuffCount++;
               I2C_Master_Wait();
               if(i2cBuffCount == i2cRxCount){
                   ACKDT = 1;
                   ACKEN = 1;
//                   PEN = 1; // set stop enable bit
                    I2C_Master_Stop();
                    i2cRdBuffsize = i2cRxCount-3;
                    i2cRxCount=0;
                    i2cBuffCount=0;  
               } else {
                   ACKDT = 0;
                   ACKEN = 1;
                   RCEN = 1;
               }
           }
        }
        PIR1bits.SSPIF = 0; // Clear MSSP interrupt flag
    }
}
#endif 

void enable_interrupts(void){
    INTCONbits.PEIE = 1; // PEIE/GIEL: Peripheral Interrupt Enable bit
    INTCONbits.GIE = 1; // GIE/GIEH: Global Interrupt Enable bit    
}

void i2c_init (void){
    IIC_SCL_MODE = INPUT;
    IIC_SDA_MODE = INPUT;
    IIC_SCL_PIN = HIGH;
    IIC_SDA_PIN = HIGH;
//    SSPADD = DS1307_SLAVE_ADD;
    SSPADD = (_XTAL_FREQ/(4*IIC_CLK_FREQ))-1;
//    SSPCON = 0x36; //I2C Slave mode, 7-bit address
    SSPCON = 0x38; //I2C Master mode
    SSPSTAT = 0x00;
    SSPCON2 = 0x01;//SEN: Start Condition Enable
#ifdef I2C_INTERRUPT_EN
    i2cBuffCount=0;
    i2cTxCount = 0;
    i2cRxCount = 0;
    i2cRdBuffsize=0;
    PIR1bits.SSPIF = 0; // Clear MSSP interrupt request flag
    PIE1bits.SSPIE = 1; // Enable MSSP interrupt enable bit
    enable_interrupts();
#endif
}
void I2C_Master_Wait(void)
{
  while ((SSPSTAT & 0x04) || (SSPCON2 & 0x1F));
}

void I2C_Master_Start(void)
{
  I2C_Master_Wait();
  SEN = 1;
}

void I2C_Master_RepeatedStart(void)
{
  I2C_Master_Wait();
  RSEN = 1;
}

void I2C_Master_Stop(void)
{
  I2C_Master_Wait();
  PEN = 1;
}

void I2C_Master_Write(unsigned d)
{
  I2C_Master_Wait();
  SSPBUF = d;
}

unsigned short I2C_Master_Read(unsigned short a)
{
  unsigned short temp;
  I2C_Master_Wait();
  RCEN = 1;
  I2C_Master_Wait();
  temp = SSPBUF;
  I2C_Master_Wait();
  ACKDT = (a)?0:1;
  ACKEN = 1;
  return temp;
}

/*
void high_priority interrupt high_isr (void)
{
    ubyte ssp_Buf;
    
    if (PIR1bits.SSPIF) {        
        if (!SSPSTATbits.D_nA) {
            i2c_byte_count = 0;
            if (SSPSTATbits.BF) {
                ssp_Buf = SSPBUF; // Clear BF
            }
          
            if (SSPSTATbits.R_nW) { 
                SSPCONbits.WCOL = 0;
                SSPBUF = i2c_reg_map[i2c_reg_addr++];
            }             
        } else {
            i2c_byte_count++;
            if (SSPSTATbits.BF) {
                ssp_Buf = SSPBUF; // Clear BF
            }
            if (SSPSTATbits.R_nW) {

                // Multi-byte read - advance to next address
                SSPCONbits.WCOL = 0;
                SSPBUF = i2c_reg_map[i2c_reg_addr++];
               
            } else { 

                if (i2c_byte_count == 1) {
                    // First write byte is register address
                    i2c_reg_addr = ssp_Buf;

                } else {
                    // Write to register address - auto advance
                    // to allow multiple bytes to be written
                    i2c_reg_map[i2c_reg_addr++] = ssp_Buf;
                }
            }
        }
        // Limit address to size of register map
        i2c_reg_addr %= sizeof(i2c_reg_map);
        
        // Finally
        PIR1bits.SSPIF = 0; // Clear MSSP interrupt flag
        SSPCONbits.CKP = 1; // Release clock 
    } 
} 
 */

void recv_data(ubyte slave_add, ubyte sub_add, ubyte byte_cnt, ubyte *recv_buf){
#ifndef I2C_INTERRUPT_EN
    ubyte i;   
    I2C_Master_Start();         //Start condition
    I2C_Master_Write(slave_add);     //7 bit address + Write
    if(!(SSPCON2 & 0x40)){ // check for ack from slave
        I2C_Master_Write(sub_add); 
        if(!(SSPCON2 & 0x40)){ // check for ack from slave
            I2C_Master_RepeatedStart();
            I2C_Master_Write(slave_add|1);     //7 bit address + Read
            if(!(SSPCON2 & 0x40)){ // check for ack from slave
                for(i=0;i<byte_cnt;i++){
                    recv_buf[i]=I2C_Master_Read(byte_cnt-(i+1));
                }
            }
        }
    }
    I2C_Master_Stop();          //Stop condition    
#else
    if((!i2cRdBuffsize)&&(!i2cRxCount)){
        i2cBuffCount=0;
        i2cTxCount = 0;
        i2cRxCount = 0;
        i2cTxBuff[i2cRxCount++] = slave_add;
        i2cTxBuff[i2cRxCount++] = sub_add;
        i2cTxBuff[i2cRxCount++] = slave_add|1;
        i2cRxCount += byte_cnt;
        I2C_Master_Start();         //Start condition
        while (!i2cRdBuffsize);        
    } 

    if ((i2cRdBuffsize)&&(!i2cRxCount)){
        while(i2cRdBuffsize){
            i2cRdBuffsize--;
            *(recv_buf+i2cRdBuffsize) = i2cRxBuff[i2cRdBuffsize];            
        }        
    }
#endif
}
void send_data(ubyte slave_add, ubyte sub_add, ubyte bytes, ubyte *data_in){
#ifndef I2C_INTERRUPT_EN
    I2C_Master_Start();         //Start condition
    I2C_Master_Write(slave_add);     //7 bit address + Write
    if(!(SSPCON2 & 0x40)){ // check for ack from slave
        I2C_Master_Write(sub_add);
        if(!(SSPCON2 & 0x40)){ // check for ack from slave
            for(bytes;bytes>0;bytes--){        
                I2C_Master_Write(*data_in++);    //Write data  
                if(SSPCON2 & 0x40){
                    break;
                }
            }  
        }
    }
    I2C_Master_Stop();          //Stop condition  
#else
    i2cBuffCount=0;
    i2cTxCount = 0;
    i2cTxBuff[i2cTxCount++] = slave_add;
    i2cTxBuff[i2cTxCount++] = sub_add;
    for(bytes;bytes>0;bytes--){
        i2cTxBuff[i2cTxCount++] = *data_in++;
    }
    i2cBuffCount = 0;
    I2C_Master_Start();         //Start condition
    while(i2cTxCount);
#endif    
}


