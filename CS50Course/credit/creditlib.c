#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "checksum.h"
#include "digitcounter.h"
#include "userinput.h"
#include <time.h>

void wait(int seconds) {
    clock_t end_wait = clock() + seconds * CLOCKS_PER_SEC;
    while (clock() < end_wait);
}
int main(void)
{
    //-------------- CREDIT CARD INPUT --------------//
    unsigned long long n = userinput();

    //-------------- NUMBER OF DIGITS --------------//
    int digits = digitcounter(n);

    //-------------- CHECKSUM CALCULATION --------------// 
    int checksumresult = checksum(digits, n);

    //-------------- CARD TYPE and FINAL VALIDATION --------------//
    unsigned long long s1=pow(10, digits-1);
    unsigned long long s2=pow(10, digits-2);
    int firstdig=n/s1;
    int firstdigs=n/s2;
    // AMEX Check
    if (digits==15 && n/10000000000000 > 33 && n/10000000000000 < 38 && checksumresult%10==0)
    {
        printf("AMEX\n");
    }
    else if (digits>12 && checksumresult%10==0)
    {
        // printf("We are here \n");
        if (firstdigs>50 && firstdigs<56)
        {
            printf("MASTERCARD\n");
        }
        else if (firstdig==4)
        {
            printf("VISA \n");
        }
        else
        {
            printf("INVALID \n");
        }   
    }
    return 0;
}