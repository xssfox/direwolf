
/* decode_aprs.h */


#ifndef DECODE_APRS_H

#define DECODE_APRS_H 1



#ifndef G_UNKNOWN
#include "latlong.h"
#endif

#ifndef AX25_MAX_ADDR_LEN
#include "ax25_pad.h"
#endif 

#ifndef APRSTT_LOC_DESC_LEN
#include "aprs_tt.h"
#endif

typedef struct decode_aprs_s {

        char g_src[AX25_MAX_ADDR_LEN];

        char g_msg_type[60];		/* Message type.  Telemetry descriptions get pretty long. */

        char g_symbol_table;		/* The Symbol Table Identifier character selects one */
					/* of the two Symbol Tables, or it may be used as */
					/* single-character (alpha or numeric) overlay, as follows: */
					
					/*	/ 	Primary Symbol Table (mostly stations) */

					/* 	\ 	Alternate Symbol Table (mostly Objects) */

					/*	0-9 	Numeric overlay. Symbol from Alternate Symbol */
					/*		Table (uncompressed lat/long data format) */

					/*	a-j	Numeric overlay. Symbol from Alternate */
					/*		Symbol Table (compressed lat/long data */
					/*		format only). i.e. a-j maps to 0-9 */

					/*	A-Z	Alpha overlay. Symbol from Alternate Symbol Table */


        char g_symbol_code;		/* Where the Symbol Table Identifier is 0-9 or A-Z (or a-j */
					/* with compressed position data only), the symbol comes from */
					/* the Alternate Symbol Table, and is overlaid with the */
					/* identifier (as a single digit or a capital letter). */

	char g_aprstt_loc[APRSTT_LOC_DESC_LEN];		/* APRStt location from !DAO! */

        double g_lat, g_lon;		/* Location, degrees.  Negative for South or West. */
					/* Set to G_UNKNOWN if missing or error. */

        char g_maidenhead[9];		/* 4 or 6 (or 8?) character maidenhead locator. */

        char g_name[20];			/* Object or item name. */

        float g_speed;			/* Speed in MPH.  */

        float g_course;			/* 0 = North, 90 = East, etc. */
	
        int g_power;			/* Transmitter power in watts. */

        int g_height;			/* Antenna height above average terrain, feet. */

        int g_gain;			/* Antenna gain in dB. */

        char g_directivity[10];		/* Direction of max signal strength */

        float g_range;			/* Precomputed radio range in miles. */

        float g_altitude;		/* Feet above median sea level.  */

        char g_mfr[80];			/* Manufacturer or application. */

        char g_mic_e_status[30];		/* MIC-E message. */

        double g_freq;			/* Frequency, MHz */

        float g_tone;			/* CTCSS tone, Hz, one fractional digit */

        int g_dcs;			/* Digital coded squelch, print as 3 octal digits. */

        int g_offset;			/* Transmit offset, KHz */

        char g_weather[500];		/* Weather.  Can get quite long. Rethink max size. */

        char g_telemetry[256];		/* Telemetry data.  Rethink max size. */

        char g_comment[256];		/* Comment. */

} decode_aprs_t;





extern void decode_aprs (decode_aprs_t *A, packet_t pp);

extern void decode_aprs_print (decode_aprs_t *A);


#endif