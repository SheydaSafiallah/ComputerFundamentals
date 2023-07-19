#include <stdio.h>
#include <math.h>
#define PI 3.1415
int main()
{
    float r , a;
    int x;

    printf("enter the radius : \n");
    scanf("%f", &r);
    printf("What do you want to be calculated? \n 1: area \n 2: perimeter \n 3: diameter \n Enter your choice Please: \n");
    scanf("%d",&x);

        switch (x)
        {
            case 1:

                a = PI * r * r;
                printf("area = %f" ,a);
                break;
            case 2:
                a = 2 * r * PI;
                printf("perimeter = %f" ,a);
                break;
            case 3:
                a = 2 * r;
                printf("diameter = %f" ,a);
                break;
            default :
                printf("invalid");
        }
        return 0;
}
