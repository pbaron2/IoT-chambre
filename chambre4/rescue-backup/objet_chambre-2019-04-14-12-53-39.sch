EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
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
LIBS:wemos_mini
LIBS:sensors
LIBS:maxim
LIBS:diode
LIBS:ch34x
LIBS:ESP8266
LIBS:bosch
LIBS:objet_chambre-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
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
L WeMos_mini U7
U 1 1 5B6487B1
P 6600 1900
F 0 "U7" H 6600 2400 60  0000 C CNN
F 1 "WeMos_mini" H 6600 1400 60  0000 C CNN
F 2 "wemos_d1_mini:D1_mini_board" H 7150 1200 60  0001 C CNN
F 3 "" H 7150 1200 60  0000 C CNN
	1    6600 1900
	1    0    0    -1  
$EndComp
$Comp
L R_PHOTO R1
U 1 1 5B648CF7
P 1350 6900
F 0 "R1" H 1400 6950 50  0000 L CNN
F 1 "R_PHOTO" H 1400 6900 50  0000 L TNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02_Pitch2.54mm" V 1400 6650 50  0001 L CNN
F 3 "" H 1350 6850 50  0001 C CNN
	1    1350 6900
	1    0    0    -1  
$EndComp
$Comp
L OLED_SCREEN U8
U 1 1 5B649679
P 7900 5800
F 0 "U8" H 7550 5400 60  0000 C CNN
F 1 "OLED_SCREEN" H 7900 5500 60  0000 C CNN
F 2 "rtc:OLED_SCREEN_SSD1306" H 7900 5800 60  0001 C CNN
F 3 "" H 7900 5800 60  0001 C CNN
	1    7900 5800
	1    0    0    -1  
$EndComp
$Comp
L DS1307 U9
U 1 1 5B649A77
P 9350 5050
F 0 "U9" H 9100 4600 60  0000 C CNN
F 1 "DS1307" H 9200 5500 60  0000 C CNN
F 2 "rtc:DS1307" H 9300 5600 60  0001 C CNN
F 3 "" H 9300 5600 60  0001 C CNN
	1    9350 5050
	1    0    0    -1  
$EndComp
$Comp
L 4x7SEG U3
U 1 1 5B649B6B
P 3850 6550
F 0 "U3" H 3200 6300 60  0000 C CNN
F 1 "4x7SEG" H 3300 6800 60  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x04_Pitch2.54mm" H 3850 6550 60  0001 C CNN
F 3 "" H 3850 6550 60  0001 C CNN
	1    3850 6550
	1    0    0    -1  
$EndComp
$Comp
L AZ1117-3.3 U2
U 1 1 5B649BA0
P 2200 950
F 0 "U2" H 2050 1075 50  0000 C CNN
F 1 "AZ1117-3.3" H 2200 1075 50  0000 L CNN
F 2 "TO_SOT_Packages_SMD:SOT-223-3_TabPin2" H 2200 1200 50  0001 C CIN
F 3 "" H 2200 950 50  0001 C CNN
	1    2200 950 
	1    0    0    -1  
$EndComp
$Comp
L Buzzer BZ1
U 1 1 5B649F12
P 1150 4050
F 0 "BZ1" H 1300 4100 50  0000 L CNN
F 1 "Buzzer" H 1300 4000 50  0000 L CNN
F 2 "Buzzers_Beepers:Buzzer_12x9.5RM7.6" V 1125 4150 50  0001 C CNN
F 3 "" V 1125 4150 50  0001 C CNN
	1    1150 4050
	-1   0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 5B649F6B
P 4850 6150
F 0 "R4" V 4930 6150 50  0000 C CNN
F 1 "10k" V 4850 6150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4780 6150 50  0001 C CNN
F 3 "" H 4850 6150 50  0001 C CNN
	1    4850 6150
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 5B649FEE
P 5050 6150
F 0 "R5" V 5130 6150 50  0000 C CNN
F 1 "10k" V 5050 6150 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 4980 6150 50  0001 C CNN
F 3 "" H 5050 6150 50  0001 C CNN
	1    5050 6150
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 5B64A037
P 7450 4400
F 0 "R7" V 7530 4400 50  0000 C CNN
F 1 "10k" V 7450 4400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7380 4400 50  0001 C CNN
F 3 "" H 7450 4400 50  0001 C CNN
	1    7450 4400
	1    0    0    -1  
