#include<stdio.h>
int intDivisor(int*, int*);
int main()
{
    int x,y;
    intDivisor(&x,&y);
    printf("%d",x);
}
int intDivisor(int *x,int *y){
    printf("enter 2 numbers:\n");
    scanf("%d%d",x,y);
    return *x/=*y;
}
