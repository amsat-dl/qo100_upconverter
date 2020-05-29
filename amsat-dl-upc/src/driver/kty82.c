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
#include "kty82.h"
#include <pinmap.h>
#include <stdio.h>
#include "adc.h"

#define RV			3300   // NTC to GND and RV to +5V
#define VREF_KTY	5100

// R table for KTY82-220
// first value: 0 degC
// step per value 10degC
float temptab[] = {
	1630 , //    Ohms at 0 Grad usw...
	1722 , //    10
	1922 , //    20
	2080  , //   30
	2245  , //    40
	2417  , //    50
	2597  , //    60
	2785  , //    70
	2980  , //    80
	3182   , //   90
	3392   , //    100
	3607   , //    110
	3817,	// 120
	4008,	// 130
	4166,	// 140
	4280,	//150
	-1
};

// calculate the PTC temperature
// uin: voltage at ADC input in mV
// returns: deg.C
s16 KTY82_222_Adc2Temperature(u16 adc_value)
{
	float Rptc;
	int i;
	float x;
	
	// voltage on ADC input in volts
	float Umess = (float)adc_value/1000.0;

	// resistance of the PTC
	Rptc = Umess * (float)RV / ((float)VREF_KTY/1000.0 - Umess);

	if(Rptc <= temptab[0])
	{
		// lower than minimum value, return 0 degC
		return 0;
	}

	// seek the range in the table
	i=0;
	while(temptab[i]!=-1)
	{
		if(temptab[i] >= Rptc) break;
		i++;
	}
	// the table range is i-1 ... i

	if(temptab[i]!=-1)
	{
		// Widerstandsbereich gefunden, interpoliere
		// found the range, interpolate value
		x = i - (Rptc - temptab[i])/(temptab[i-1] - temptab[i]);

		// calculate temperature from interpolated value
		return  (s16)(x*10.0);	// 10.0 = table step distance in degC
	}

	return 111; // higher than max value
}

s16 readKTY82(void)
{
	return KTY82_222_Adc2Temperature(adc_voltage(PIN_TEMP));
}
