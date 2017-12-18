This project displays time in HH:MM format.
uC used is of 8bit and is from pic16 family (pic16f886).
RTC used is DS1307.
Communication with RTC is by bit bang implementation of IIC protocol.
7 seg led display used is Common Cathode.
Seconds indication is done by toggling LED which is connected to SWQ of RTC.
Two switches are used to configure hours and minutes. 

