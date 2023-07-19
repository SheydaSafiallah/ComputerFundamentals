#include <stdio.h>
int main()
{
    float x ,y;
    scanf("%f", &x);
        if (x>0 && x<=2)
        {
            y =  x / 2 ;
            printf("%f",y);
        }
        else if (x>2 && x<=3)
        {
            y = x / 3 ;
            printf("%f",y);
        }
        else
        printf("Invalid number!");
    return 0;
}
