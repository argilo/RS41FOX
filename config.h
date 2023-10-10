// RS41FOX Config File.

#ifndef RS41HUP_CONFIG_H
#define RS41HUP_CONFIG_H

#ifdef USE_EXTERNAL_CONFIG
#include "config_external.h"
#else


//************GLOBAL Settings*****************
#define CALLSIGN "VE3IRR" // Put your callsign here, max. 15 characters

// TX Power
#define TX_POWER  0 // PWR 0...7 0- MIN ... 7 - MAX
// Power Levels measured at 434.650 MHz, using a Rigol DSA815, and a 10 kHz RBW
// Power measured by connecting a short (30cm) length of RG316 directly to the
// antenna/ground pads at the bottom of the RS41 PCB.
// 0 --> -1.9dBm
// 1 --> 1.3dBm
// 2 --> 3.6dBm
// 3 --> 7.0dBm
// 4 --> 10.0dBm
// 5 --> 13.1dBm - DEFAULT
// 6 --> 15.0dBm
// 7 --> 16.3dBm


//*************BEACON SETTINGS****************
// Morse Ident speed.
#define MORSE_WPM	12

// CW beacon on & off times.
#define ON_TIME		5 // Seconds
#define OFF_TIME	20 // Seconds

// Number of On/Off Repeats.
#define ONOFF_REPEATS 1

// Low-Voltage Beacon
// If enabled (uncommmented), beacon the lat/lon of the fox in the CW ident when the battery voltage gets low.
// NOTE: If you are going to place the fox in a location with no GPS reception, disable this mode,
// else it will draw lots of power trying to acquire GPS signal.
// #define LOW_VOLTAGE_BEACON 1

// Low-Voltage beacon threshold voltage. For ~4-5 hours of position beaconing before going flat, use:
// Lithium AA: 2.7 volts  (Refer 100mA discharge curve here: http://data.energizer.com/pdfs/l91.pdf )
// Alkaline AA: 2.2 volts (Refer 100mA discharge curve here: http://data.energizer.com/pdfs/e91.pdf )
#define LOW_VOLTAGE_BEACON_THRESHOLD 2.2 // Volts

// Low-Voltage Cutout - Kill power if the supply drops below this level. Useful to avoid destroying cells.
// Set this to < 1 Volt for (essentially) no low-voltage cutout.
#define LOW_VOLTAGE_CUTOUT 0.0 // Volts


#endif
#endif //RS41HUP_CONFIG_H
