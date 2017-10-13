#Overview

1. Disable Watchdog
2. For FR boards, disable high-impedance mode
3. Set P1.0 as output
4. Enable interrupt at button press.

G2553: P1.3
F5529: P2.1
FR5994: P5.6
FR2311: P1.1

5. Specify whether the interrupt service will trigger from hi to low edges or vice versa. main.c works from high to low edge.
6. Enable pullup resistors on buttons
7. Turn on pullup resistors
8. Clear interrupt flag
9. Enter low power mode

For the interrupt:
1. Force LED on while interrupt service is happening using if (P1IES & BITx) where BITx is the button pin.
2. If the button is not being pressed, turn off the LED
3. Clear interrupt flag