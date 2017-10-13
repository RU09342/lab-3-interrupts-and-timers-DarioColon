#include <msp430.h> // Allows use of keywords like PxDIR or PxOUT

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 = 0xFFFE; // Disable high-impedance mode
	P1DIR = BIT0; // Set pin1.0 as output
	P1IE = BIT1; // Enable interrupt at pin1.1
	P1IES = BIT1; // Works from high to low edge
	P1REN = BIT1; // Enable pullup resistor on switch S1
	P1OUT = BIT1; // Turn on pullup resistor
	P1IFG = 0x00; // Clear interrupt flag

	__bis_SR_register(LPM4_bits + GIE); // Enter low power mode at interrupt
}

#pragma vector=PORT1_VECTOR
__interrupt void Port_1(void)
{
    if((P1IES&BIT1)) // Force LED on while S1 is pressed
    {
        P1OUT |= BIT0;
        P1IES &= ~BIT1;
    }
    else if(~(P1IES&BIT1)) // Force LED off while S1 is not pressed
    {
        P1OUT &= ~BIT0;
        P1IES |= BIT1;
    }
    P1IFG = 0x00; // Clear interrupt flag
}
