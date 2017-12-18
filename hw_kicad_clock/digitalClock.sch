EESchema Schematic File Version 2
LIBS:digitalClock-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:microchip_pic16mcu
LIBS:digitalClock-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 7050 3850 1500 800 
U 5A1FE3AD
F0 "rtc" 60
F1 "ds1307.sch" 60
F2 "I2C_SCL" I R 8550 4050 60 
F3 "I2C_SDA" I R 8550 4250 60 
F4 "SQW_OP" I L 7050 4500 60 
F5 "GND" I R 8550 4450 60 
F6 "5v_DC" I R 8550 4600 60 
$EndSheet
$Sheet
S 6350 700  1200 2500
U 5A200BD2
F0 "TimeDisplay" 60
F1 "7segLed_time.sch" 60
F2 "SEG_A" I R 7550 1400 60 
F3 "SEG_B" I R 7550 1550 60 
F4 "SEG_C" I R 7550 1700 60 
F5 "SEG_D" I R 7550 1850 60 
F6 "SEG_E" I R 7550 2000 60 
F7 "SEG_F" I R 7550 2150 60 
F8 "SEG_G" I R 7550 2300 60 
F9 "CC_Hrs_H" I R 7550 2950 60 
F10 "CC_Hrs_L" I R 7550 2800 60 
F11 "CC_Min_H" I R 7550 2650 60 
F12 "CC_Min_L" I R 7550 2500 60 
F13 "Sec_Blink" I L 6350 3000 60 
F14 "5vDC" I L 6350 950 60 
F15 "GND" I L 6350 1300 60 
$EndSheet
$Sheet
S 8300 700  1250 2550
U 5A262DA9
F0 "pic16f886_clock" 60
F1 "pic16f886_clock.sch" 60
F2 "SEG_A" I L 8300 1400 60 
F3 "SEG_B" I L 8300 1550 60 
F4 "SEG_C" I L 8300 1700 60 
F5 "SEG_D" I L 8300 1850 60 
F6 "SEG_E" I L 8300 2000 60 
F7 "SEG_F" I L 8300 2150 60 
F8 "SEG_G" I L 8300 2300 60 
F9 "CC_MIN_L" I L 8300 2500 60 
F10 "CC_MIN_H" I L 8300 2650 60 
F11 "CC_HRS_L" I L 8300 2800 60 
F12 "CC_HRS_H" I L 8300 2950 60 
F13 "I2C_SCL" I R 9550 2900 60 
F14 "I2C_SDA" I R 9550 2700 60 
F15 "5v_DC" I R 9550 950 60 
F16 "GND" I R 9550 1250 60 
$EndSheet
Wire Wire Line
	7550 1400 8300 1400
Wire Wire Line
	7550 1550 8300 1550
Wire Wire Line
	7550 1700 8300 1700
Wire Wire Line
	7550 1850 8300 1850
Wire Wire Line
	7550 2000 8300 2000
Wire Wire Line
	7550 2150 8300 2150
Wire Wire Line
	7550 2300 8300 2300
Wire Wire Line
	7550 2500 8300 2500
Wire Wire Line
	7550 2650 8300 2650
Wire Wire Line
	7550 2800 8300 2800
Wire Wire Line
	7550 2950 8300 2950
Wire Wire Line
	9550 2900 9650 2900
Wire Wire Line
	9650 2900 9650 4050
Wire Wire Line
	9650 4050 8550 4050
Wire Wire Line
	8550 4250 9800 4250
Wire Wire Line
	9800 4250 9800 2700
Wire Wire Line
	9800 2700 9550 2700
Wire Wire Line
	6350 3000 6150 3000
Wire Wire Line
	6150 3000 6150 4500
Wire Wire Line
	6150 4500 7050 4500
$Sheet
S 3050 950  1500 1150
U 5A1D2E5E
F0 "regulator" 60
F1 "pwrRegulator.sch" 60
F2 "5v_DC" I R 4550 1200 60 
F3 "GND" I R 4550 1500 60 
$EndSheet
Wire Wire Line
	6350 950  6100 950 
Wire Wire Line
	6350 1300 6050 1300
Wire Wire Line
	8550 4450 8800 4450
Wire Wire Line
	8550 4600 8800 4600
Text Label 8800 4450 0    60   ~ 0
gnd
Text Label 8800 4600 0    60   ~ 0
5vdc
Text Label 6100 950  2    60   ~ 0
5vdc
Text Label 6050 1300 2    60   ~ 0
gnd
Wire Wire Line
	4550 1200 4750 1200
Wire Wire Line
	4550 1500 4750 1500
Text Label 4750 1200 0    60   ~ 0
5vdc
Text Label 4750 1500 0    60   ~ 0
gnd
Text Label 9850 950  0    60   ~ 0
5vdc
Wire Wire Line
	9550 950  9850 950 
Wire Wire Line
	9550 1250 9900 1250
Text Label 9900 1250 0    60   ~ 0
gnd
$EndSCHEMATC
