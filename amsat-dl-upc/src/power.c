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
#include <config.h>
#include <pinmap.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <driver/adf4351.h>
#include <driver/usart.h>
#include <driver/kty82.h>
#include <driver/adc.h>
#include <alarm.h>
#include <power.h>
#include <downconv_data.h>

/*
 * calculate the ouput power according to the measurement of the AD8312
 * 
 * Measured on two upconverters:
 * 0dBm ... 420 mV
 * 40dBm .. 2080 mV
 * the output voltage is linear to dBm
 * 
 * formular to calculate power in dBm:
 * power[dBm] = 40 * (v - 420) / (2080 - 420)
 * 
 * Blink Codes:
 * 1 ... 1-10mW
 * 2 ... 10-100mW
 * 3 ... 100mW-0,5W
 * 4 ... 0,5W-1W
 * 5 ... 1W-2W
 * 6 ... 2W-4W
 * 7 ... >4W
 */

s8 power_dBm;
u8 power_blink;

#define	V0dBm	420L	// voltage in mV for 0dBm output
#define V40dBm	2080L	// voltage in mV for 40dBm output (interpolated from max possible power)

void calc_power(u16 v)
{
	s32 dBm = 40L * ((s32)v - V0dBm);
	dBm /= (V40dBm - V0dBm);
	
	// calculate watts from dBm
	// power[mW] = 10 ^ (dBm/10)
	// the pic's memory does not allow this calculation
	// but we only need to know full watts
	
	power_dBm = (s8)dBm;
	
	power_blink = 1;
	if(dBm > 10) power_blink = 2;
	if(dBm > 20) power_blink = 3;
	if(dBm > 27) power_blink = 4;
	if(dBm > 30) power_blink = 5;
	if(dBm > 33) power_blink = 6;
	if(dBm > 36) power_blink = 7;
	
	//printf("%d\n",power_blink);
}
