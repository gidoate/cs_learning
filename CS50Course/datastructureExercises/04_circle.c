#include <stdio.h>

typedef struct 
{
    float r; //radious of the circle
    float perimeter; //perimeter of the circle
    float area; //area of the circle 
}circle;

int main(void)
{
    circle circles [2];
    for (int i = 0; i < 2; i++)
    {
        printf("Input the radius of circle %i: ", i);
        scanf("%f", &circles[i].r);
    }
    
    for (int i = 0; i < 2; i++)
    {
        circles[i].perimeter = 2 * 3.14159 * circles[i].r;
        circles[i].area = 3.14159 * circles[i].r * circles[i].r;
    }
    
    for (int i = 0; i < 2; i++)
    {
        printf("Radius of circle %i is: %f\n", i, circles[i].r);
        printf("Perimeter of cirlce %i is: %f\n", i, circles[i].perimeter);
        printf("Area of circle %i is: %f\n", i, circles[i].area);
    }
    


}
