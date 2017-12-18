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
Sheet 2 5
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L BATTERY BT1
U 1 1 5A1FE5A4
P 5250 3400
F 0 "BT1" H 5250 3600 50  0000 C CNN
F 1 "BATTERY" H 5250 3210 50  0000 C CNN
F 2 "Battery:BatteryHolder_CR2032H" H 5250 3400 60  0001 C CNN
F 3 "" H 5250 3400 60  0000 C CNN
	1    5250 3400
	1    0    0    -1  
$EndComp
$Comp
L DS1307+ U1
U 1 1 5A1FE5AB
P 4200 3100
F 0 "U1" H 4470 3650 60  0000 C CNN
F 1 "DS1307+" H 4500 2550 60  0000 C CNN
F 2 "Package_DIP:DIP-8_W7.62mm_LongPads" H 4200 3100 60  0001 C CNN
F 3 "" H 4200 3100 60  0000 C CNN
	1    4200 3100
	1    0    0    -1  
$EndComp
$Comp
L CRYSTAL X1
U 1 1 5A1FE5B2
P 2950 3550
F 0 "X1" H 2950 3700 50  0000 C CNN
F 1 "32.768 kHz" H 2950 3400 50  0000 C CNN
F 2 "Crystal:Crystal_DS26_D2.0mm_L6.0mm_Horizontal_1EP_style1" H 2950 3550 60  0001 C CNN
F 3 "" H 2950 3550 60  0000 C CNN
	1    2950 3550
	0    -1   -1   0   
$EndComp
$Comp
L R-RESCUE-digitalClock R1
U 1 1 5A1FE5B9
P 5050 2500
F 0 "R1" V 5130 2500 50  0000 C CNN
F 1 "10k" V 5057 2501 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4980 2500 30  0001 C CNN
F 3 "" H 5050 2500 30  0000 C CNN
	1    5050 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 3250 3600 3250
Wire Wire Line
	3600 3250 3600 3300
Wire Wire Line
	2950 3850 3600 3850
Wire Wire Line
	3600 3850 3600 3500
Wire Wire Line
	4800 3400 4950 3400
Wire Wire Line
	5650 3400 5650 3800
Wire Wire Line
	3100 3000 3600 3000
Wire Wire Line
	3600 2800 3100 2800
Wire Wire Line
	4800 2800 5300 2800
Wire Wire Line
	5050 2800 5050 2750
Connection ~ 5050 2800
Wire Wire Line
	4200 2500 4200 2350
Text Label 5300 2800 0    60   ~ 0
sqw
Text Label 3100 2800 0    60   ~ 0
scl
Text Label 3100 3000 0    60   ~ 0
sda
Wire Wire Line
	4200 3800 4200 3700
Wire Wire Line
	4200 2400 4450 2400
Wire Wire Line
	4450 2400 4450 2200
Wire Wire Line
	4450 2200 5050 2200
Wire Wire Line
	5050 2200 5050 2250
Wire Wire Line
	6900 2400 7250 2400
Wire Wire Line
	6900 2600 7250 2600
Wire Wire Line
	6900 2800 7250 2800
Text Label 6900 2400 2    60   ~ 0
scl
Text Label 6900 2600 2    60   ~ 0
sda
Text Label 6900 2800 2    60   ~ 0
sqw
Text HLabel 7250 2400 2    60   Input ~ 0
I2C_SCL
Text HLabel 7250 2600 2    60   Input ~ 0
I2C_SDA
Text HLabel 7250 2800 2    60   Input ~ 0
SQW_OP
Connection ~ 4200 2400
Wire Wire Line
	5550 3400 5650 3400
Text HLabel 4200 3800 0    60   Input ~ 0
GND
Text HLabel 4200 2350 1    60   Input ~ 0
5v_DC
Wire Wire Line
	5650 3800 4200 3800
$EndSCHEMATC
