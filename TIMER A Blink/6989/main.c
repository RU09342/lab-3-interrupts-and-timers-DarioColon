#include <msp430.h> // Allows use of keywords like PxDIR or PxOUT
#include "blinkFrequency.h"

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5; // Disable high-impedance mode

	// Set both LEDs as outputs
	P1DIR |= BIT0;
	P9DIR |= BIT7;

	// Initialize both LEDs to be off
	P1OUT &= ~BIT0;
	P9OUT &= ~BIT7;

	TA0CCTL0 = CCIE; // Enable interrupt (CCIE: "Capture/Compare Interrupt Enable")
	TA0CTL = TASSEL_2 + MC_1 + ID_3; // Set timer A to SMCLCK/8 using up mode

    TA0CCR0 = blinkFrequency(4); // LEDs will toggle 4 times / second

	__bis_SR_register(LPM0_bits + GIE); // Enter low power mode at interrupt
}

#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
{
        P1OUT ^= BIT0;
        P9OUT ^= BIT7;
}
