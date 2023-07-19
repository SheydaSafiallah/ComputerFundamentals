#include <stdio.h>
int pow(int a);
int main()
{
    int m,n,i=-10,j=1,sum=0;
    scanf("%d%d",&m,&n);
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++)
        {
            sum+=pow(i+j)/(j*j);

        }
    }

    return 0;
}
int pow(int a){
    int b;
    b=a*a*a;
    return b;
}
