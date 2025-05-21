#include "checksum.h"

int checksum (int digits, unsigned long long n)
    {
    //-------------- CHECKSUM CALCULATION --------------//
    // Number of loops
    int loops=digits/2;
    if (digits%2>0)
    {
        loops=loops+1;
    }

    // Even numbers checksum addition
    unsigned long long a=100; // divider for the number extraction
    int b=0; // even number checksum addition
    unsigned long long c=0; // internal for even number checksum addition
    unsigned long long x=0; // even numbers
    int x2=0; // even numbers x2
    for (int i = 1; i <= loops; i++)
    {
        x=n%a;
        c=a/10;
        x=x/c;
        x2=2*x;
        b=b+x2;
        a=a*100;
    }
    // Odd numbers checksum addition
    unsigned long long d=10; // odivider for the number extractionion
    int e=0; // odd number checksum 
    unsigned long long f=0; //internal for odd number checksum addition
    unsigned long long y=0; // odd numbers
    for (int i = 1; i <= loops; i++)
    {
        y=n%d;
        f=d/10;
        y=y/f;
        e=e+y;
        d=d*100;
    }
    // Even + Odd
    int checksum=b+e;
    printf("The card checksum is %d \n", checksum);
    if (checksum%10==0)
    {
        printf("The card checksum is correct. \n");
    }
    else
    {
        printf("The card checksum is incorrect. Invalid card. \n");
    }

    return checksum;
    }
    