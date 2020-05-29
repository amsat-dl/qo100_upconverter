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
 * File:   main.c
 * Author: be
 *
 * Created on 23. April 2019, 16:56
 */

// PIC18F2520 Configuration Bit Settings

// CONFIG1H
#pragma config OSC = INTIO67    // Oscillator Selection bits (Internal oscillator block, port function on RA6 and RA7)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 3         // Brown Out Reset Voltage bits (Minimum setting)

// CONFIG2H
#ifdef __RELEASE__
#pragma config WDT = ON         // Watchdog Timer Enable bit (WDT enabled)
#else
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled)
#endif
#pragma config WDTPS = 256      // Watchdog Timer Postscale Select bits (1:256)

// CONFIG3H
#pragma config CCP2MX = PORTC   // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as analog input on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer1 Oscillator Enable bit (Timer1 configured for higher power operation)
#ifdef __RELEASE__
#pragma config MCLRE = OFF       // MCLR Pin Enable bit (MCLR pin disabled; RE3 input pin enabled)
#else
#pragma config MCLRE = ON       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)
#endif //__RELEASE__

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = OFF         // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config XINST = OFF       // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode enabled)

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.
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
#include <mtstd/debug.h>
//#include "../hg.h"

#define EVENT_LOOP_DELAY    10 //event loop delay time in ms
#define DEBOUNCE_TIME       10 //debounce time will be DEBOUNCE_TIME*EVENT_LOOP_DELAY ms
#define ALIVE_UPDATE_TIME  50 //led update time will be LED_UPDATE_TIME*EVENT_LOOP_DELAY ms

//local variables
static int  g_cmd_debounce_counter = DEBOUNCE_TIME;	// debouncing of the two qrg jumpers
static u8   g_pending_cmd = 0xFF;
static u8   g_applied_cmd = 0xFF;
static int  g_ipc = ADF4351_ICP_188;
static int  g_pout = ADF4351_POUT_1;
static int  g_cpu_led_update_cnt = 0;
static int  g_ptt_debounce_counter = DEBOUNCE_TIME;
static adf4351_ctx g_adf4351;
u8 ptt_status = 0;


// LNB LO Freq in kHz
static const u32 freq_table[4] = {
    1970000,	// 2400 - 1970 = 430 MHz
	1965000,	// 2400 - 1965 = 435 MHz
	1570000,	// 2400 - 1570 = 830 MHz
	1110000,	// 2400 - 1970 = 1290 MHz
};

//local functions declarations
static void check_adf4351_lock(void);
static u8  read_switch(void);
static void init_switch(void);
static void update_switch(void);
static void update_led(void);
static void pa_mute(void);
static void pa_unmute(void);
static void pa_update(void);
static void handle_cmd(u8 cmd);
static void init_gpios(void);
static void setLOCK_LED(u8 onoff);
static void setPTT_LED(u8 onoff);
static void check_usart(void);

//
//main function
//
void main(void)
{
    int ref;
    //clock setup
    OSCTUNE = 0x80;
    OSCCON = 0xF2;
    
    //wait for clock to get stable
    while(!OSCCONbits.IOFS);

    //disable all interrupts
    PIE1 = 0;
    PIE2 = 0;

    init_gpios();

    adc_init();
    adc_cfg_gpio(PIN_TEMP);
    adc_cfg_gpio(PIN_RF_V);
    adc_cfg_gpio(PIN_RF_R);
    adc_cfg_gpio(PIN_VOLTAGE);

    usart_init(9600);
    
    ref = gpio_get_input(PIN_ADF_FREQ_SEL) ? 0 : 1;	// open=40 MHz, closed=10 MHz
    
    //welcome message
    printf("\nAMSAT DL UpConverter HW:%s FW:%s\n\n",UPC_HW_VERSION,UPC_SW_VERSION);
	printf("UPC 00 07 AMSAT-DL Upconverter HW:%s FW:%s\n",UPC_HW_VERSION,UPC_SW_VERSION);
    
    printf("ADF4351 INIT (%sMHz)\r\n", (ref)?"10":"40");
    if(ref) {
        adf4351_init(&g_adf4351, 10000UL, 10000UL);
    } else {
        adf4351_init(&g_adf4351, 40000UL, 10000UL);
    }
    printf("ADF4351 SET TUNE\r\n");
    adf4351_set_tune(&g_adf4351, g_ipc, g_pout, TRUE);
    printf("INIT SWITCH\r\n");
    init_switch();
	
    //disable irq priority system
    RCONbits.IPEN = 0;
    //enable all peripheral interrupt sources
    INTCONbits.PEIE = 1;
    //enable all interrupt sources
    INTCONbits.GIE = 1;
    
    //main loop
    for(;;) {
        CLRWDT();
		check_adf4351_lock();
        update_switch();
        update_led();
        pa_update();
		
		for(int i=0; i<EVENT_LOOP_DELAY; i++)
		{
			__delay_ms(1);
			check_usart();
		}
    }
}

