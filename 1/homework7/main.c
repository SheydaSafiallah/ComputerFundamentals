#include <stdio.h>
int main()
{
    int n , m , t;
    scanf("%d%d",&n,&m);
        if(n>m)
            {
            printf("max = %d",n);
        }

        else
        {
          t = n;
          n = m;
          m = t;
            printf("max = %d",n);
        }
    return 0;
}
