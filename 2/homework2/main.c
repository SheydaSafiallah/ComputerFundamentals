#include <stdio.h>
#include <math.h>

int main()
{
    float a,b,c,delta,x,y;
    scanf("%f%f%f",&a,&b,&c);
    delta = (b*b) - (4*a*c);

    if(a==0 && b==0 || delta < 0)
    {
        printf("IMPOSSIBLE");
        return 0;
    }

    if(a==0)
    {
        x = (-c)/b;
        printf("%0.3f",x);
        return 0;
    }

    x = (-b + sqrt(delta))/(2*a);
    y = (-b - sqrt(delta))/(2*a);
    if(x>y)
        printf("%0.3f\n%0.3f",y,x);
    else if (x<y)
        printf("%0.3f\n%0.3f",x,y);
    else
        printf("%0.3f",x);
    return 0;
}
