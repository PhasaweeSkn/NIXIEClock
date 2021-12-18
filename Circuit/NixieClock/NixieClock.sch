EESchema Schematic File Version 4
EELAYER 30 0
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
L NixieClock:IN-8 NE1
U 1 1 61B2A53B
P 2600 2300
F 0 "NE1" H 2828 2346 50  0000 L CNN
F 1 "IN-8" H 2828 2255 50  0000 L CNN
F 2 "NixieClock:IN-8" H 2450 2950 50  0001 C CNN
F 3 "" H 2450 2950 50  0001 C CNN
	1    2600 2300
	0    -1   -1   0   
$EndComp
$Comp
L NixieClock:74141N U1
U 1 1 61B2E166
P 2550 3250
F 0 "U1" V 2596 3828 50  0000 L CNN
F 1 "74141N" V 2505 3828 50  0000 L CNN
F 2 "Package_DIP:DIP-16_W7.62mm" H 3100 3250 50  0001 C CNN
F 3 "" H 3100 3250 50  0001 C CNN
	1    2550 3250
	0    -1   -1   0   
$EndComp
Wire Wire Line
	2200 2900 2200 2600
Wire Wire Line
	2300 2900 2300 2600
Wire Wire Line
	2400 2900 2400 2600
Wire Wire Line
	2500 2900 2500 2600
Wire Wire Line
	2600 2900 2600 2600
Wire Wire Line
	2700 2900 2700 2600
Wire Wire Line
	2800 2900 2800 2600
Wire Wire Line
	2900 2900 2900 2600
Wire Wire Line
	3000 2900 3000 2600
Wire Wire Line
	2100 2900 2100 2750
Wire Wire Line
	2100 2750 3100 2750
Wire Wire Line
	3100 2750 3100 2600
$Comp
L 74xx:74AHC595 U?
U 1 1 61BE0AD2
P 2450 4850
F 0 "U?" H 2450 5631 50  0000 C CNN
F 1 "74AHC595" H 2450 5540 50  0000 C CNN
F 2 "" H 2450 4850 50  0001 C CNN
F 3 "https://assets.nexperia.com/documents/data-sheet/74AHC_AHCT595.pdf" H 2450 4850 50  0001 C CNN
	1    2450 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	2850 4450 3000 4450
Wire Wire Line
	3000 4450 3000 4000
Wire Wire Line
	3000 4000 2400 4000
Wire Wire Line
	2400 4000 2400 3600
Wire Wire Line
	2850 4550 3100 4550
Wire Wire Line
	3100 4550 3100 3850
Wire Wire Line
	3100 3850 2500 3850
Wire Wire Line
	2500 3850 2500 3600
Wire Wire Line
	2850 4650 3250 4650
Wire Wire Line
	3250 4650 3250 3700
Wire Wire Line
	3250 3700 2600 3700
Wire Wire Line
	2600 3700 2600 3600
Wire Wire Line
	2700 3600 3400 3600
Wire Wire Line
	3400 3600 3400 4750
Wire Wire Line
	3400 4750 2850 4750
$EndSCHEMATC
