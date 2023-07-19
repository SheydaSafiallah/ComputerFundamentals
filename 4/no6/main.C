#include<stdio.h>
int change(char*);
int main(){
    char s[100];
    gets(s);
    change(s);
    printf("%d",change(s));
}
int change(char*s){
    int a=0;
    while (*s) {
        if((*s>='0')&(*s<=9)){
            a=a*10+(*s+=48);}
    }
    return a;
}
