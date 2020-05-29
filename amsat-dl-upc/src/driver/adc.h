/* 
 * File:   adc.h
 * Author: be
 *
 * Created on 5. November 2019, 09:46
 */

#ifndef ADC_H
#define	ADC_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mtcrt/types.h"
#include "gpio.h"
    
extern void adc_init(void);
extern int  adc_cfg_gpio(gpio_pin gpio);
extern u16  adc_sample(gpio_pin gpio);
extern u32  adc_voltage(gpio_pin gpio);
extern u16 readPowerVoltage(void);
extern u16 readFWD(void);
extern u16 readREV(void);

#ifdef	__cplusplus
}
#endif

#endif	/* ADC_H */

