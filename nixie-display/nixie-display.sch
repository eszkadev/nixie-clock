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
LIBS:nixie
LIBS:nixie-display-cache
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
L MPSA42 Q1
U 1 1 58BAFA75
P 1275 3300
F 0 "Q1" H 1475 3375 50  0000 L CNN
F 1 "MPSA42" H 1475 3300 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 1475 3225 50  0000 L CIN
F 3 "" H 1275 3300 50  0000 L CNN
	1    1275 3300
	1    0    0    -1  
$EndComp
$Comp
L MPSA92 Q2
U 1 1 58BAFADC
P 1725 2650
F 0 "Q2" H 1925 2725 50  0000 L CNN
F 1 "MPSA92" H 1925 2650 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 1925 2575 50  0000 L CIN
F 3 "" H 1725 2650 50  0000 L CNN
	1    1725 2650
	1    0    0    1   
$EndComp
$Comp
L R R3
U 1 1 58BAFBA4
P 1375 2900
F 0 "R3" V 1455 2900 50  0000 C CNN
F 1 "470K" V 1375 2900 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 1305 2900 50  0001 C CNN
F 3 "" H 1375 2900 50  0000 C CNN
	1    1375 2900
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 58BAFBEF
P 1375 2450
F 0 "R2" V 1455 2450 50  0000 C CNN
F 1 "100K" V 1375 2450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 1305 2450 50  0001 C CNN
F 3 "" H 1375 2450 50  0000 C CNN
	1    1375 2450
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 58BAFCD0
P 1075 2950
F 0 "R1" V 1155 2950 50  0000 C CNN
F 1 "33K" V 1075 2950 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 1005 2950 50  0001 C CNN
F 3 "" H 1075 2950 50  0000 C CNN
	1    1075 2950
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 58BAFD1D
P 1825 3050
F 0 "R4" V 1905 3050 50  0000 C CNN
F 1 "47K" V 1825 3050 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 1755 3050 50  0001 C CNN
F 3 "" H 1825 3050 50  0000 C CNN
	1    1825 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR01
U 1 1 58BAFE37
P 1375 3500
F 0 "#PWR01" H 1375 3250 50  0001 C CNN
F 1 "GND" H 1375 3350 50  0000 C CNN
F 2 "" H 1375 3500 50  0000 C CNN
F 3 "" H 1375 3500 50  0000 C CNN
	1    1375 3500
	1    0    0    -1  
$EndComp
$Comp
L MPSA42 Q3
U 1 1 58BB051A
P 3675 3300
F 0 "Q3" H 3875 3375 50  0000 L CNN
F 1 "MPSA42" H 3875 3300 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 3875 3225 50  0000 L CIN
F 3 "" H 3675 3300 50  0000 L CNN
	1    3675 3300
	1    0    0    -1  
$EndComp
$Comp
L MPSA92 Q4
U 1 1 58BB0520
P 4125 2650
F 0 "Q4" H 4325 2725 50  0000 L CNN
F 1 "MPSA92" H 4325 2650 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 4325 2575 50  0000 L CIN
F 3 "" H 4125 2650 50  0000 L CNN
	1    4125 2650
	1    0    0    1   
$EndComp
$Comp
L R R7
U 1 1 58BB0526
P 3775 2900
F 0 "R7" V 3855 2900 50  0000 C CNN
F 1 "470K" V 3775 2900 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3705 2900 50  0001 C CNN
F 3 "" H 3775 2900 50  0000 C CNN
	1    3775 2900
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 58BB052C
P 3775 2450
F 0 "R6" V 3855 2450 50  0000 C CNN
F 1 "100K" V 3775 2450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3705 2450 50  0001 C CNN
F 3 "" H 3775 2450 50  0000 C CNN
	1    3775 2450
	1    0    0    -1  
$EndComp
$Comp
L R R5
U 1 1 58BB0532
P 3475 2950
F 0 "R5" V 3555 2950 50  0000 C CNN
F 1 "33K" V 3475 2950 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 3405 2950 50  0001 C CNN
F 3 "" H 3475 2950 50  0000 C CNN
	1    3475 2950
	1    0    0    -1  
