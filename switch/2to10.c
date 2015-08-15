#include <stdio.h>

void main()
{
    int i, j;
    int k=128;

    printf("Enter a number:");
    scanf("%d", &i);
    for(j=1;j<=8;j++){
        printf("%d", (i&k) && 1);
        k = k >> 1;
    }
    printf("\n");
}
