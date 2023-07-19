#include <stdio.h>

int main() {
    long int n,x,y,a,b;
    scanf("%ld",&n);
    if(n==0)
        printf("0 0");
    else if(n==1)
        printf("1 0");
    else if(n==2)
        printf("1 1");

    else {

        a=n-2;
        x=a/4;
        x++;

        a%=4;



        b=n-3;
        y=b/4;
        y++;

        b%=4;

        if(a==0||a==1)
            printf("%ld ",x);

        else
            printf("%ld ",-x);

        if(b==0||b==1)
            printf("%ld",y);

        else
            printf("%ld",-y);
    }
    return 0;

}
