EESchema Schematic File Version 2
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
LIBS:special
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
Sheet 1 4
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
L CRYSTAL X?
U 1 1 5A1D0210
P 5475 2600
F 0 "X?" H 5475 2750 50  0000 C CNN
F 1 "20MHz" H 5475 2450 50  0000 C CNN
F 2 "" H 5475 2600 60  0000 C CNN
F 3 "" H 5475 2600 60  0000 C CNN
	1    5475 2600
	0    1    1    0   
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5A1D02C5
P 1075 4875
F 0 "SW?" H 1225 4985 50  0000 C CNN
F 1 "SW_PUSH" H 1075 4795 50  0000 C CNN
F 2 "" H 1075 4875 60  0000 C CNN
F 3 "" H 1075 4875 60  0000 C CNN
	1    1075 4875
	0    -1   -1   0   
$EndComp
$Sheet
S 4000 6250 1500 1150
U 5A1D2E5E
F0 "regulator" 60
F1 "pwrRegulator.sch" 60
F2 "5V_DC" I L 4000 6450 60 
F3 "Gnd" I L 4000 6850 60 
$EndSheet
Text GLabel 1150 1650 0    60   Input ~ 0
5VDC
$Sheet
S 4000 5200 1500 800 
U 5A1FE3AD
F0 "rtc" 60
F1 "ds1307.sch" 60
F2 "Gnd" I L 4000 5750 60 
F3 "5V_DC" I L 4000 5400 60 
$EndSheet
$Sheet
S 8550 3650 1200 2500
U 5A200BD2
F0 "TimeDisplay" 60
F1 "7segLed_time.sch" 60
F2 "5V_DC" I L 8550 3800 60 
F3 "Gnd" I L 8550 4000 60 
F4 "SEG_A" I L 8550 4250 60 
F5 "SEG_B" I L 8550 4400 60 
F6 "SEG_C" I L 8550 4550 60 
F7 "SEG_D" I L 8550 4700 60 
F8 "SEG_E" I L 8550 4850 60 
F9 "SEG_F" I L 8550 5000 60 
F10 "SEG_G" I L 8550 5150 60 
F11 "CC_Hrs_H" I L 8550 5350 60 
F12 "CC_Hrs_L" I L 8550 5500 60 
F13 "CC_Min_H" I L 8550 5650 60 
F14 "CC_Min_L" I L 8550 5800 60 
F15 "Sec_Blink" I L 8550 5950 60 
$EndSheet
$Comp
L PIC16F886-I/P U?
U 1 1 5A2142E7
P 3300 2725
F 0 "U?" H 3850 3825 50  0000 L CNN
F 1 "PIC16F886-I/P" H 3850 3725 50  0000 L CNN
F 2 "" H 3300 2725 50  0001 C CIN
F 3 "" H 3300 2525 50  0001 C CNN
	1    3300 2725
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5A21469A
P 1825 1675
F 0 "R?" V 1905 1675 50  0000 C CNN
F 1 "10K" V 1832 1676 50  0000 C CNN
F 2 "" V 1755 1675 30  0000 C CNN
F 3 "" H 1825 1675 30  0000 C CNN
	1    1825 1675
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5A2148EA
P 1225 2225
F 0 "SW?" H 1375 2335 50  0000 C CNN
F 1 "SW_PUSH" H 1225 2145 50  0000 C CNN
F 2 "" H 1225 2225 60  0000 C CNN
F 3 "" H 1225 2225 60  0000 C CNN
	1    1225 2225
	0    -1   -1   0   
$EndComp
$Comp
L C C?
U 1 1 5A214BFF
P 5875 2300
F 0 "C?" H 5925 2400 50  0000 L CNN
F 1 "22pF" H 5925 2200 50  0000 L CNN
F 2 "" H 5913 2150 30  0000 C CNN
F 3 "" H 5875 2300 60  0000 C CNN
	1    5875 2300
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5A214E32
P 5800 2900
F 0 "C?" H 5850 3000 50  0000 L CNN
F 1 "22pF" H 5850 2800 50  0000 L CNN
F 2 "" H 5838 2750 30  0000 C CNN
F 3 "" H 5800 2900 60  0000 C CNN
	1    5800 2900
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 5A215106
P 1675 2125
F 0 "C?" H 1725 2225 50  0000 L CNN
F 1 "100nF" H 1725 2025 50  0000 L CNN
F 2 "" H 1713 1975 30  0000 C CNN
F 3 "" H 1675 2125 60  0000 C CNN
	1    1675 2125
	-1   0    0    1   
