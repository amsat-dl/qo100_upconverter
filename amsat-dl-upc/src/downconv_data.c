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
 * downconv_data.c
 *
 *  Created on: 21.11.2019
 *      Author: kurt
 */

#include <config.h>
#include <pinmap.h>
#include <stdio.h>
#include <string.h>
#include <driver/usart.h>
#include <downconv_data.h>

/*
 * format of messages from Downconverter:
 * "OLD xx yy text\n"
 * OLD ... header
 * xx .... x position if OLED display
 * yy .... y  position if OLED display
 * text .. text written into OLED display
 *
 * all messages without the "OLD " header are debug messages and must be ignored
 */

#define DOWN_MAXRXLEN 100

u8 down_rxbuf[DOWN_MAXRXLEN+1]; // one extra byte for string terminator
u8 down_rxidx = 0;

void receive_downconverter_data(u8 rxdatabyte)
{
static u8 idx = 0;

	switch(idx)
	{
	case 0: if(rxdatabyte == 'O')
			{
				idx++;
			}
			break;
	case 1: if(rxdatabyte == 'L')
			{
				idx++;
			}
			else
				idx = 0;
			break;
	case 2: if(rxdatabyte == 'D')
				idx++;
			else
				idx = 0;
			break;
	case 3:
			if(rxdatabyte == ' ')
			{
				// header found, read all data until '\n'
				down_rxidx = 0;
				idx++;
			}
			else
				idx = 0;
			break;

	case 4:	// read all data until '\n'
			if(down_rxidx >= DOWN_MAXRXLEN)
			{
				// too long, ignore
				idx = 0;
				break;
			}

			down_rxbuf[down_rxidx++] = rxdatabyte;

			if(rxdatabyte == '\n')
			{
				// finished
				down_rxbuf[down_rxidx] = 0;	// string terminator
				
				// an OLD message was received from the downconverter
				// just send it out
				printf("OLD %s",down_rxbuf);
				
				idx = 0;
				break;
			}
			break;
	}
}
