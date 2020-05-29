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
#include "usart.h"
#include <driver/irq.h>

//USART RX-fifo
static volatile char g_usart_buf[256];
static volatile u16 g_usart_rpos = 0;
static volatile u16 g_usart_wpos = 0;

static void usart_rx_irq_handler(void *udata);

void usart_init(u32 baud)
{
    irq_set_handler(IRQ_HANDLER_ID_USART, usart_rx_irq_handler, NULL);
    TXSTAbits.TX9 = 0;   //8-Bit transmit
    TXSTAbits.SENDB = 0; //don't send sync break
    TXSTAbits.BRGH = 1;  //high speed
    TXSTAbits.TXEN = 1;  //enable transmiter
    
    
    RCSTAbits.RX9 = 0;   //8-Bit transmit
    RCSTAbits.CREN = 1;  //enable receiver
    RCSTAbits.ADDEN = 0; //disable address detection
    
    BAUDCONbits.BRG16 = 1; //16-bit baud rate generator
    BAUDCONbits.ABDEN = 0; //auto baudrate disable
    
    u16 spbrg_value = ((_XTAL_FREQ/4) / baud) - 1;
    
    SPBRGH = (spbrg_value>>8)&0xFF; //set baudrate
    SPBRG  = (spbrg_value>>0)&0xFF; //set baudrate
    
    TXSTAbits.SYNC = 0; //async
    RCSTAbits.SPEN = 1; //enable usart port

    PIE1bits.RCIE = 1;  //enable rx interrupt
}

char usart_putc(char c)
{
    //whait for tx register to be empty
    while(TXSTAbits.TRMT == 0);
    //send data
    TXREG = c;
    
    return c;
}

//data ready to be read from usart-port?
int usart_tstc(void)
{
	return (g_usart_wpos != g_usart_rpos);
}

//read char from usart-port
int usart_getc(void)
{
	int res;

	//wait until char is ready to be read
	while(g_usart_wpos == g_usart_rpos);

	//get char
	res = g_usart_buf[g_usart_rpos];
	g_usart_rpos = (g_usart_rpos+1) % sizeof(g_usart_buf);

	//return char
	return res;
}

static void usart_rx_irq_handler(void *udata)
{
    volatile char c;
    volatile int wposn;

    //check if operation is active
    if(BAUDCONbits.RCIDL == 0) return;
    
	//read char (clears irq flag)
	c = RCREG;

    //check for errors
    if(RCSTAbits.FERR) {
        return;
    }
    if(RCSTAbits.OERR) {
        //reset bus
        RCSTAbits.CREN = 0;
        RCSTAbits.CREN = 1;
        return;
    }
	
	//printf("c:%d\n",c);

	//write char into fifo
	wposn = (g_usart_wpos+1) % sizeof(g_usart_buf);
	if(wposn != g_usart_rpos) {
		g_usart_buf[g_usart_wpos] = c;
		g_usart_wpos = wposn;
	}
}
