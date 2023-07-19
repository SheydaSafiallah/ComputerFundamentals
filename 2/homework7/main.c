#include <stdio.h>
int main()
{
    int x,i,d=0;
    scanf("%d",&x);
    for(i=1;i<x;i++){
        if(x%i==0)
        {
            d=i+d;
        }

    }
    if(d==x)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
    return 0;
}
