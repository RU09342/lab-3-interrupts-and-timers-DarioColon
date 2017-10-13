#include <msp430.h> 

int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	// stop watchdog timer
	PM5CTL0 &= ~LOCKLPM5; // Disable high-impedance mode
	P1DIR |= BIT0; // Set LED as output
	P1REN |= BIT1; // Enable pullup resistor
	P1OUT |= BIT1; // Turn on pullup resistor
	P1IE |= BIT1; // Enable interrupt when button S1 is pressed
	P1IES |= BIT1; // High to low edge
	P1IFG &= ~BIT1; // Clear interrupt flag

	// Initialize LEDs to begin off
	P1OUT &= ~BIT0;
	P9OUT &= ~BIT7;
	
	TA0CCTL0 = CCIE; // Enable interrupt (CCIE: "Capture/Compare Interrupt Enable")
	TA0CTL = TASSEL_2 + MC_2 + ID_3; // Set timer A to SMCLCK / 8 using continuous mode

	TA0CCR0 =

	__bis_SR_register(LPM0_bits + GIE); // Enter low power mode at interrupt
}



#pragma vector=TIMER0_A0_VECTOR
__interrupt void Timer_A (void)
