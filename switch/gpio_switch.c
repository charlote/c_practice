#include<stdio.h>

void main()
{
    char value = 0;
    int i, k, tmp, cho, dev;

    do{
        k = 128;
        printf("current value:");
        for(i=1;i<=8;i++){
            printf("%d", (value&k) && 1);
            k = k >> 1;
        }
        printf("\n");
        printf("Input:\n");
        printf("1)turn on 2)turn off 0)exit\n");
        printf("enter your choice:");
        scanf("%d", &cho);
        switch(cho){
            case 1:
                printf("which device turn on(1~8):");
                scanf("%d", &dev);
                k = 128;
                k = k >> (dev-1);
                value = value|k;
                break;
            case 2:
                printf("which device turn off(1~8):");
                scanf("%d", &dev);
                k = 128;
                k = k >> (dev-1);
                tmp = ~k;
                value = value&tmp;
                break;
        }
    } while(cho != 0);
}
