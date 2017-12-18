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
Sheet 3 5
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
L LED-RESCUE-digitalClock D2
U 1 1 5A200FDB
P 5800 2650
F 0 "D2" H 5800 2750 50  0000 C CNN
F 1 "LED" H 5800 2550 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 5800 2650 60  0001 C CNN
F 3 "" H 5800 2650 60  0000 C CNN
	1    5800 2650
	1    0    0    -1  
$EndComp
$Comp
L 7SEGM S1
U 1 1 5A200FE2
P 2350 2400
F 0 "S1" H 2350 3050 50  0000 C CNN
F 1 "7SEGM" H 2350 1750 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_1inch" H 2350 2400 60  0001 C CNN
F 3 "" H 2350 2400 60  0000 C CNN
	1    2350 2400
	1    0    0    -1  
$EndComp
$Comp
L LED-RESCUE-digitalClock D1
U 1 1 5A200FE9
P 5800 2200
F 0 "D1" H 5800 2300 50  0000 C CNN
F 1 "LED" H 5800 2100 50  0000 C CNN
F 2 "LED_THT:LED_D3.0mm" H 5800 2200 60  0001 C CNN
F 3 "" H 5800 2200 60  0000 C CNN
	1    5800 2200
	1    0    0    -1  
$EndComp
$Comp
L R-RESCUE-digitalClock R2
U 1 1 5A200FF0
P 5600 1700
F 0 "R2" V 5680 1700 50  0000 C CNN
F 1 "10K" V 5607 1701 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 5530 1700 30  0001 C CNN
F 3 "" H 5600 1700 30  0000 C CNN
	1    5600 1700
	1    0    0    -1  
$EndComp
$Comp
L BC547 Q3
U 1 1 5A200FF7
P 5900 3200
F 0 "Q3" H 5900 3051 40  0000 R CNN
F 1 "BC547" H 5900 3350 40  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Narrow_Oval" H 5800 3302 29  0001 C CNN
F 3 "" H 5900 3200 60  0000 C CNN
	1    5900 3200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5600 1450 5100 1450
Wire Wire Line
	5600 1950 5600 2650
Connection ~ 5600 2200
Wire Wire Line
	6000 2200 6000 3000
Connection ~ 6000 2650
Wire Wire Line
	6000 3600 6000 3400
Wire Wire Line
	5700 3200 5400 3200
Wire Wire Line
	1600 2300 1450 2300
Wire Wire Line
	1600 2200 1450 2200
Wire Wire Line
	1600 2100 1450 2100
Wire Wire Line
	1600 2400 1450 2400
Wire Wire Line
	1600 2500 1450 2500
Wire Wire Line
	1600 2600 1450 2600
Wire Wire Line
	1600 2700 1450 2700
Text Label 1450 2100 2    60   ~ 0
Seg_A
Text Label 1450 2200 2    60   ~ 0
Seg_B
Text Label 1450 2300 2    60   ~ 0
Seg_C
Text Label 1450 2400 2    60   ~ 0
Seg_D
Text Label 1450 2500 2    60   ~ 0
Seg_E
Text Label 1450 2600 2    60   ~ 0
Seg_F
Text Label 1450 2700 2    60   ~ 0
Seg_G
NoConn ~ 1600 2800
Wire Wire Line
	1600 2000 1050 2000
Wire Wire Line
	1050 2000 1050 3100
$Comp
L BC547 Q1
U 1 1 5A201022
P 950 3300
F 0 "Q1" H 950 3151 40  0000 R CNN
F 1 "BC547" H 950 3450 40  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Narrow_Oval" H 850 3402 29  0001 C CNN
F 3 "" H 950 3300 60  0000 C CNN
	1    950  3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	1600 2900 1050 2900
Connection ~ 1050 2900
Wire Wire Line
	1050 3500 1050 3600
Wire Wire Line
	750  3300 650  3300
Text Label 650  3300 1    60   ~ 0
CK_Hrs_H
$Comp
L 7SEGM S2
U 1 1 5A201034
P 4800 2400
F 0 "S2" H 4800 3050 50  0000 C CNN
F 1 "7SEGM" H 4800 1750 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_1inch" H 4800 2400 60  0001 C CNN
F 3 "" H 4800 2400 60  0000 C CNN
	1    4800 2400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2300 3900 2300
