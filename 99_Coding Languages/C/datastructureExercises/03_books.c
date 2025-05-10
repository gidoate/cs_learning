#include <stdio.h>

typedef struct 
{
    char *title;
    char *author;
    int price;
}book;

int main(void)
{

    book book1;
    book book2;
    book book3;

    printf("Input the title of book number 1: ");
    scanf("%s", &book1.title);    
    printf("Input the author of book number 1: ");
    scanf("%s", &book1.author);
    printf("Input the price (in euros) of book number 1: ");
    scanf("%i", &book1.price);

    printf("Input the title of book number 2: ");
    scanf("%s", &book2.title);    
    printf("Input the author of book number 2: ");
    scanf("%s", &book2.author);
    printf("Input the price (in euros) of book number 2: ");
    scanf("%i", &book2.price);

    printf("Input the title of book number 3: ");
    scanf("%s", &book3.title);    
    printf("Input the author of book number 3: ");
    scanf("%s", &book3.author);
    printf("Input the price (in euros) of book number 3: ");
    scanf("%i", &book3.price);

    int maxprice = 0;
    char *maxtitle = NULL;
    char *maxauthor = NULL;
    if (book1.price > book2.price && book1.price > book3.price)
    {
        maxprice = book1.price;
        maxtitle = book1.title;
        maxauthor = book1.author;
    }
    else if (book2.price > book3.price)
    {
        maxprice = book2.price;
        maxtitle = book2.title;
        maxauthor = book2.author;
    }
    else
    {
        maxprice = book3.price;
        maxtitle = book3.title;
        maxauthor = book3.author;
    }
    
    printf("\nThe most expensive book is %s, written by %s and which cost %i", maxtitle, maxauthor, maxprice);
}