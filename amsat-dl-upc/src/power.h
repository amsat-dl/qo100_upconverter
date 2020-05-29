/* 
 * File:   power.h
 * Author: kurt
 *
 * Created on 12. Dezember 2019, 18:37
 */

#ifndef POWER_H
#define	POWER_H

#ifdef	__cplusplus
extern "C" {
#endif

void calc_power(u16 v);

extern u8 power_blink;
extern s8 power_dBm;

#ifdef	__cplusplus
}
#endif

#endif	/* POWER_H */

