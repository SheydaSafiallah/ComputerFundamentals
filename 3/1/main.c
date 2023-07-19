#include<stdio.h>

int Prime(int a){
    int i;
    for(i=2;i<a;i++)
    {
      if(a%i==0)
          return 0;
    }
  return 1;
}

int main()
{
  int a,b,i,d = 0;
  scanf("%d%d",&a,&b);
  if(a==0)
      a+=1;


  for(i=a+1;i<b;i++)
  {
    if(Prime(i)){
        printf("%d",i);
        break;}
  }
  d=i;



  for(i=d+1;i<b;i++)
  {
    if(Prime(i))
        printf(",%d",i);
  }
  return 0;
}
