#include <stdio.h>
int main()
{
	int small;

    for(small=97;small<=122;small+=2)
        {
            printf("%c %c ",small,small-31);
        }

	return  0;
}
