#include "blinkFrequency.h"

int blinkFrequency(int Hz) //
{
    int count = 125000 / Hz; // We are using SMCLCK / 8, which is 125KHz

    if(count > 65536) // Since Timer A is a 16-bit timer, it can only go up to 2^16 = 65536
        return 65536;

    else
        return count;
}