$EndComp
$Comp
L POT RV1
U 1 1 5B64A4AB
P 1350 4400
F 0 "RV1" V 1175 4400 50  0000 C CNN
F 1 "500" V 1250 4400 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Bourns_3296W" H 1350 4400 50  0001 C CNN
F 3 "" H 1350 4400 50  0001 C CNN
	1    1350 4400
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 5B64AA1E
P 7250 4400
F 0 "R6" V 7330 4400 50  0000 C CNN
F 1 "10k" V 7250 4400 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 7180 4400 50  0001 C CNN
F 3 "" H 7250 4400 50  0001 C CNN
	1    7250 4400
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR01
U 1 1 5B6595C9
P 1650 800
F 0 "#PWR01" H 1650 650 50  0001 C CNN
F 1 "+5V" H 1650 940 50  0000 C CNN
F 2 "" H 1650 800 50  0001 C CNN
F 3 "" H 1650 800 50  0001 C CNN
	1    1650 800 
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR02
U 1 1 5B659819
P 2750 800
F 0 "#PWR02" H 2750 650 50  0001 C CNN
F 1 "+3.3V" H 2750 940 50  0000 C CNN
F 2 "" H 2750 800 50  0001 C CNN
F 3 "" H 2750 800 50  0001 C CNN
	1    2750 800 
	1    0    0    -1  
$EndComp
$Comp
L POT RV2
U 1 1 5B65A90F
P 1350 6400
F 0 "RV2" V 1175 6400 50  0000 C CNN
F 1 "50k" V 1250 6400 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Trimmer_Bourns_3296W" H 1350 6400 50  0001 C CNN
F 3 "" H 1350 6400 50  0001 C CNN
	1    1350 6400
	1    0    0    -1  
$EndComp
$Comp
L Jumper_NC_Dual JP1
U 1 1 5B65AC6E
P 5550 6200
F 0 "JP1" H 5600 6100 50  0000 L CNN
F 1 "Jumper" H 5550 6300 50  0000 C BNN
F 2 "Pin_Headers:Pin_Header_Straight_1x03_Pitch2.54mm" H 5550 6200 50  0001 C CNN
F 3 "" H 5550 6200 50  0001 C CNN
	1    5550 6200
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR03
U 1 1 5B65AEDE
P 5050 5800
F 0 "#PWR03" H 5050 5650 50  0001 C CNN
F 1 "+3.3V" H 5050 5940 50  0000 C CNN
F 2 "" H 5050 5800 50  0001 C CNN
F 3 "" H 5050 5800 50  0001 C CNN
	1    5050 5800
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR04
U 1 1 5B65AF20
P 5850 5800
F 0 "#PWR04" H 5850 5650 50  0001 C CNN
F 1 "+5V" H 5850 5940 50  0000 C CNN
F 2 "" H 5850 5800 50  0001 C CNN
F 3 "" H 5850 5800 50  0001 C CNN
	1    5850 5800
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR05
U 1 1 5B65B07B
P 4850 6800
F 0 "#PWR05" H 4850 6600 50  0001 C CNN
F 1 "GNDPWR" H 4850 6670 50  0000 C CNN
F 2 "" H 4850 6750 50  0001 C CNN
F 3 "" H 4850 6750 50  0001 C CNN
	1    4850 6800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 6600 5550 6600
Wire Wire Line
	5550 6600 5550 6300
Wire Wire Line
	4750 6700 4850 6700
Wire Wire Line
	4850 6700 4850 6800
Wire Wire Line
	4750 6400 5950 6400
Wire Wire Line
	4850 6400 4850 6300
Wire Wire Line
	4750 6500 5950 6500
Wire Wire Line
	5050 6500 5050 6300
Wire Wire Line
	4850 6000 4850 5900
Wire Wire Line
	4850 5900 5250 5900
Wire Wire Line
	5050 5800 5050 6000
