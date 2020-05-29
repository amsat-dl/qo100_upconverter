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
#include "pinmap.h"

//port A
GPIO_DEFINE_PIN_C(PIN_ADF_LOCK,      A, 0)
GPIO_DEFINE_PIN_C(PIN_ADF_CE,        A, 1)
GPIO_DEFINE_PIN_C(PIN_ADF_LE,        A, 2)
GPIO_DEFINE_PIN_C(PIN_SIO_DATA,      A, 3)
GPIO_DEFINE_PIN_C(PIN_SIO_CLK,       A, 4)
GPIO_DEFINE_PIN_C(PIN_ADF_FREQ_SEL,  A, 6)
GPIO_DEFINE_PIN_C(PIN_PTT_INPUT,     A, 7)

//port B
GPIO_DEFINE_PIN_C(PIN_TEMP,          B, 0)
GPIO_DEFINE_PIN_C(PIN_RF_R,          B, 1)
GPIO_DEFINE_PIN_C(PIN_RF_V,          B, 2)
GPIO_DEFINE_PIN_C(PIN_VOLTAGE,       B, 3)
GPIO_DEFINE_PIN_C(PIN_FSW0,          B, 4)
GPIO_DEFINE_PIN_C(PIN_FSW1,          B, 5)

//port C
GPIO_DEFINE_PIN_C(PIN_LED_CPU_OK,    C, 0)
GPIO_DEFINE_PIN_C(PIN_LED_ADF_LOCK,  C, 1)
GPIO_DEFINE_PIN_C(PIN_LED_PTT_ACTIVE,C, 2)
GPIO_DEFINE_PIN_C(PIN_ALARM_OUTPUT,	 C, 3)
GPIO_DEFINE_PIN_C(PIN_PA_ENABLE,     C, 4)
GPIO_DEFINE_PIN_C(PIN_POWER_GOOD,    C, 5)
GPIO_DEFINE_PIN_C(PIN_USART_TX,      C, 6)
GPIO_DEFINE_PIN_C(PIN_USART_RX,      C, 7)