$EndComp
$Comp
L R R8
U 1 1 58BB0538
P 4225 3050
F 0 "R8" V 4305 3050 50  0000 C CNN
F 1 "47K" V 4225 3050 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 4155 3050 50  0001 C CNN
F 3 "" H 4225 3050 50  0000 C CNN
	1    4225 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 58BB053E
P 3775 3500
F 0 "#PWR02" H 3775 3250 50  0001 C CNN
F 1 "GND" H 3775 3350 50  0000 C CNN
F 2 "" H 3775 3500 50  0000 C CNN
F 3 "" H 3775 3500 50  0000 C CNN
	1    3775 3500
	1    0    0    -1  
$EndComp
$Comp
L MPSA42 Q5
U 1 1 58BB070F
P 6075 3300
F 0 "Q5" H 6275 3375 50  0000 L CNN
F 1 "MPSA42" H 6275 3300 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 6275 3225 50  0000 L CIN
F 3 "" H 6075 3300 50  0000 L CNN
	1    6075 3300
	1    0    0    -1  
$EndComp
$Comp
L MPSA92 Q6
U 1 1 58BB0715
P 6525 2650
F 0 "Q6" H 6725 2725 50  0000 L CNN
F 1 "MPSA92" H 6725 2650 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 6725 2575 50  0000 L CIN
F 3 "" H 6525 2650 50  0000 L CNN
	1    6525 2650
	1    0    0    1   
$EndComp
$Comp
L R R11
U 1 1 58BB071B
P 6175 2900
F 0 "R11" V 6255 2900 50  0000 C CNN
F 1 "470K" V 6175 2900 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 6105 2900 50  0001 C CNN
F 3 "" H 6175 2900 50  0000 C CNN
	1    6175 2900
	1    0    0    -1  
$EndComp
$Comp
L R R10
U 1 1 58BB0721
P 6175 2450
F 0 "R10" V 6255 2450 50  0000 C CNN
F 1 "100K" V 6175 2450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 6105 2450 50  0001 C CNN
F 3 "" H 6175 2450 50  0000 C CNN
	1    6175 2450
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 58BB0727
P 5875 2950
F 0 "R9" V 5955 2950 50  0000 C CNN
F 1 "33K" V 5875 2950 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 5805 2950 50  0001 C CNN
F 3 "" H 5875 2950 50  0000 C CNN
	1    5875 2950
	1    0    0    -1  
$EndComp
$Comp
L R R12
U 1 1 58BB072D
P 6625 3050
F 0 "R12" V 6705 3050 50  0000 C CNN
F 1 "47K" V 6625 3050 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 6555 3050 50  0001 C CNN
F 3 "" H 6625 3050 50  0000 C CNN
	1    6625 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 58BB0733
P 6175 3500
F 0 "#PWR03" H 6175 3250 50  0001 C CNN
F 1 "GND" H 6175 3350 50  0000 C CNN
F 2 "" H 6175 3500 50  0000 C CNN
F 3 "" H 6175 3500 50  0000 C CNN
	1    6175 3500
	1    0    0    -1  
$EndComp
$Comp
L MPSA42 Q7
U 1 1 58BB0CAE
P 8475 3300
F 0 "Q7" H 8675 3375 50  0000 L CNN
F 1 "MPSA42" H 8675 3300 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 8675 3225 50  0000 L CIN
F 3 "" H 8475 3300 50  0000 L CNN
	1    8475 3300
	1    0    0    -1  
$EndComp
$Comp
L MPSA92 Q8
U 1 1 58BB0CB4
P 8925 2650
F 0 "Q8" H 9125 2725 50  0000 L CNN
F 1 "MPSA92" H 9125 2650 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 9125 2575 50  0000 L CIN
F 3 "" H 8925 2650 50  0000 L CNN
	1    8925 2650
	1    0    0    1   
$EndComp
$Comp
L R R15
U 1 1 58BB0CBA
P 8575 2900
F 0 "R15" V 8655 2900 50  0000 C CNN
F 1 "470K" V 8575 2900 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 8505 2900 50  0001 C CNN
F 3 "" H 8575 2900 50  0000 C CNN
	1    8575 2900
	1    0    0    -1  
