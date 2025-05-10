#include <stdio.h>

typedef struct 
{
    char *name[50];
    int age;
    int mark;
}student;

int main (void)
{
    student student1;
    student student2;

    printf("Input the name of the first student: ");
    scanf("%s", &student1.name);
    printf("Input the name of the second student: ");
    scanf("%s", &student2.name);
    printf("Input the age of the first student: ");
    scanf("%i", &student1.age);
    printf("Input the age of the second student: ");
    scanf("%i", &student2.age);
    printf("Input the mark of the first student: ");
    scanf("%i", &student1.mark);
    printf("Input the mark of the second student: ");
    scanf("%i", &student2.mark);
    printf("\n");
    printf("Names: %s | %s\n", student1.name, student2.name);
    printf("Ages:  %i | %i\n", student1.age, student2.age);
    printf("Marks: %i | %i\n", student1.mark, student2.mark);
}