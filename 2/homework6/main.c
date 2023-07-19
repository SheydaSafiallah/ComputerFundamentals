#include <stdio.h>
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>0 && b>0 && c>0)
    {

    if(a>b && a>c)
    {
        if(a*a == (b*b + c*c))
        {
            printf("YES");
        }
        else
            printf("NO");
    }
    else if(b>a && b>c)
    {
        if(b*b == (a*a + c*c))
        {
            printf("YES");
        }
        else
            printf("NO");

    }
       else if(c>a && c>b)
    {
        if(c*c == (a*a + b*b))
        {
            printf("YES");
        }
        else
            printf("NO");

    }

    }
    else
        printf("NO");
        return 0;
}
