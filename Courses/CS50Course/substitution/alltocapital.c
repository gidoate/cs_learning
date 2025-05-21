#include "alltocapital.h"

void alltocapital(char* word)
{
    int i=0;
    while (word[i]!='\0')
        {
            if (word[i]>96 && word[i]<123)
            {
                word[i]=word[i]-32;
            }
            i++;
        }
}