$EndComp
$Comp
L R R14
U 1 1 58BB0CC0
P 8575 2450
F 0 "R14" V 8655 2450 50  0000 C CNN
F 1 "100K" V 8575 2450 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 8505 2450 50  0001 C CNN
F 3 "" H 8575 2450 50  0000 C CNN
	1    8575 2450
	1    0    0    -1  
$EndComp
$Comp
L R R13
U 1 1 58BB0CC6
P 8275 2950
F 0 "R13" V 8355 2950 50  0000 C CNN
F 1 "33K" V 8275 2950 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 8205 2950 50  0001 C CNN
F 3 "" H 8275 2950 50  0000 C CNN
	1    8275 2950
	1    0    0    -1  
$EndComp
$Comp
L R R16
U 1 1 58BB0CCC
P 9025 3050
F 0 "R16" V 9105 3050 50  0000 C CNN
F 1 "47K" V 9025 3050 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 8955 3050 50  0001 C CNN
F 3 "" H 9025 3050 50  0000 C CNN
	1    9025 3050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR04
U 1 1 58BB0CD2
P 8575 3500
F 0 "#PWR04" H 8575 3250 50  0001 C CNN
F 1 "GND" H 8575 3350 50  0000 C CNN
F 2 "" H 8575 3500 50  0000 C CNN
F 3 "" H 8575 3500 50  0000 C CNN
	1    8575 3500
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR05
U 1 1 58BB298E
P 10325 2175
F 0 "#PWR05" H 10325 2025 50  0001 C CNN
F 1 "VCC" H 10325 2325 50  0000 C CNN
F 2 "" H 10325 2175 50  0000 C CNN
F 3 "" H 10325 2175 50  0000 C CNN
	1    10325 2175
	1    0    0    -1  
$EndComp
$Comp
L MPSA42 Q9
U 1 1 58BB2EF6
P 10225 3550
F 0 "Q9" H 10425 3625 50  0000 L CNN
F 1 "MPSA42" H 10425 3550 50  0000 L CNN
F 2 "TO_SOT_Packages_THT:TO-92_Inline_Wide" H 10425 3475 50  0000 L CIN
F 3 "" H 10225 3550 50  0000 L CNN
	1    10225 3550
	1    0    0    -1  
$EndComp
$Comp
L R R17
U 1 1 58BB2EFC
P 10025 3200
F 0 "R17" V 10105 3200 50  0000 C CNN
F 1 "33K" V 10025 3200 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 9955 3200 50  0001 C CNN
F 3 "" H 10025 3200 50  0000 C CNN
	1    10025 3200
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 58BB2F02
P 10325 3750
F 0 "#PWR06" H 10325 3500 50  0001 C CNN
F 1 "GND" H 10325 3600 50  0000 C CNN
F 2 "" H 10325 3750 50  0000 C CNN
F 3 "" H 10325 3750 50  0000 C CNN
	1    10325 3750
	1    0    0    -1  
$EndComp
$Comp
L R R18
U 1 1 58BB2F68
P 10325 3200
F 0 "R18" V 10405 3200 50  0000 C CNN
F 1 "220K" V 10325 3200 50  0000 C CNN
F 2 "Resistors_ThroughHole:R_Axial_DIN0309_L9.0mm_D3.2mm_P15.24mm_Horizontal" V 10255 3200 50  0001 C CNN
F 3 "" H 10325 3200 50  0000 C CNN
	1    10325 3200
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X10 P2
U 1 1 58BB4AFE
P 700 5250
F 0 "P2" H 700 5800 50  0000 C CNN
F 1 "CONN_01X10" V 800 5250 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x10_Pitch2.54mm" H 700 5250 50  0001 C CNN
F 3 "" H 700 5250 50  0000 C CNN
	1    700  5250
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X06 P1
U 1 1 58BB90BE
P 700 1600
F 0 "P1" H 700 1950 50  0000 C CNN
F 1 "CONN_01X06" V 800 1600 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x06_Pitch2.54mm" H 700 1600 50  0001 C CNN
F 3 "" H 700 1600 50  0000 C CNN
	1    700  1600
	-1   0    0    1   
