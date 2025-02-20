#include <stdio.h>

typedef struct 
{
    char name[50];
    char ID[50];
    float salary;
}employee;


int main(void)
{
    employee employees[3];

    for (int i = 0; i < 3; i++)
    {
        printf("Enter the name of employee number %i: ", i);
        scanf("%s", &employees[i].name);
        printf("Enter the ID of employee number %i (format: X-0000): ", i);
        scanf("%s", &employees[i].ID);
        printf("Enter the salary of employee number %i: ", i);
        scanf("%f", &employees[i].salary);
    }
    if (employees[1].salary > employees[2].salary && employees[1].salary > employees[3].salary)
    {
        printf("The employee with highest salary is %s, with ID number %s and who earns %.2f euros a year", employees[1].name, employees[1].ID, employees[1].salary);
    }
    else if (employees[2].salary > employees[3].salary)
    {
        printf("The employee with highest salary is %s, with ID number %s and who earns %.2f euros a year", employees[2].name, employees[2].ID, employees[2].salary);
    }    
    else
    {
        printf("The employee with highest salary is %s, with ID number %s and who earns %.2f euros a year", employees[3].name, employees[3].ID, employees[3].salary);
    }
}