Connection ~ 5050 5900
Wire Wire Line
	5250 5900 5250 6200
Wire Wire Line
	5250 6200 5300 6200
Wire Wire Line
	5800 6200 5850 6200
Wire Wire Line
	5850 6200 5850 5800
$Comp
L +3.3V #PWR06
U 1 1 5B65B573
P 1350 6050
F 0 "#PWR06" H 1350 5900 50  0001 C CNN
F 1 "+3.3V" H 1350 6190 50  0000 C CNN
F 2 "" H 1350 6050 50  0001 C CNN
F 3 "" H 1350 6050 50  0001 C CNN
	1    1350 6050
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR07
U 1 1 5B65B662
P 1350 7250
F 0 "#PWR07" H 1350 7050 50  0001 C CNN
F 1 "GNDPWR" H 1350 7120 50  0000 C CNN
F 2 "" H 1350 7200 50  0001 C CNN
F 3 "" H 1350 7200 50  0001 C CNN
	1    1350 7250
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 7050 1350 7250
Wire Wire Line
	1350 6550 1350 6750
Wire Wire Line
	1350 6050 1350 6250
Wire Wire Line
	1500 6400 1550 6400
Wire Wire Line
	1550 6400 1550 6150
Wire Wire Line
	1550 6150 1350 6150
Connection ~ 1350 6150
$Comp
L GNDPWR #PWR011
U 1 1 5B65CB17
P 7500 5250
F 0 "#PWR011" H 7500 5050 50  0001 C CNN
F 1 "GNDPWR" H 7500 5120 50  0000 C CNN
F 2 "" H 7500 5200 50  0001 C CNN
F 3 "" H 7500 5200 50  0001 C CNN
	1    7500 5250
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR012
U 1 1 5B65CB59
P 8050 4250
F 0 "#PWR012" H 8050 4100 50  0001 C CNN
F 1 "+5V" H 8050 4390 50  0000 C CNN
F 2 "" H 8050 4250 50  0001 C CNN
F 3 "" H 8050 4250 50  0001 C CNN
	1    8050 4250
	1    0    0    -1  
$EndComp
$Comp
L +3.3V #PWR013
U 1 1 5B65CCC3
P 7450 4100
F 0 "#PWR013" H 7450 3950 50  0001 C CNN
F 1 "+3.3V" H 7450 4240 50  0000 C CNN
F 2 "" H 7450 4100 50  0001 C CNN
F 3 "" H 7450 4100 50  0001 C CNN
	1    7450 4100
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR014
U 1 1 5B65CD05
P 9300 4350
F 0 "#PWR014" H 9300 4150 50  0001 C CNN
F 1 "GNDPWR" H 9300 4220 50  0000 C CNN
F 2 "" H 9300 4300 50  0001 C CNN
F 3 "" H 9300 4300 50  0001 C CNN
	1    9300 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7000 4950 8850 4950
Wire Wire Line
	8050 4950 8050 5250
Wire Wire Line
	7950 5050 7950 5250
Wire Wire Line
	7000 5050 8850 5050
Wire Wire Line
	7250 5050 7250 4550
Connection ~ 7950 5050
Wire Wire Line
	7450 4950 7450 4550
Connection ~ 8050 4950
Wire Wire Line
	8850 4750 8800 4750
Wire Wire Line
	8800 4750 8800 4300
Wire Wire Line
	9300 4300 9300 4350
Wire Wire Line
	8050 4250 8050 4850
Wire Wire Line
	8050 4850 8850 4850
Wire Wire Line
	7250 4200 7850 4200
Wire Wire Line
	7250 4200 7250 4250
Wire Wire Line
	7450 4100 7450 4250
Wire Wire Line
	7850 4200 7850 5250
Connection ~ 7450 4200
Wire Wire Line
	7750 5250 7750 5150
Wire Wire Line
	7750 5150 7500 5150
Wire Wire Line
	7500 5150 7500 5250
NoConn ~ 8850 5150
NoConn ~ 9800 5250
NoConn ~ 9800 5350
Wire Wire Line
	9800 4850 9900 4850