/*
static void apply_ipc(int ipc)
{
    g_ipc = ipc;
    adf4351_set_tune(&g_adf4351, g_ipc, g_pout, TRUE);
    printf("ipc set to %i\n", g_ipc); 
}
*/

/*
 * if an external clock is applied AFTER power on, then the adf4351 will not lock properly
 * test for this situation and reinitialize the ADF4351 if required
 * this function is called every EVENT_LOOP_DELAY ms
 * 
 * this function is also used for alarm checking, which is done every ADF_CHECKPERIOD ms
 * 
 */
#define ADF_CHECKPERIOD 1000	
#define MAX_UNLOCK		10

static void check_adf4351_lock(void)
{
	static u16	timespan_s = 0;
	static u8 last_lock = 0;
	static u8 unlock_cnt = 0;
	
	// within a time span of ADF_CHECKPERIOD ms
	// count the unlock or lock/unlock changes
	if(++timespan_s >= (ADF_CHECKPERIOD/EVENT_LOOP_DELAY)) {
		// here every ADF_CHECKPERIOD ms
		
		// measurement values
		// send in standard format
		// and test for alarm conditions
		alarm();
		
		// check if the unlocked situation requires an reinitialization
		if(unlock_cnt > MAX_UNLOCK) {
			printf("ADF4351 RE-INITIALIZE, unlock_cnt:%d\r\n", unlock_cnt);
			printf("UPC 00 08 ADF4351 Re-Init\n");
			adf4351_set_tune(&g_adf4351, g_ipc, g_pout, TRUE);
		}
			
		unlock_cnt = 0;
		timespan_s = 0;
	}
	else {
		// increment the unlock counter if the ADF4351 is not locked or
		// if the lock status changes (lock LED flickering)
		u8 lock = adf4351_get_lock(&g_adf4351);
		
		if(lock == FALSE || lock != last_lock) {
			last_lock = lock;
			unlock_cnt++;
		}
	}
}

// disable PA
static void pa_mute(void)
{
    if(g_ptt_debounce_counter < 0) {
        //PA is unmuted => mute
        printd("PA muted\n");
        adf4351_set_rfout_enable(&g_adf4351, FALSE);
        gpio_set_lvl_low(PIN_PA_ENABLE);
        setPTT_LED(0);
    } else {
        //PA is muted => do nothing
    }
    //reset deboune timer
    g_ptt_debounce_counter = DEBOUNCE_TIME;
}

// enable PA
static void pa_unmute(void)
{
	// enable PA only if no alarm condition
	if(pa_alarm())
		return;
	
    if(g_ptt_debounce_counter > 0) {
        //debounce not done yet => decrement counter and wait
        g_ptt_debounce_counter--;
    } else if(g_ptt_debounce_counter == 0) {
        //debounce done => unmute
        printd("PA unmuted\n");
        g_ptt_debounce_counter--;
        gpio_set_lvl_high(PIN_PA_ENABLE);
        setPTT_LED(1);
        __delay_ms(2);
        adf4351_set_rfout_enable(&g_adf4351, TRUE);
    } else {
        //debounce done and unmuted => do nothing
    }
}

