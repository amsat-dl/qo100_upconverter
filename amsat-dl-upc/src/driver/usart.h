#ifndef __DRIVER_USART_H__
#define __DRIVER_USART_H__

//initialize usart-port
extern void usart_init(u32 baud);
//write char to usart-port
extern char usart_putc(char c);
//data ready to be read from usart-port?
extern int usart_tstc(void);
//read char from usart-port
extern int usart_getc(void);

#endif //__DRIVER_USART_H__
