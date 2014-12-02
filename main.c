/*
 * menu.c
 * 
 * Copyright 2014 pepcio03 <piotrk0303@gmail.com>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


//*****************************************************************************
//
// main.c - Program prezentujacy obsluge UARTa
//
//*****************************************************************************


#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/debug.h"
#include "driverlib/gpio.h"
#include "driverlib/interrupt.h"
#include "driverlib/sysctl.h"
#include "driverlib/timer.h"
#include "drivers/osram128x64x4.h"
#include "driverlib/adc.h"
#include "driverlib/pwm.h"
#include "driverlib/systick.h"
#include "driverlib/uart.h"
#include <stdio.h>
#include <string.h>
#include "audio.h"

		char bufor[50];
		int i;
		//char uart;
		char uartc[50];
		//char komenda[10];
		char opcja[5];
		unsigned long q;
		unsigned int l;
		unsigned int p;
//*****************************************************************************
// Funkcja obs³ugi przerwania portu UART.
//*****************************************************************************
void
UARTIntHandler(void)
{
	
	unsigned long ulStatus;
	// Get the interrrupt status.
	
	ulStatus = UARTIntStatus(UART0_BASE, true);
	// Clear the asserted interrupts.
	UARTIntClear(UART0_BASE, ulStatus);
	
	
	// Loop while there are characters in the receive FIFO.
	i =1 ;
	while(UARTCharsAvail(UART0_BASE))
	{
		uart = UARTCharNonBlockingGet(UART0_BASE);
		l = UARTCharNonBlockingGet(UART0_BASE);
	}
}
//*****************************************************************************
// Wys³anie ci¹gu znaków do portu UART.
//*****************************************************************************
void
UARTSend(const unsigned char *pucBuffer, unsigned long ulCount)
{
// Loop while there are more characters to send.
	while(ulCount--)
	{
		// Write the next character to the UART.
		UARTCharNonBlockingPut(UART0_BASE, *pucBuffer++);
	}
	
}
//*****************************************************************************
// Pêtla g³ówna program
//*****************************************************************************
int main(void)
{
		// Set the clocking to run directly from the crystal.
		SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |
		SYSCTL_XTAL_8MHZ);
		// Initialize the OLED display and write status.
		OSRAM128x64x4Init(1000000);
		// Enable the peripherals used by this example.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
		// Enable processor interrupts.
		IntMasterEnable();
		// Set GPIO A0 and A1 as UART pins.
		GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
		// Configure the UART for 115,200, 8-N-1 operation.
		UARTConfigSet(UART0_BASE, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));
		// Enable the UART interrupt.
		IntEnable(INT_UART0);
		UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
		// Prompt for text to be entered.
		UARTSend((unsigned char *)"Enter text: ", 12);
		// Loop forever echoing data through the UART.
		
		
	while(1)
	{
		
		if(i == 1){
			uartc[q++] = uart;
			//q++;
			i = 0;
			//sprintf(bufor, "%s", uartc);
			//OSRAM128x64x4StringDraw(bufor, 12, p, 15);
			
			////////////////////////////////////////////
			//13=CR, 10=LF, 45=myslinik, 32=SPACJA
			////////////////////////////////////////////
			if (l==13 || l==10)
			{
				unsigned int j = 0;
				int cmp = 0;
				unsigned int spacja, myslnik;
				/*
				for(j=0;j<10;j++)
				{
					if(uartc[j] == 32 ) spacja = 1;
					
					if(spacja == 0)
					{
						komenda[j] == uartc[j];
					}	
					else 
					{
						 break;
					}
				}
				*/
			}
		}
	}
	
}

void komendy(char uartc[]){
	cmp  = strncmp(uartc,"time",4)
	if(cmp == 0)
	{
		for(j=0;j<50;j++)
		{
			if(uartc[j] == 45 ){
			if(uartc[(j+1)]=="h")
			{
				
			}
			
			}
			
		}
	}
	
}
