#Overview

This project has an extra source file and header file (blinkFrequency). More information is available in the "blinkFrequency" section.

1. Stop Watchdog timer
2. Disable high-impedance for FR boards
3. Set both LEDs as outputs
4. Initialize both LEDs to be off (If this is not done, the LEDs will alternate blinks)
5. Enable interrupt (Note: Some boards have more than one set of registers. These boards specify which registers are which by using the label TAxCCRy where x and y are integers. This project was done on an FR6989, which uses this designation)
6. Set timer A to SMCLCK / 8 using up mode
7. Set CCR0 to blinkFrequency(Hz). This causes Timer A to only count up to the value of CCR0, which is explained in the "blinkFrequency" section of this ReadMe.
8. Enter low power mode

In the Timer A vector, all that needs to be done is to toggle the LEDs by toggling their value with itself.

##blinkFrequency

blinkfrequency() is a function whose input is the frequency of LED blinks in Hz and returns the necessary value of CCR0.
It creates an integer called "count" whose value is equal to (SMCLCK / 8) / Hz. However, since Timer A can only count up to 2^16, the function contains an if statement which returns 65536 if the value of count remains greater than 65536, and just returns the normal value of count otherwise.
