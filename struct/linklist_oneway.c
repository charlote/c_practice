#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int value;
    struct data *next;
} DATA;

void main()
{
    DATA *mydata, *head;
    int tmpv;
    
    mydata = malloc(sizeof(DATA));
    head = mydata;
    do{
        printf("Please input anumber(0 for exit):");
        scanf("%d", &tmpv);
        mydata->value = tmpv;
        mydata->next = malloc(sizeof(DATA));
        mydata = mydata->next;
    } while(tmpv != 0);
    mydata->next = NULL;
    mydata = head;
    do{
        printf("%d\n", mydata->value);
        mydata = mydata->next;
    } while(mydata->next != NULL);
}