static void setLOCK_LED(u8 onoff)
{
	static u8 old_onoff = 255;
	
	if(onoff != old_onoff)
	{
		printf("UPC 00 04 %d\n",onoff);
		old_onoff = onoff;
	}
	
	if(onoff) {
		gpio_set_lvl_low(PIN_LED_ADF_LOCK);
	} else {
		gpio_set_lvl_high(PIN_LED_ADF_LOCK);
	}
}

static void setPTT_LED(u8 onoff)
{
	static u8 old_onoff = 255;
	
	ptt_status = onoff;
	
	if(onoff != old_onoff)
	{
		printf("UPC 00 06 %d\n",onoff);
		old_onoff = onoff;
	}
	
	if(onoff) {
		gpio_set_lvl_low(PIN_LED_PTT_ACTIVE);
	} else {
		gpio_set_lvl_high(PIN_LED_PTT_ACTIVE);
	}
}

static void pa_update(void)
{
	if(pa_alarm())
	{
		pa_mute();
		return;
	}
	
    if((adf4351_get_lock(&g_adf4351) != FALSE) && (gpio_get_input(PIN_PTT_INPUT) == FALSE)) {
        //locked and PTT aktive => unmute
        pa_unmute();
    } else {
        //not locked or PTT not ative => mute
        pa_mute();
    }
}

/*
 * the serial output of the downconverter can be connected to the RxD of this upconverter
 * read OLED codes from the downconverter and route it to the TxD where an external receiver can
 * get messages from the UPC and the DNC.
 * This allows to write a i.e. Raspi program to display all values
 */
static void check_usart(void)
{
    if(usart_tstc()) 
	{
        int c = usart_getc();
		// c contains a new character from the USART
		// find OLD messages and send it to the serial output
		receive_downconverter_data((u8)c);
    }
}

static u8 read_switch(void)
{
    u8 fsw0, fsw1;

    //read values
    fsw0 = gpio_get_input(PIN_FSW0)?0:1;
    fsw1 = gpio_get_input(PIN_FSW1)?0:1;

    return (fsw0<<0) | (fsw1<<1);
}

static void init_switch(void)
{
    g_pending_cmd = read_switch();
    handle_cmd(g_pending_cmd);
}

static void update_switch(void)
{
    u8 cmd = read_switch();

    //handle read out value
    if(cmd != g_pending_cmd) {
        g_pending_cmd = cmd;
        g_cmd_debounce_counter = DEBOUNCE_TIME;
    } else {
        if(g_cmd_debounce_counter > 0) {
            g_cmd_debounce_counter--;
        } else if(g_cmd_debounce_counter == 0) {
            handle_cmd(g_pending_cmd);
            g_cmd_debounce_counter = DEBOUNCE_TIME;
        }
    }
}

static void update_led(void)
{
static u8 blinkcnt = 0;
static u8 blinkstat = 0;
u16 updatetime = ALIVE_UPDATE_TIME;
static u8 pause = 0;

	if(power_blink > 1)
		updatetime /= 2;

    //update cpu alive led
    if(g_cpu_led_update_cnt++ >= updatetime) 
	{
        if(blinkstat == 0) 
		{
			blinkstat = 1;
			if(power_blink > 1 && ++blinkcnt > power_blink)
			{
				blinkcnt = 0;
				pause = 1;
				return;
			}
			if(pause)
			{
				if(--pause == 0)
					blinkcnt = 0;
			}
			else
				gpio_set_lvl_low(PIN_LED_CPU_OK);
        } 
		else 
		{
			blinkstat = 0;
            gpio_set_lvl_high(PIN_LED_CPU_OK);
        }

        g_cpu_led_update_cnt = 0;
    }
	
    //update ADF lock led
    if(adf4351_get_lock(&g_adf4351) == FALSE) {
        setLOCK_LED(0);
    } else {
        setLOCK_LED(1);
    }
    
}

