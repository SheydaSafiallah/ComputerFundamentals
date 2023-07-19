#include <stdio.h>
int main()
{
    int a,max,i;
    scanf("%d",&a);
    max = a;
    for(i=1;i<=2;i++)
    {
        scanf("%d",&a);

        if(a > max){
            max = a;
        }
    }
    printf ("%d",max);

    return 0;
}