$EndComp
$Comp
L CONN_01X03 P3
U 1 1 58BB9390
P 10650 1550
F 0 "P3" H 10650 1750 50  0000 C CNN
F 1 "CONN_01X03" V 10750 1550 50  0000 C CNN
F 2 "Terminal_Blocks:TerminalBlock_Pheonix_MPT-2.54mm_3pol" H 10650 1550 50  0001 C CNN
F 3 "" H 10650 1550 50  0000 C CNN
	1    10650 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 58BB9E10
P 10325 1650
F 0 "#PWR07" H 10325 1400 50  0001 C CNN
F 1 "GND" H 10325 1500 50  0000 C CNN
F 2 "" H 10325 1650 50  0000 C CNN
F 3 "" H 10325 1650 50  0000 C CNN
	1    10325 1650
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR08
U 1 1 58BB9E8D
P 10325 1450
F 0 "#PWR08" H 10325 1300 50  0001 C CNN
F 1 "VCC" H 10325 1600 50  0000 C CNN
F 2 "" H 10325 1450 50  0000 C CNN
F 3 "" H 10325 1450 50  0000 C CNN
	1    10325 1450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR09
U 1 1 58BBAA12
P 900 1850
F 0 "#PWR09" H 900 1600 50  0001 C CNN
F 1 "GND" H 900 1700 50  0000 C CNN
F 2 "" H 900 1850 50  0000 C CNN
F 3 "" H 900 1850 50  0000 C CNN
	1    900  1850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 58BB17CB
P 10200 5500
F 0 "#PWR010" H 10200 5250 50  0001 C CNN
F 1 "GND" H 10200 5350 50  0000 C CNN
F 2 "" H 10200 5500 50  0000 C CNN
F 3 "" H 10200 5500 50  0000 C CNN
	1    10200 5500
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR011
U 1 1 58BB1825
P 10675 5500
F 0 "#PWR011" H 10675 5350 50  0001 C CNN
F 1 "VCC" H 10675 5650 50  0000 C CNN
F 2 "" H 10675 5500 50  0000 C CNN
F 3 "" H 10675 5500 50  0000 C CNN
	1    10675 5500
	1    0    0    1   
$EndComp
$Comp
L PWR_FLAG #FLG012
U 1 1 58BB19E3
P 10200 5500
F 0 "#FLG012" H 10200 5595 50  0001 C CNN
F 1 "PWR_FLAG" H 10200 5680 50  0000 C CNN
F 2 "" H 10200 5500 50  0000 C CNN
F 3 "" H 10200 5500 50  0000 C CNN
	1    10200 5500
	1    0    0    -1  
$EndComp
$Comp
L PWR_FLAG #FLG013
U 1 1 58BB1A3D
P 10675 5500
F 0 "#FLG013" H 10675 5595 50  0001 C CNN
F 1 "PWR_FLAG" H 10675 5680 50  0000 C CNN
F 2 "" H 10675 5500 50  0000 C CNN
F 3 "" H 10675 5500 50  0000 C CNN
	1    10675 5500
	1    0    0    -1  
$EndComp
$Comp
L Conn_01x11 J1
U 1 1 5A26E6A8
P 1500 4050
F 0 "J1" H 1500 4650 50  0000 C CNN
F 1 "Conn_01x11" H 1500 3450 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x11_Pitch2.54mm" H 1500 4050 50  0001 C CNN
F 3 "" H 1500 4050 50  0001 C CNN
	1    1500 4050
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x11 J2
U 1 1 5A2726D4
P 3450 4050
F 0 "J2" H 3450 4650 50  0000 C CNN
F 1 "Conn_01x11" H 3450 3450 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x11_Pitch2.54mm" H 3450 4050 50  0001 C CNN
F 3 "" H 3450 4050 50  0001 C CNN
	1    3450 4050
	0    -1   -1   0   
$EndComp
$Comp
L Conn_01x11 J3
U 1 1 5A27345D
P 5800 4050
F 0 "J3" H 5800 4650 50  0000 C CNN
F 1 "Conn_01x11" H 5800 3450 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x11_Pitch2.54mm" H 5800 4050 50  0001 C CNN
F 3 "" H 5800 4050 50  0001 C CNN
	1    5800 4050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	1825 3600 1825 3200