static void handle_cmd(u8 cmd)
{
    if((cmd != g_applied_cmd) && (cmd < 4)) {
        int timeout = 100;
        
        pa_mute();

        printd("handle_cmd(%i)\r\n",cmd);        
        
        printd("ADF4351 SET FREQ\r\n");
		printf("UPC 00 05 %ld\n",freq_table[cmd]);
		printf("UPC 00 10 %ld\n",2400000 - freq_table[cmd]);
        adf4351_set_freq(&g_adf4351, freq_table[cmd]);
        printd("ADF4351 SET MODE\r\n");
        adf4351_set_mode(&g_adf4351, TRUE);
        
        while((adf4351_get_lock(&g_adf4351) == FALSE) && (timeout>0)) {
            timeout--;
            __delay_ms(1);
        }
        if(timeout <= 0) {
            printf("lock timed out!\n");
			setLOCK_LED(0);
        } else {
			setLOCK_LED(1);
        }
        g_applied_cmd = cmd;
        
        printd("applied_cmd:=%i\r\n",cmd);
        
    }
}

static void init_gpios(void)
{
    ADCON1bits.PCFG = 0xF;

    //
    //PORT A
    //
    //ADF4351 Lock Detect
    gpio_set_dir_in(PIN_ADF_LOCK);
    
    //ADF4351 Chip Enable
    gpio_set_lvl_low(PIN_ADF_CE);
    gpio_set_dir_out(PIN_ADF_CE);
    
    //ADF4351 Latch Enable
    gpio_set_lvl_low(PIN_ADF_LE);
    gpio_set_dir_out(PIN_ADF_LE);
    
    //Serial Data
    gpio_set_lvl_low(PIN_SIO_DATA);
    gpio_set_dir_out(PIN_SIO_DATA);
    
    //Serial Clock
    gpio_set_lvl_low(PIN_SIO_CLK);
    gpio_set_dir_out(PIN_SIO_CLK);

    //LED high/low
    gpio_set_dir_in(PIN_ADF_FREQ_SEL);
    gpio_set_lvl_high(PIN_ADF_FREQ_SEL);

    //PTT input
    gpio_set_dir_in(PIN_PTT_INPUT);
    gpio_set_lvl_high(PIN_PTT_INPUT);

    //
    //PORT B
    //
    INTCON2bits.nRBPU = 0; //enable internal pull-up on Port B
    
    //FSW0
    gpio_set_dir_in(PIN_FSW0);
    gpio_set_lvl_high(PIN_FSW0); //pull-up
    
    //FSW1
    gpio_set_dir_in(PIN_FSW1);
    gpio_set_lvl_high(PIN_FSW1); //pull-up

    //
    //PORT C
    //
    //LED cpu ok
    gpio_set_lvl_low(PIN_LED_CPU_OK);
    gpio_set_dir_out(PIN_LED_CPU_OK);

    //LED lock
    gpio_set_lvl_low(PIN_LED_ADF_LOCK);
    gpio_set_dir_out(PIN_LED_ADF_LOCK);

    //PA
    gpio_set_lvl_low(PIN_PA_ENABLE);
    gpio_set_dir_out(PIN_PA_ENABLE);
    
    //LED PTT active
    gpio_set_lvl_high(PIN_LED_PTT_ACTIVE);        
    gpio_set_dir_out(PIN_LED_PTT_ACTIVE);     
	
	// Alarm Output
	gpio_set_lvl_low(PIN_ALARM_OUTPUT);
    gpio_set_dir_out(PIN_ALARM_OUTPUT);
    
    //Serial TX
    gpio_set_dir_in(PIN_USART_TX);

    //Serial RX
    gpio_set_dir_in(PIN_USART_RX);
}

//retarget for printf
int fputc(int c, FILE *fp)
{
    if(c == '\n') {
        usart_putc('\r');
    }
    usart_putc((char)c);

    return (unsigned char)c;
}
