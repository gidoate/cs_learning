#include <stdio.h>

int main(void)
{
    char name[10];
    char surname[10];
    char date[10];
    printf("what's your name? ");
    scanf("%s", &name);
    printf("what's your surename? ");
    scanf("%s", &surname);
    printf("what's your date of birth? ");
    scanf("%s", &date);
    printf("Hi, %s %s, born in year %s", name, surname, date);
}