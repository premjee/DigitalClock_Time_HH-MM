This project displays time in HH:MM format.
uC used is of 8bit and is from pic16 family (pic16f886).
RTC used is DS1307.
Communication with RTC is by differnt methods
     1. by bit bang implementation of IIC protocol. (uses i2c.c & i2c.h).
     2. by polling method  - configuring IIC peripheral registers and poling the status registers. (uses i2c_peripheral.c & i2c_peripheral.h)
     3. by interrupt method - configuring IIC peripheral registers and enabling interrupt. (uses i2c_peripheral.c & i2c_peripheral.h)
7 seg led display used is Common Cathode.
Seconds indication is done by toggling LED which is connected to SWQ of RTC.
Two switches are used to configure hours and minutes. 