Wire Wire Line
	9900 4850 9900 4300
Wire Wire Line
	9900 4300 8800 4300
Connection ~ 9300 4300
Wire Wire Line
	8700 4850 8700 4200
Wire Wire Line
	8700 4200 10000 4200
Wire Wire Line
	10000 4200 10000 4950
Wire Wire Line
	10000 4950 9800 4950
Connection ~ 8700 4850
Wire Wire Line
	8600 4950 8600 4100
Wire Wire Line
	8600 4100 10100 4100
Wire Wire Line
	10100 4100 10100 5050
Wire Wire Line
	10100 5050 9800 5050
Connection ~ 8600 4950
Wire Wire Line
	8500 5050 8500 4000
Wire Wire Line
	8500 4000 10200 4000
Wire Wire Line
	10200 4000 10200 5150
Wire Wire Line
	10200 5150 9800 5150
Connection ~ 8500 5050
NoConn ~ 9800 4750
$Comp
L +3.3V #PWR016
U 1 1 5B65EFF8
P 5650 4400
F 0 "#PWR016" H 5650 4250 50  0001 C CNN
F 1 "+3.3V" H 5650 4540 50  0000 C CNN
F 2 "" H 5650 4400 50  0001 C CNN
F 3 "" H 5650 4400 50  0001 C CNN
	1    5650 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4750 5650 4400
Text GLabel 7000 4950 0    60   BiDi ~ 0
SDA
Text GLabel 7000 5050 0    60   Input ~ 0
SCL
Connection ~ 7450 4950
Connection ~ 7250 5050
Text GLabel 5950 6400 2    60   Input ~ 0
CLK
Text GLabel 5950 6500 2    60   BiDi ~ 0
DIO
Connection ~ 5050 6500
Connection ~ 4850 6400
Text GLabel 1600 6650 2    60   Output ~ 0
PHOTORES
Wire Wire Line
	1600 6650 1350 6650
Connection ~ 1350 6650
Text GLabel 2250 4850 2    60   Input ~ 0
BUZZ
$Comp
L R R2
U 1 1 5B660DFA
P 1950 4850
F 0 "R2" V 2030 4850 50  0000 C CNN
F 1 "2.2k" V 1950 4850 50  0000 C CNN
F 2 "Resistors_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P15.24mm_Horizontal" V 1880 4850 50  0001 C CNN
F 3 "" H 1950 4850 50  0001 C CNN
	1    1950 4850
	0    1    1    0   
$EndComp
$Comp
L PN2222A Q1
U 1 1 5B660E47
P 1450 4850
F 0 "Q1" H 1650 4925 50  0000 L CNN
F 1 "PN2222A" H 1650 4850 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H 1650 4775 50  0001 L CIN
F 3 "" H 1450 4850 50  0001 L CNN
	1    1450 4850
	-1   0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR017
U 1 1 5B661135
P 1350 5150
F 0 "#PWR017" H 1350 4950 50  0001 C CNN
F 1 "GNDPWR" H 1350 5020 50  0000 C CNN
F 2 "" H 1350 5100 50  0001 C CNN
F 3 "" H 1350 5100 50  0001 C CNN
	1    1350 5150
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR018
U 1 1 5B66139E
P 1350 3850
F 0 "#PWR018" H 1350 3700 50  0001 C CNN
F 1 "+5V" H 1350 3990 50  0000 C CNN
F 2 "" H 1350 3850 50  0001 C CNN
F 3 "" H 1350 3850 50  0001 C CNN
	1    1350 3850
	1    0    0    -1  
$EndComp
Wire Wire Line
	1350 3850 1350 3950
Wire Wire Line
	1350 3950 1250 3950
Wire Wire Line
	1250 4150 1350 4150
Wire Wire Line
	1350 4150 1350 4250
Wire Wire Line
	1350 4550 1350 4650
Wire Wire Line
	1350 4600 1550 4600
Wire Wire Line
	1550 4600 1550 4400
Wire Wire Line
	1550 4400 1500 4400
Connection ~ 1350 4600
Wire Wire Line
	1350 5150 1350 5050
Wire Wire Line
	1650 4850 1800 4850
