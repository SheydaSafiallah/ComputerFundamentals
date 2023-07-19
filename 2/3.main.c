#include<stdio.h>

int pow(int x, int n)
{
    int p = 1;
    for(int i=1;i<=n;i++)
    {
        p*=x;
    }
    return p;
}
int fact(int n)
{
    int f = 1;
    for(int i=1;i<=n;i++)
    {
        f*=i;
    }
    return f;
}
int main()
{
    double sum = 0;
    int n,x;
    scanf("%d%d",&x,&n);
    for(int i=1;i<=n;i++){
        sum += (double) pow(x,i-1) / fact(i-1);
    }
    /*int x,n,fact=1,pow=1;
    double sum=0,division=1;
    scanf("%d%d",&x,&n);
    for(int i=1;i<=n;i++){

        division = ((double)pow/fact);
        fact*=i;
        pow *= x;
        sum += division;


    }

    */
    printf("%f",sum);
    return 0;
}
