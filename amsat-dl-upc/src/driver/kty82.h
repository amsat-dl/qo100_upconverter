/* 
 * File:   kty82.h
 * Author: be
 *
 * Created on 4. November 2019, 12:11
 */

#ifndef KTY82_H
#define	KTY82_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "mtcrt/types.h"
    
extern s16 KTY82_222_Adc2Temperature(u16 adc_value);
extern s16 readKTY82(void);

#ifdef	__cplusplus
}
#endif

#endif	/* KTY82_H */

