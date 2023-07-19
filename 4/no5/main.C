#include<stdio.h>
int main(){
    char arr[100];
    gets(arr);
    char *ptr;
    ptr=arr;
    printf("%s\n",ptr);
    return 0;
}