Wire Wire Line
	2100 4850 2250 4850
Text GLabel 7400 2150 2    60   Input ~ 0
PHOTORES
Text GLabel 7400 2050 2    60   BiDi ~ 0
DIO
Text GLabel 7400 1950 2    60   Output ~ 0
CLK
Text GLabel 4250 4950 2    60   Output ~ 0
SW1
Text GLabel 4800 4950 2    60   Output ~ 0
SW2
Text GLabel 5350 4950 2    60   Output ~ 0
SW3
Wire Wire Line
	5350 4950 5250 4950
Wire Wire Line
	4800 4950 4700 4950
Wire Wire Line
	4250 4950 4150 4950
Text GLabel 7400 1850 2    60   Input ~ 0
SW1
Text GLabel 7400 1750 2    60   Input ~ 0
SW2
Text GLabel 7400 1650 2    60   Input ~ 0
SW3
NoConn ~ 7100 2250
Text GLabel 5800 1950 0    60   BiDi ~ 0
SDA
Text GLabel 5800 2050 0    60   Output ~ 0
SCL
Text GLabel 5800 1850 0    60   BiDi ~ 0
DATA_DHT
Text GLabel 5800 1750 0    60   Output ~ 0
BUZZ
Wire Wire Line
	5800 1750 6100 1750
Wire Wire Line
	6100 1850 5800 1850
Wire Wire Line
	6100 1950 5800 1950
Wire Wire Line
	6100 2050 5800 2050
Wire Wire Line
	7100 1650 7400 1650
Wire Wire Line
	7100 1750 7400 1750
Wire Wire Line
	7100 1850 7400 1850
Wire Wire Line
	7100 1950 7400 1950
Wire Wire Line
	7100 2050 7400 2050
Wire Wire Line
	7100 2150 7400 2150
NoConn ~ 6100 2150
NoConn ~ 6100 2250
$Comp
L 1N4148 D1
U 1 1 5B664369
P 1600 4050
F 0 "D1" H 1600 4150 50  0000 C CNN
F 1 "1N4148" H 1600 3950 50  0000 C CNN
F 2 "Diodes_THT:D_DO-35_SOD27_P10.16mm_Horizontal" H 1600 3875 50  0001 C CNN
F 3 "" H 1600 4050 50  0001 C CNN
	1    1600 4050
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR019
U 1 1 5B664843
P 5250 900
F 0 "#PWR019" H 5250 750 50  0001 C CNN
F 1 "+5V" H 5250 1040 50  0000 C CNN
F 2 "" H 5250 900 50  0001 C CNN
F 3 "" H 5250 900 50  0001 C CNN
	1    5250 900 
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR020
U 1 1 5B664B5A
P 5050 1700
F 0 "#PWR020" H 5050 1500 50  0001 C CNN
F 1 "GNDPWR" H 5050 1570 50  0000 C CNN
F 2 "" H 5050 1650 50  0001 C CNN
F 3 "" H 5050 1650 50  0001 C CNN
	1    5050 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5050 1650 6100 1650
Wire Wire Line
	5050 1650 5050 1700
Wire Wire Line
	1600 4200 1350 4200
Connection ~ 1350 4200
Wire Wire Line
	1600 3900 1350 3900
Connection ~ 1350 3900
$Comp
L GNDPWR #PWR021
U 1 1 5B68BEDE
P 2200 1350
F 0 "#PWR021" H 2200 1150 50  0001 C CNN
F 1 "GNDPWR" H 2200 1220 50  0000 C CNN
F 2 "" H 2200 1300 50  0001 C CNN
F 3 "" H 2200 1300 50  0001 C CNN
	1    2200 1350
	1    0    0    -1  
$EndComp
Wire Wire Line
	1650 800  1650 1050
Wire Wire Line
	1400 950  1900 950 
Wire Wire Line
	2500 950  2750 950 
Wire Wire Line
	2750 800  2750 1050
Wire Wire Line
	2200 1250 2200 1350
