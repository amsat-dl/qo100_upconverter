/* 
 * File:   debug.h
 * Author: be
 *
 * Created on 7. November 2019, 09:46
 */

#ifndef DEBUG_H
#define	DEBUG_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef __RELEASE__
#define printd(x...)
#else
#define printd(x...) printf(x)
#endif


#ifdef	__cplusplus
}
#endif

#endif	/* DEBUG_H */

