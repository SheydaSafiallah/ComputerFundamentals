#include<stdio.h>
int main(){
    int x=10;
    int *xprt;
    xprt = &x;
    printf("%p , %p\n",&x,xprt);
    printf("%d\n",*(xprt)+1);
    printf("%d\n",*xprt*2);
    return 0;
}
