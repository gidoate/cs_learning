#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(void)
{
    //-------------- CREDIT CARD INPUT --------------//
    unsigned long long n;
    bool validInput;
    do {
        printf("Enter your credit card number (13 to 16 digits): ");
        validInput = scanf("%llu", &n) == 1 && n > 999999999999 && n <= 9999999999999999;
        // Clear the input buffer if the input is invalid
        if (!validInput)
        {
            while (getchar() != '\n'); // Discard invalid input
            printf("Invalid input. Please enter a valid number.\n");
        }
    } while (!validInput);

    //Number of digits
    unsigned long long i=10;
    int digits=1;
    while (n/i>0)
    {
        digits=digits+1;
        i=i*10;   
    }
    // printf("Your card number has %d digits. \n",digits);
    
    //-------------- CHECKSUM CALCULATION --------------//
    // Number of loops
    int loops=digits/2;
    if (digits%2>0)
    {
        loops=loops+1;
    }
    // printf ("There will be %d loops \n", loops);

    // Even numbers checksum addition
    unsigned long long a=100; // divider for the number extraction
    int b=0; // even number checksum addition
    unsigned long long c=0; // internal for even number checksum addition
    unsigned long long x=0; // even numbers
    int x2=0; // even numbers x2
    for (i = 1; i <= loops; i++)
    {
        // printf ("Even Loop number %d \n", i);
        x=n%a;
        // printf("%llu \n",x);
        c=a/10;
        x=x/c;
        // printf("The extracted even number is: %llu \n",x);
        x2=2*x;
        // printf("The addition to the even checksum will be: %d \n",x2);
        b=b+x2;
        // printf("The current even checksum is %d \n",b);
        a=a*100;
    }
    // Odd numbers checksum addition
    unsigned long long d=10; // odivider for the number extractionion
    int e=0; // odd number checksum 
    unsigned long long f=0; //internal for odd number checksum addition
    unsigned long long y=0; // odd numbers
    for (i = 1; i <= loops; i++)
    {
        // printf ("Odd Loop number %d \n", i);
        y=n%d;
        // printf("%llu \n",y);
        f=d/10;
        y=y/f;
        // printf("The extracted odd number is: %llu \n",y);
        // printf("The addition to the even checksum will be: %llu \n",y);
        e=e+y;
        // printf("The current odd checksum is %d \n",e);
        d=d*100;
        // printf("Current d is %d \n",d);
    }
    // Even + Odd
    int checksum=b+e;
    // printf("The card checksum is %d \n", checksum);
    if (checksum%10==0)
    {
        // printf("The card checksum is correct. \n");
    }
    else
    {
        printf("The card checksum is incorrect. Invalid card. \n");
    }

    //-------------- CARD TYPE and FINAL VALIDATION --------------//
    unsigned long long s1=pow(10, digits-1);
    unsigned long long s2=pow(10, digits-2);
    int firstdig=n/s1;
    int firstdigs=n/s2;
    // printf("The first digit is: %d \n", firstdig);   
    // printf("The first two digits are: %d \n", firstdigs);

    // AMEX Check
    if (digits==15 && n/10000000000000 > 33 && n/10000000000000 < 38 && checksum%10==0)
    {
        printf("AMEX\n");
    }
    else if (digits>12 && checksum%10==0)
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