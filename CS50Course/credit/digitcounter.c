#include "digitcounter.h"

int digitcounter(unsigned long long n)
{
    unsigned long long i=10;
    int digits=1;
    while (n/i>0)
    {
        digits=digits+1;
        i=i*10;  
    } 
    printf("Your card number has %d digits. \n",digits);

    return digits;
}