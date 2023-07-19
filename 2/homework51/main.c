#include <stdio.h>

int main()
{
    int number, i, k, count = 1;
     scanf("%d", &number);
    count = number - 2;
    if(number==1)
        printf("*");
    else{

    for (k = 1; k <= number/2 +1; k++)
    {
        for (i = 1; i <= count; i+=2)
            printf(" ");
        count-=2;
        for (i = 1; i <= 2 * k - 1; i++)
            printf("*");
        printf("\n");
     }


    //second
count = 1;

        for (k = 1; k <= number/2; k++)
    {
            for (i = 1; i <= count; i+=2)
                printf(" ");
            count+=2;
            for (i = number; i <= 2 * (number-k )- 1; i++)
                printf("*");
            printf("\n");
     }
    }
      return 0;
}