NoConn ~ 7100 1550
$Comp
L Conn_01x01 J1
U 1 1 5B68C9FF
P 9350 1100
F 0 "J1" H 9350 1200 50  0000 C CNN
F 1 "Conn_01x01" H 9350 1000 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.5mm_Pad" H 9350 1100 50  0001 C CNN
F 3 "" H 9350 1100 50  0001 C CNN
	1    9350 1100
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J2
U 1 1 5B68CA5E
P 9350 1400
F 0 "J2" H 9350 1500 50  0000 C CNN
F 1 "Conn_01x01" H 9350 1300 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.5mm_Pad" H 9350 1400 50  0001 C CNN
F 3 "" H 9350 1400 50  0001 C CNN
	1    9350 1400
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J3
U 1 1 5B68CAA3
P 9350 1700
F 0 "J3" H 9350 1800 50  0000 C CNN
F 1 "Conn_01x01" H 9350 1600 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.5mm_Pad" H 9350 1700 50  0001 C CNN
F 3 "" H 9350 1700 50  0001 C CNN
	1    9350 1700
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x01 J4
U 1 1 5B68CB3F
P 9350 2000
F 0 "J4" H 9350 2100 50  0000 C CNN
F 1 "Conn_01x01" H 9350 1900 50  0000 C CNN
F 2 "Mounting_Holes:MountingHole_3.5mm_Pad" H 9350 2000 50  0001 C CNN
F 3 "" H 9350 2000 50  0001 C CNN
	1    9350 2000
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR022
U 1 1 5B68CB8A
P 9000 2200
F 0 "#PWR022" H 9000 2000 50  0001 C CNN
F 1 "GNDPWR" H 9000 2070 50  0000 C CNN
F 2 "" H 9000 2150 50  0001 C CNN
F 3 "" H 9000 2150 50  0001 C CNN
	1    9000 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 2000 9150 2000
Wire Wire Line
	9000 1100 9000 2200
Wire Wire Line
	9150 1100 9000 1100
Connection ~ 9000 2000
Wire Wire Line
	9150 1700 9000 1700
Connection ~ 9000 1700
Wire Wire Line
	9150 1400 9000 1400
Connection ~ 9000 1400
$Comp
L USB_OTG J5
U 1 1 5B6B301B
P 1100 1150
F 0 "J5" H 900 1600 50  0000 L CNN
F 1 "USB_OTG" H 900 1500 50  0000 L CNN
F 2 "Connectors:USB_Micro-B" H 1250 1100 50  0001 C CNN
F 3 "" H 1250 1100 50  0001 C CNN
	1    1100 1150
	1    0    0    -1  
$EndComp
NoConn ~ 1400 1150
NoConn ~ 1400 1250
NoConn ~ 1400 1350
$Comp
L GNDPWR #PWR023
U 1 1 5B6B3639
P 1100 1700
F 0 "#PWR023" H 1100 1500 50  0001 C CNN
F 1 "GNDPWR" H 1100 1570 50  0000 C CNN
F 2 "" H 1100 1650 50  0001 C CNN
F 3 "" H 1100 1650 50  0001 C CNN
	1    1100 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	1100 1550 1100 1700
Wire Wire Line
	1000 1600 1650 1600
Wire Wire Line
	1000 1600 1000 1550
Connection ~ 1100 1600
$Comp
L 1N4007 D2
U 1 1 5B6B3C3B
P 5500 1000
F 0 "D2" H 5500 1100 50  0000 C CNN
F 1 "1N4007" H 5500 900 50  0000 C CNN
F 2 "Diodes_THT:D_DO-41_SOD81_P10.16mm_Horizontal" H 5500 825 50  0001 C CNN
F 3 "" H 5500 1000 50  0001 C CNN
	1    5500 1000
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 900  5250 1000
Wire Wire Line
	5250 1000 5350 1000
Wire Wire Line
	6050 1000 6050 1550
Wire Wire Line
	6050 1550 6100 1550
Connection ~ 1650 950 
Wire Wire Line
	1650 1600 1650 1350
$Comp
L C C3
U 1 1 5B6B613A
P 5800 1250
F 0 "C3" H 5825 1350 50  0000 L CNN
F 1 "10nF" H 5825 1150 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 5838 1100 50  0001 C CNN
F 3 "" H 5800 1250 50  0001 C CNN
	1    5800 1250
	1    0    0    -1  
