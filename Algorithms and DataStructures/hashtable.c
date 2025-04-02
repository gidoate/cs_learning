// This implementation does not handle collisions or resizing of the hash table
// It is a simple implementation to demonstrate the concept of a hash table
// The hash function is a simple sum of the ASCII values of the characters in the name
// The hash value is the sum modulo 100

#include <stdio.h>

int hash(char *name)
{
    printf("Entering hash function\n");
    if (name == NULL) {
        printf("Error: name is NULL\n");
        return -1; // Return an error code
    }
    int sum = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        sum += name[i];
    }
    int hash_value = sum % 100;
    return hash_value;
}

int main(void)
{
    int number_of_inputs = 0;
    char input_name[100];
    int ages[100] = {0}; //Size of the hash table
    printf("The age of how many people do you want to enter (max of 100 people)? ");
    scanf("%i", &number_of_inputs);

    for (int i = 0; i < number_of_inputs; i++)
    {
        printf("Name %i: ", i+1);
        scanf("%s", &input_name);
        printf("%p\n", input_name);
        int hash_value = hash(input_name);
        printf("Hash value: %i\n", hash_value);
        printf("Age %i: ", i+1);
        scanf("%i", &ages[hash_value]);
    }

    printf("Who do you want to know the age of? ");
    scanf("%s", &input_name);
    int hash_value = hash(input_name);
    printf("The age of %s is %i", input_name, ages[hash_value]);
    return 0;
}