/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
/*
 * Alarm conditions:
 * 1) KTY82-2 reports a temperature above 75 degC
 * 2) the reverse power measurement is much higher than and forward power
 * 
 * Alarms are reported by the output line GPIO RC3. Low=normal High=Alarm
 * 
 * In case of an overtemperature alarm the PA is deactivated.
 * 
 * A reverse power alarm is only reported by RC3, no deactivation of the PA.
 * 
 */

#include <config.h>
#include <pinmap.h>
#include <stdio.h>
#include <string.h>
#include <driver/adf4351.h>
#include <driver/usart.h>
#include <driver/kty82.h>
#include <driver/adc.h>
#include <alarm.h>
#include <power.h>
#include <downconv_data.h>

extern u8 ptt_status;

u8 overtemp_alarm = 0;
u8 revpwr_alarm = 0;
u8 supplyvoltage_alarm = 0;

#define MAXTEMP		75		// max. allowed PA temperature
#define MINVOLTAGE	4700	// min. voltage of the Step Down Converter
#define MAXVOLTAGE	5500	// max. voltage of the Step Down Converter

void alarm(void)
{
	static u8 old_overtemp_alarm = 0;
	static u8 old_supplyvoltage_alarm = 0;
	static u8 old_revpwr_alarm = 0;
	
	u16 fwd = 0;
	u16 rev = 0;
	
	// check alarm conditions
	s16 temperature = readKTY82();
	printf("UPC 00 00 %d\n",temperature);
	
	if(temperature >= MAXTEMP)
		overtemp_alarm = 1;

	if(temperature < (MAXTEMP-5))
		overtemp_alarm = 0;

	u16 voltage = readPowerVoltage();
	printf("UPC 00 01 %d\n",voltage);
	
	if(voltage < MINVOLTAGE)
		supplyvoltage_alarm = 1;
	else if(voltage > MAXVOLTAGE)
		supplyvoltage_alarm = 2;
	else
		supplyvoltage_alarm = 0;
	
	// check VSWR only during TX
	if(ptt_status == 1)
	{
		fwd = readFWD();
		calc_power(fwd);
		//rev = readREV();
		printf("UPC 00 02 %d %d\n",fwd,power_dBm);
		//printf("UPC 00 03 %d\n",rev);

		/*if(rev > (2*fwd))
			revpwr_alarm = 1;
		else
			revpwr_alarm = 0;*/
	}
	else
		revpwr_alarm = 0;
	
	// print alarms
	if(old_overtemp_alarm != overtemp_alarm)
	{
		printf("over temperature alarm: %s T=%d\n",overtemp_alarm?"ON":"OFF",temperature);
		printf("UPC 00 11 %s T=%d\n",overtemp_alarm?"ON":"OFF",temperature);
		old_overtemp_alarm = overtemp_alarm;
	}
	
	if(old_supplyvoltage_alarm != supplyvoltage_alarm)
	{
		if(supplyvoltage_alarm == 1)
			printf("UPC 00 12 under voltage %d mV\n",voltage);
		if(supplyvoltage_alarm == 2)
			printf("UPC 00 13 over voltage %d mV\n",voltage);
		if(supplyvoltage_alarm == 0)
			printf("UPC 00 12 supply voltage OK %d mV\n",voltage);
		
		old_supplyvoltage_alarm = supplyvoltage_alarm;
	}
	
	/*if(ptt_status == 1 && old_revpwr_alarm != revpwr_alarm)
	{
		if(revpwr_alarm)
		{
			printf("VSWR warning fwd: %d rev: %d\n",fwd,rev);
			printf("UPC 00 14 %d %d\n",fwd,rev);
		}
		
		old_revpwr_alarm = revpwr_alarm;
	}*/
	
	// handle alarms
	if(	overtemp_alarm ||
		supplyvoltage_alarm ||
		revpwr_alarm)
	{
		gpio_set_lvl_high(PIN_ALARM_OUTPUT);
	}
	else
	{
		gpio_set_lvl_low(PIN_ALARM_OUTPUT);
	}
}

// check for PA alarms 
u8 pa_alarm(void)
{
	if(overtemp_alarm || supplyvoltage_alarm)
		return 1;
	
	return 0;
}