$EndComp
$Comp
L GNDPWR #PWR025
U 1 1 5B6B6273
P 5800 1450
F 0 "#PWR025" H 5800 1250 50  0001 C CNN
F 1 "GNDPWR" H 5800 1320 50  0000 C CNN
F 2 "" H 5800 1400 50  0001 C CNN
F 3 "" H 5800 1400 50  0001 C CNN
	1    5800 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1000 6050 1000
Wire Wire Line
	5800 1100 5800 1000
Connection ~ 5800 1000
Wire Wire Line
	5800 1450 5800 1400
$Comp
L C C1
U 1 1 5B6B508F
P 1650 1200
F 0 "C1" H 1675 1300 50  0000 L CNN
F 1 "10uF" H 1675 1100 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 1688 1050 50  0001 C CNN
F 3 "" H 1650 1200 50  0001 C CNN
	1    1650 1200
	1    0    0    -1  
$EndComp
$Comp
L CP C4
U 1 1 5B6B7963
P 2750 1200
F 0 "C4" H 2775 1300 50  0000 L CNN
F 1 "100uF" H 2775 1100 50  0000 L CNN
F 2 "Capacitors_THT:CP_Radial_D7.5mm_P2.50mm" H 2788 1050 50  0001 C CNN
F 3 "" H 2750 1200 50  0001 C CNN
	1    2750 1200
	1    0    0    -1  
$EndComp
Connection ~ 2750 950 
$Comp
L GNDPWR #PWR026
U 1 1 5B6B7AD3
P 2750 1450
F 0 "#PWR026" H 2750 1250 50  0001 C CNN
F 1 "GNDPWR" H 2750 1320 50  0000 C CNN
F 2 "" H 2750 1400 50  0001 C CNN
F 3 "" H 2750 1400 50  0001 C CNN
	1    2750 1450
	1    0    0    -1  
$EndComp
Wire Wire Line
	2750 1450 2750 1350
Entry Wire Line
	4900 4950 5000 5050
$Comp
L DS1307+ U?
U 1 1 5CB31435
P -1050 5750
F 0 "U?" H -780 6300 50  0000 C CNN
F 1 "DS1307+" H -750 5200 50  0000 C CNN
F 2 "" H -1050 5750 50  0001 C CNN
F 3 "" H -1050 5750 50  0001 C CNN
	1    -1050 5750
	1    0    0    -1  
$EndComp
$Comp
L CH340G U?
U 1 1 5CB3164F
P -1000 4300
F 0 "U?" H -975 4775 60  0000 C CNN
F 1 "CH340G" H -1000 3825 60  0000 C CNN
F 2 "" H -900 4100 60  0000 C CNN
F 3 "" H -900 4100 60  0000 C CNN
	1    -1000 4300
	1    0    0    -1  
$EndComp
$Comp
L ESP-12E U?
U 1 1 5CB316D6
P -1000 2650
F 0 "U?" H -1000 2550 50  0000 C CNN
F 1 "ESP-12E" H -1000 2750 50  0000 C CNN
F 2 "" H -1000 2650 50  0001 C CNN
F 3 "" H -1000 2650 50  0001 C CNN
	1    -1000 2650
	1    0    0    -1  
$EndComp
$Comp
L S8050 Q?
U 1 1 5CB318A1
P -1600 1350
F 0 "Q?" H -1400 1425 50  0000 L CNN
F 1 "S8050" H -1400 1350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H -1400 1275 50  0001 L CIN
F 3 "" H -1600 1350 50  0001 L CNN
	1    -1600 1350
	1    0    0    -1  
$EndComp
$Comp
L S8050 Q?
U 1 1 5CB3193E
P -950 1350
F 0 "Q?" H -750 1425 50  0000 L CNN
F 1 "S8050" H -750 1350 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Molded_Narrow" H -750 1275 50  0001 L CIN
F 3 "" H -950 1350 50  0001 L CNN
	1    -950 1350
	1    0    0    -1  
$EndComp
$EndSCHEMATC