$EndComp
$Comp
L C C?
U 1 1 5A215217
P 3675 1475
F 0 "C?" H 3725 1575 50  0000 L CNN
F 1 "100nF" H 3725 1375 50  0000 L CNN
F 2 "" H 3713 1325 30  0000 C CNN
F 3 "" H 3675 1475 60  0000 C CNN
	1    3675 1475
	0    -1   -1   0   
$EndComp
$Comp
L +5V #PWR?
U 1 1 5A2154CE
P 3300 1375
F 0 "#PWR?" H 3300 1225 60  0001 C CNN
F 1 "+5V" H 3300 1515 60  0000 C CNN
F 2 "" H 3300 1375 60  0000 C CNN
F 3 "" H 3300 1375 60  0000 C CNN
	1    3300 1375
	1    0    0    -1  
$EndComp
Wire Wire Line
	3300 1625 3300 1375
Wire Wire Line
	3300 1475 3475 1475
Connection ~ 3300 1475
Wire Wire Line
	3875 1475 3975 1475
Wire Wire Line
	3975 1475 3975 1500
$Comp
L GND #PWR?
U 1 1 5A2154E2
P 3350 3975
F 0 "#PWR?" H 3350 3725 60  0001 C CNN
F 1 "GND" H 3350 3825 60  0000 C CNN
F 2 "" H 3350 3975 60  0000 C CNN
F 3 "" H 3350 3975 60  0000 C CNN
	1    3350 3975
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5A2168ED
P 3975 1500
F 0 "#PWR?" H 3975 1250 60  0001 C CNN
F 1 "GND" H 3975 1350 60  0000 C CNN
F 2 "" H 3975 1500 60  0000 C CNN
F 3 "" H 3975 1500 60  0000 C CNN
	1    3975 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 3975 3350 3825
Wire Wire Line
	3300 3825 3400 3825
Connection ~ 3350 3825
Wire Wire Line
	1225 1925 2000 1925
Connection ~ 1825 1925
Connection ~ 1675 1925
Wire Wire Line
	1225 2525 1675 2525
Wire Wire Line
	1675 2525 1675 2325
Wire Wire Line
	1675 2325 1800 2325
Wire Wire Line
	1800 2325 1800 2400
Wire Wire Line
	2000 1925 2000 1650
Wire Wire Line
	2000 1650 2125 1650
$Comp
L GND #PWR?
U 1 1 5A2176DE
P 1800 2400
F 0 "#PWR?" H 1800 2150 60  0001 C CNN
F 1 "GND" H 1800 2250 60  0000 C CNN
F 2 "" H 1800 2400 60  0000 C CNN
F 3 "" H 1800 2400 60  0000 C CNN
	1    1800 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 2625 5250 2625
Wire Wire Line
	5250 2625 5250 2900
Wire Wire Line
	5250 2900 5600 2900
Connection ~ 5475 2900
Wire Wire Line
	5275 2300 5675 2300
Wire Wire Line
	6075 2300 6075 3025
Wire Wire Line
	6075 2900 6000 2900
Connection ~ 6075 2900
Wire Wire Line
	4600 2525 5275 2525
Wire Wire Line
	5275 2525 5275 2300
Connection ~ 5475 2300
$Comp
L GND #PWR?
U 1 1 5A21865E
P 6075 3025
F 0 "#PWR?" H 6075 2775 60  0001 C CNN
F 1 "GND" H 6075 2875 60  0000 C CNN
F 2 "" H 6075 3025 60  0000 C CNN
F 3 "" H 6075 3025 60  0000 C CNN
	1    6075 3025
	1    0    0    -1  
$EndComp
Wire Wire Line
	1825 1425 1825 1350
Wire Wire Line
	1825 1350 2000 1350
$Comp
L +5V #PWR?
U 1 1 5A2189FE
P 2000 1350
F 0 "#PWR?" H 2000 1200 60  0001 C CNN
F 1 "+5V" H 2000 1490 60  0000 C CNN
F 2 "" H 2000 1350 60  0000 C CNN
F 3 "" H 2000 1350 60  0000 C CNN
	1    2000 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 3425 4875 3425
Wire Wire Line
	4600 3525 4900 3525