Wire Wire Line
	4050 2200 3900 2200
Wire Wire Line
	4050 2100 3900 2100
Wire Wire Line
	4050 2400 3900 2400
Wire Wire Line
	4050 2500 3900 2500
Wire Wire Line
	4050 2600 3900 2600
Wire Wire Line
	4050 2700 3900 2700
Text Label 3900 2100 2    60   ~ 0
Seg_A
Text Label 3900 2200 2    60   ~ 0
Seg_B
Text Label 3900 2300 2    60   ~ 0
Seg_C
Text Label 3900 2400 2    60   ~ 0
Seg_D
Text Label 3900 2500 2    60   ~ 0
Seg_E
Text Label 3900 2600 2    60   ~ 0
Seg_F
Text Label 3900 2700 2    60   ~ 0
Seg_G
NoConn ~ 4050 2800
Wire Wire Line
	4050 2000 3500 2000
Wire Wire Line
	3500 2000 3500 3100
$Comp
L BC547 Q2
U 1 1 5A20104C
P 3400 3300
F 0 "Q2" H 3400 3151 40  0000 R CNN
F 1 "BC547" H 3400 3450 40  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Narrow_Oval" H 3300 3402 29  0001 C CNN
F 3 "" H 3400 3300 60  0000 C CNN
	1    3400 3300
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 2900 3500 2900
Connection ~ 3500 2900
Wire Wire Line
	3500 3500 3500 3600
Wire Wire Line
	3200 3300 3100 3300
Text Label 3100 3300 1    60   ~ 0
CK_Hrs_L
Text Label 5400 3200 0    60   ~ 0
Sec_LED
$Comp
L 7SEGM S3
U 1 1 5A20105F
P 7950 2250
F 0 "S3" H 7950 2900 50  0000 C CNN
F 1 "7SEGM" H 7950 1600 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_1inch" H 7950 2250 60  0001 C CNN
F 3 "" H 7950 2250 60  0000 C CNN
	1    7950 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2150 7050 2150
Wire Wire Line
	7200 2050 7050 2050
Wire Wire Line
	7200 1950 7050 1950
Wire Wire Line
	7200 2250 7050 2250
Wire Wire Line
	7200 2350 7050 2350
Wire Wire Line
	7200 2450 7050 2450
Wire Wire Line
	7200 2550 7050 2550
Text Label 7050 1950 2    60   ~ 0
Seg_A
Text Label 7050 2050 2    60   ~ 0
Seg_B
Text Label 7050 2150 2    60   ~ 0
Seg_C
Text Label 7050 2250 2    60   ~ 0
Seg_D
Text Label 7050 2350 2    60   ~ 0
Seg_E
Text Label 7050 2450 2    60   ~ 0
Seg_F
Text Label 7050 2550 2    60   ~ 0
Seg_G
NoConn ~ 7200 2650
Wire Wire Line
	7200 1850 6650 1850
Wire Wire Line
	6650 1850 6650 2950
$Comp
L BC547 Q4
U 1 1 5A201077
P 6550 3150
F 0 "Q4" H 6550 3001 40  0000 R CNN
F 1 "BC547" H 6550 3300 40  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Narrow_Oval" H 6450 3252 29  0001 C CNN
F 3 "" H 6550 3150 60  0000 C CNN
	1    6550 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2750 6650 2750
Connection ~ 6650 2750
Wire Wire Line
	6650 3600 6650 3350
Wire Wire Line
	6350 3150 6250 3150
Text Label 6250 3150 1    60   ~ 0
CK_Min_H
$Comp
L 7SEGM S4
U 1 1 5A201089
P 10400 2250
F 0 "S4" H 10400 2900 50  0000 C CNN
F 1 "7SEGM" H 10400 1600 50  0000 C CNN
F 2 "Display_7Segment:7SegmentLED_1inch" H 10400 2250 60  0001 C CNN
F 3 "" H 10400 2250 60  0000 C CNN
	1    10400 2250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 2150 9500 2150
Wire Wire Line
	9650 2050 9500 2050
Wire Wire Line
	9650 1950 9500 1950
Wire Wire Line
	9650 2250 9500 2250
Wire Wire Line
	9650 2350 9500 2350
