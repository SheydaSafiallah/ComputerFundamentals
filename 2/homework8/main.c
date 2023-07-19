#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c;
    float delta,x,y;
    scanf("%d%d%d",&a,&b,&c);
    delta = (b*b) - (4*a*c);
    if(a!=0)
        {

        if(delta > 0)
        {
        x = (-b + sqrt(delta))/(2*a);
        y = (-b - sqrt(delta))/(2*a);
        if(x>y)
        {
            printf("%0.3f\n%0.3f",y,x);
        }
        else
            printf("%0.3f\n%0.3f",x,y);
        }



        else if(delta == 0)
        {
        x = (-b)/(2*a);
        printf("%0.3f",x);
        }


        else if(delta < 0)
        {
            printf("IMPOSSIBLE");
        }
        }
        else
        x = (-c)/b;
        printf("%0.3f",x);
    return 0;
}
