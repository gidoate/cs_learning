#include <stdio.h>
void miau(int n);

int n = 0; // n declaration and init

int main (void){
    printf("how many miaus? ");
    scanf("%d", &n);
    miau(n);
}

void miau(int n){
    for (int i=0; i<n; i++){
        printf("miau \n");
    }
}