Wire Wire Line
	9650 2450 9500 2450
Wire Wire Line
	9650 2550 9500 2550
Text Label 9500 1950 2    60   ~ 0
Seg_A
Text Label 9500 2050 2    60   ~ 0
Seg_B
Text Label 9500 2150 2    60   ~ 0
Seg_C
Text Label 9500 2250 2    60   ~ 0
Seg_D
Text Label 9500 2350 2    60   ~ 0
Seg_E
Text Label 9500 2450 2    60   ~ 0
Seg_F
Text Label 9500 2550 2    60   ~ 0
Seg_G
NoConn ~ 9650 2650
Wire Wire Line
	9650 1850 9100 1850
Wire Wire Line
	9100 1850 9100 2950
$Comp
L BC547 Q5
U 1 1 5A2010A1
P 9000 3150
F 0 "Q5" H 9000 3001 40  0000 R CNN
F 1 "BC547" H 9000 3300 40  0000 R CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline_Narrow_Oval" H 8900 3252 29  0001 C CNN
F 3 "" H 9000 3150 60  0000 C CNN
	1    9000 3150
	1    0    0    -1  
$EndComp
Wire Wire Line
	9650 2750 9100 2750
Connection ~ 9100 2750
Wire Wire Line
	9100 3600 9100 3350
Wire Wire Line
	8800 3150 8700 3150
Text Label 8700 3150 1    60   ~ 0
CK_Min_L
Wire Wire Line
	2000 4800 1850 4800
Wire Wire Line
	2000 4700 1850 4700
Wire Wire Line
	2000 4600 1850 4600
Wire Wire Line
	2000 4900 1850 4900
Wire Wire Line
	2000 5000 1850 5000
Wire Wire Line
	2000 5100 1850 5100
Wire Wire Line
	2000 5200 1850 5200
Text Label 1850 4600 2    60   ~ 0
Seg_A
Text Label 1850 4700 2    60   ~ 0
Seg_B
Text Label 1850 4800 2    60   ~ 0
Seg_C
Text Label 1850 4900 2    60   ~ 0
Seg_D
Text Label 1850 5000 2    60   ~ 0
Seg_E
Text Label 1850 5100 2    60   ~ 0
Seg_F
Text Label 1850 5200 2    60   ~ 0
Seg_G
Text Label 1850 5300 2    60   ~ 0
CK_Hrs_H
Text Label 1850 5450 2    60   ~ 0
CK_Hrs_L
Text Label 1850 5600 2    60   ~ 0
Sec_LED
Text Label 1850 5750 2    60   ~ 0
CK_Min_H
Text Label 1850 5900 2    60   ~ 0
CK_Min_L
Wire Wire Line
	1850 5300 2000 5300
Wire Wire Line
	1850 5450 2000 5450
Wire Wire Line
	1850 5600 2000 5600
Wire Wire Line
	1850 5750 2000 5750
Wire Wire Line
	1850 5900 2000 5900
Text HLabel 2000 4600 2    60   Input ~ 0
SEG_A
Text HLabel 2000 4700 2    60   Input ~ 0
SEG_B
Text HLabel 2000 4800 2    60   Input ~ 0
SEG_C
Text HLabel 2000 4900 2    60   Input ~ 0
SEG_D
Text HLabel 2000 5000 2    60   Input ~ 0
SEG_E
Text HLabel 2000 5100 2    60   Input ~ 0
SEG_F
Text HLabel 2000 5200 2    60   Input ~ 0
SEG_G
Text HLabel 2000 5300 2    60   Input ~ 0
CC_Hrs_H
Text HLabel 2000 5450 2    60   Input ~ 0
CC_Hrs_L
Text HLabel 2000 5750 2    60   Input ~ 0
CC_Min_H
Text HLabel 2000 5900 2    60   Input ~ 0
CC_Min_L
Text HLabel 2000 5600 2    60   Input ~ 0
Sec_Blink
Text HLabel 5100 1450 0    60   Input ~ 0
5vDC
Wire Wire Line
	1050 3600 9300 3600
Connection ~ 3500 3600
Connection ~ 6000 3600
Connection ~ 6650 3600
Connection ~ 9100 3600
Text HLabel 9300 3600 2    60   Input ~ 0
GND
$EndSCHEMATC