Wire Wire Line
	1075 3300 1075 3100
Wire Wire Line
	1825 2850 1825 2900
Connection ~ 1375 2650
Wire Wire Line
	1375 2650 1525 2650
Wire Wire Line
	1375 2600 1375 2750
Wire Wire Line
	1375 3100 1375 3050
Wire Wire Line
	4225 3200 4225 4350
Wire Wire Line
	3475 3300 3475 3100
Wire Wire Line
	4225 2850 4225 2900
Connection ~ 3775 2650
Wire Wire Line
	3775 2650 3925 2650
Wire Wire Line
	3775 2600 3775 2750
Wire Wire Line
	3775 3100 3775 3050
Wire Wire Line
	6625 3200 6625 4350
Wire Wire Line
	5875 3300 5875 3100
Wire Wire Line
	6625 2850 6625 2900
Connection ~ 6175 2650
Wire Wire Line
	6175 2650 6325 2650
Wire Wire Line
	6175 2600 6175 2750
Wire Wire Line
	6175 3100 6175 3050
Wire Wire Line
	9025 3200 9025 4350
Wire Wire Line
	8275 3300 8275 3100
Wire Wire Line
	9025 2850 9025 2900
Connection ~ 8575 2650
Wire Wire Line
	8575 2650 8725 2650
Wire Wire Line
	8575 2600 8575 2750
Wire Wire Line
	8575 3100 8575 3050
Wire Wire Line
	1825 2450 1825 2300
Wire Wire Line
	1375 2300 10325 2300
Wire Wire Line
	4225 2300 4225 2450
Wire Wire Line
	6625 2300 6625 2450
Connection ~ 3775 2300
Connection ~ 1825 2300
Connection ~ 6175 2300
Connection ~ 4225 2300
Wire Wire Line
	9025 2300 9025 2450
Connection ~ 8575 2300
Connection ~ 6625 2300
Wire Wire Line
	10025 3550 10025 3350
Connection ~ 9025 2300
Wire Wire Line
	10325 2175 10325 2650
Wire Wire Line
	10325 1450 10450 1450
Wire Wire Line
	10450 1650 10325 1650
Wire Wire Line
	10450 1550 10325 1550
Wire Wire Line
	10325 1550 10325 1650
Wire Wire Line
	1075 2800 1075 1750
Wire Wire Line
	1075 1750 900  1750
Wire Wire Line
	900  1650 3475 1650
Wire Wire Line
	3475 1650 3475 2800
Wire Wire Line
	900  1550 5875 1550
Wire Wire Line
	5875 1550 5875 2800
Wire Wire Line
	900  1450 8275 1450
Wire Wire Line
	8275 1450 8275 2800
Wire Wire Line
	900  1350 10025 1350
Wire Wire Line
	10025 1350 10025 3050
Wire Wire Line
	900  4800 7700 4800
Wire Wire Line
	1000 4800 1000 4250
Wire Wire Line
	900  4900 7800 4900
Wire Wire Line
	1100 4900 1100 4250
Wire Wire Line
	900  5000 7900 5000
Wire Wire Line
	1200 5000 1200 4250
Wire Wire Line
	900  5100 8000 5100
Wire Wire Line
	1300 5100 1300 4250
Wire Wire Line
	900  5200 8100 5200
Wire Wire Line
	1400 5200 1400 4250
Wire Wire Line
	900  5300 8200 5300
Wire Wire Line
	1500 5300 1500 4250
Wire Wire Line
	900  5400 8300 5400
Wire Wire Line
	1600 5400 1600 4250
Wire Wire Line
	900  5500 8400 5500
Wire Wire Line
	1700 5500 1700 4250
Wire Wire Line
	900  5600 8500 5600
Wire Wire Line
	1800 5600 1800 4250
Wire Wire Line
	900  5700 8600 5700
Wire Wire Line
	1900 5700 1900 4250
Wire Wire Line
	1825 3600 2400 3600
Wire Wire Line
	2400 3600 2400 4325
Wire Wire Line
	2400 4325 2000 4325
Wire Wire Line
	2000 4325 2000 4250
Wire Wire Line
	2950 4800 2950 4250
Connection ~ 1000 4800
Wire Wire Line
	3050 4900 3050 4250
