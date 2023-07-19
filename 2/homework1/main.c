#include<stdio.h>

int main()
{
    int x,n;
    double sum=0,division=1;
    scanf("%d%d",&x,&n);
    for(int i=1;i<=n;i++){

        sum += division;

    division = (division*x)/i;

    }
    printf("%0.3f",sum);
    return 0;
}
