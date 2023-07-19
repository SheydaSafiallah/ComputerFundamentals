#include<stdio.h>
void sum(double*, double*);
int main()
{
    double x,y;
    sum(&x,&y);
}
void sum(double *x,double *y){

    scanf("%lf%lf",x,y);
    double z;
    z=(*x + *y);
    printf("%lf",z);

}