Connection ~ 1100 4900
Wire Wire Line
	3150 5000 3150 4250
Connection ~ 1200 5000
Wire Wire Line
	3250 5100 3250 4250
Connection ~ 1300 5100
Wire Wire Line
	3350 5200 3350 4250
Connection ~ 1400 5200
Wire Wire Line
	3450 5300 3450 4250
Connection ~ 1500 5300
Wire Wire Line
	3550 5400 3550 4250
Connection ~ 1600 5400
Wire Wire Line
	3650 5500 3650 4250
Connection ~ 1700 5500
Wire Wire Line
	3750 5600 3750 4250
Connection ~ 1800 5600
Wire Wire Line
	3850 5700 3850 4250
Connection ~ 1900 5700
Wire Wire Line
	4225 4350 3950 4350
Wire Wire Line
	3950 4350 3950 4250
Wire Wire Line
	5300 4800 5300 4250
Connection ~ 2950 4800
Wire Wire Line
	5400 4900 5400 4250
Connection ~ 3050 4900
Wire Wire Line
	5500 5000 5500 4250
Connection ~ 3150 5000
Wire Wire Line
	5600 5100 5600 4250
Connection ~ 3250 5100
Wire Wire Line
	5700 5200 5700 4250
Connection ~ 3350 5200
Wire Wire Line
	5800 5300 5800 4250
Connection ~ 3450 5300
Wire Wire Line
	5900 5400 5900 4250
Connection ~ 3550 5400
Wire Wire Line
	6000 5500 6000 4250
Connection ~ 3650 5500
Wire Wire Line
	6100 5600 6100 4250
Connection ~ 3750 5600
Wire Wire Line
	6200 5700 6200 4250
Connection ~ 3850 5700
Wire Wire Line
	6625 4350 6300 4350
Wire Wire Line
	6300 4350 6300 4250
$Comp
L Conn_01x11 J4
U 1 1 5A273F72
P 8200 4050
F 0 "J4" H 8200 4650 50  0000 C CNN
F 1 "Conn_01x11" H 8200 3450 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x11_Pitch2.54mm" H 8200 4050 50  0001 C CNN
F 3 "" H 8200 4050 50  0001 C CNN
	1    8200 4050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7700 4800 7700 4250
Connection ~ 5300 4800
Wire Wire Line
	7800 4900 7800 4250
Connection ~ 5400 4900
Wire Wire Line
	7900 5000 7900 4250
Connection ~ 5500 5000
Wire Wire Line
	8000 5100 8000 4250
Connection ~ 5600 5100
Wire Wire Line
	8100 5200 8100 4250
Connection ~ 5700 5200
Wire Wire Line
	8200 5300 8200 4250
Connection ~ 5800 5300
Wire Wire Line
	8300 5400 8300 4250
Connection ~ 5900 5400
Wire Wire Line
	8400 5500 8400 4250
Connection ~ 6000 5500
Wire Wire Line
	8500 5600 8500 4250
Connection ~ 6100 5600
Wire Wire Line
	8600 5700 8600 4250
Connection ~ 6200 5700
Wire Wire Line
	9025 4350 8700 4350
Wire Wire Line
	8700 4350 8700 4250
$Comp
L Conn_01x02 J5
U 1 1 5A27568F
P 10525 2650
F 0 "J5" H 10525 2750 50  0000 C CNN
F 1 "Conn_01x02" H 10525 2450 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x02_Pitch2.54mm" H 10525 2650 50  0001 C CNN
F 3 "" H 10525 2650 50  0001 C CNN
	1    10525 2650
	1    0    0    -1  
$EndComp
Connection ~ 10325 2300
Wire Wire Line
	10325 2750 10325 3050
Text Notes 1325 3925 0    60   ~ 0
NIXIE1
Text Notes 3325 3925 0    60   ~ 0
NIXIE2
Text Notes 5650 3925 0    60   ~ 0
NIXIE3
Text Notes 8075 3925 0    60   ~ 0
NIXIE4
Text Notes 10675 2725 0    60   ~ 0
NEON1
Text Notes 7350 7500 0    60   ~ 12
Nixie switching
$EndSCHEMATC
