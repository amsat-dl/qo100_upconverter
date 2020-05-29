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
#include <pic18f2520.h>
#include <config.h>
#include <pinmap.h>
#include <stdio.h>
#include "adc.h"

static inline int gpio_to_ch(gpio_pin gpio);

void adc_init(void)
{
    ADCON1bits.VCFG1 = 0;	// 3,3V Reference
    ADCON1bits.VCFG0 = 0;
    ADCON1bits.PCFG  = 0xF;	// AN0-AN4 ... analog inputs
    
    ADCON2bits.ADFM = 1;	// right justified
    ADCON2bits.ACQT = 7;	// aqu time: 20T
    ADCON2bits.ADCS = 7;	// clock: AD RC osc.
    
    ADCON0bits.ADON = 1;
}

int adc_cfg_gpio(gpio_pin gpio)
{
    if(gpio_to_ch(gpio) < 0) return -1;

    gpio_set_dir_in(gpio);
    return 0;
}

// 16 bit value of the ADC
u16 adc_sample(gpio_pin gpio)
{
    int ch = gpio_to_ch(gpio);
    if(ch>=0) {
        //set channel
		ADCON1bits.PCFG  = 0;
        ADCON0bits.CHS = ch;	
        //start conversion
        ADCON0bits.GODONE = 1;
        //wait for conversion to finish
        while(ADCON0bits.GODONE != 0);
		ADCON1bits.PCFG  = 0xF;
        //return result
		u16 result = (u16)ADRESH<<8 | (u16)ADRESL;
		//printf("ch:%d res:%d\n",ch,result);
        return result;
    }
    return 0;
}

// voltage on ADC input in mV
#define UREF 3300L	// ADC ref voltage in mV
#define ADCRES 10	// ADC resolution in bits
u32 adc_voltage(gpio_pin gpio)
{
    //return ((3222656 * (u32)adc_sample(gpio)) + 500) / 1000;
	
	u32 adcval = adc_sample(gpio);
	u32 mV = (adcval*UREF)/(1<<ADCRES);
	
	return mV;
}

static inline int gpio_to_ch(gpio_pin gpio)
{
    if(gpio->pTRIS == (volatile unsigned char *)&TRISA) {
        if(gpio->mask & 0x01) return 0;
        if(gpio->mask & 0x02) return 1;
        if(gpio->mask & 0x04) return 2;
        if(gpio->mask & 0x08) return 3;
        if(gpio->mask & 0x20) return 4;
        return -1;
    }
    if(gpio->pTRIS == (volatile unsigned char *)&TRISB) {
        if(gpio->mask & 0x01) return 12;
        if(gpio->mask & 0x02) return 10;
        if(gpio->mask & 0x04) return 8;
        if(gpio->mask & 0x08) return 9;
        if(gpio->mask & 0x10) return 11;
        return -1;
    }
    return -1;
}

// check the 5V output of the switched power regulator
u16 readPowerVoltage(void)
{
	u32 v = adc_voltage(PIN_VOLTAGE);
	
	return (u16)v * 2;
}
		
u16 readFWD(void)
{
	u32 fwd_volt = adc_voltage(PIN_RF_V);
	
	return fwd_volt;
}

u16 readREV(void)
{
	u32 rev_volt = adc_voltage(PIN_RF_R);
	
	return rev_volt;
}