Text Label 4875 3425 0    60   ~ 0
ICSP_CLK
Text Label 4900 3525 0    60   ~ 0
ICSP_DAT
Text Label 2125 1650 0    60   ~ 0
MCLR
$Comp
L R R?
U 1 1 5A219BA4
P 1075 3125
F 0 "R?" V 1025 2900 50  0000 C CNN
F 1 "10K" V 1082 3126 50  0000 C CNN
F 2 "" V 1005 3125 30  0000 C CNN
F 3 "" H 1075 3125 30  0000 C CNN
	1    1075 3125
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR?
U 1 1 5A21A0EC
P 725 3025
F 0 "#PWR?" H 725 2875 60  0001 C CNN
F 1 "+5V" H 725 3165 60  0000 C CNN
F 2 "" H 725 3025 60  0000 C CNN
F 3 "" H 725 3025 60  0000 C CNN
	1    725  3025
	1    0    0    -1  
$EndComp
Text Label 1400 3125 0    60   ~ 0
I2C_SCL
Text Label 1425 3250 0    60   ~ 0
I2C_SDA
$Comp
L R R?
U 1 1 5A21B503
P 1075 3250
F 0 "R?" V 1025 3025 50  0000 C CNN
F 1 "10K" V 1082 3251 50  0000 C CNN
F 2 "" V 1005 3250 30  0000 C CNN
F 3 "" H 1075 3250 30  0000 C CNN
	1    1075 3250
	0    1    1    0   
$EndComp
$Comp
L SW_PUSH SW?
U 1 1 5A21B6C7
P 1500 4875
F 0 "SW?" H 1650 4985 50  0000 C CNN
F 1 "SW_PUSH" H 1500 4795 50  0000 C CNN
F 2 "" H 1500 4875 60  0000 C CNN
F 3 "" H 1500 4875 60  0000 C CNN
	1    1500 4875
	0    -1   -1   0   
$EndComp
$Comp
L R R?
U 1 1 5A21B788
P 1075 4200
F 0 "R?" V 1025 3975 50  0000 C CNN
F 1 "10K" V 1082 4201 50  0000 C CNN
F 2 "" V 1005 4200 30  0000 C CNN
F 3 "" H 1075 4200 30  0000 C CNN
	1    1075 4200
	-1   0    0    1   
$EndComp
$Comp
L R R?
U 1 1 5A21B92C
P 1500 4200
F 0 "R?" V 1450 3975 50  0000 C CNN
F 1 "10K" V 1507 4201 50  0000 C CNN
F 2 "" V 1430 4200 30  0000 C CNN
F 3 "" H 1500 4200 30  0000 C CNN
	1    1500 4200
	-1   0    0    1   
$EndComp
Wire Wire Line
	1325 3125 2000 3125
Wire Wire Line
	1325 3250 2000 3250
Wire Wire Line
	2000 3250 2000 3225
Wire Wire Line
	750  3250 825  3250
Wire Wire Line
	750  3025 750  3250
Wire Wire Line
	750  3125 825  3125
Wire Wire Line
	750  3025 725  3025
Connection ~ 750  3125
$Comp
L +5V #PWR?
U 1 1 5A21BD55
P 1325 3850
F 0 "#PWR?" H 1325 3700 60  0001 C CNN
F 1 "+5V" H 1325 3990 60  0000 C CNN
F 2 "" H 1325 3850 60  0000 C CNN
F 3 "" H 1325 3850 60  0000 C CNN
	1    1325 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1075 3950 1500 3950
Wire Wire Line
	1325 3950 1325 3850
Connection ~ 1325 3950
Wire Wire Line
	1075 4575 1075 4450
Wire Wire Line
	1500 4450 1500 4575
Wire Wire Line
	1075 5175 1500 5175
Wire Wire Line
	1250 5175 1250 5275
Connection ~ 1250 5175
$Comp
L GND #PWR?
U 1 1 5A21C248
P 1250 5275
F 0 "#PWR?" H 1250 5025 60  0001 C CNN
F 1 "GND" H 1250 5125 60  0000 C CNN
F 2 "" H 1250 5275 60  0000 C CNN
F 3 "" H 1250 5275 60  0000 C CNN
	1    1250 5275
	1    0    0    -1  
$EndComp
Wire Wire Line
	1500 4500 1625 4500
Connection ~ 1500 4500
Wire Wire Line
	1075 4500 1225 4500
Connection ~ 1075 4500
Wire Wire Line
	2000 2925 1775 2925
Wire Wire Line
	2000 3025 1775 3025
Text Label 1225 4500 1    60   ~ 0
Hrs_sw
Text Label 1625 4500 1    60   ~ 0
Min_sw
Text Label 1775 3025 2    60   ~ 0
Hrs_sw
Text Label 1775 2925 2    60   ~ 0
Min_sw
$EndSCHEMATC
