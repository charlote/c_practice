#include <stdio.h>
#include <stdlib.h>

typedef struct data
{
    int value;
    struct data *pre;
    struct data *next;
} DATA;

void show_menu();

void main()
{
    DATA *mydata, *head;
    int cho;

    mydata = malloc(sizeof(DATA));
    head = mydata;
    mydata->pre = NULL;
    mydata->next = NULL;
    do{
        show_menu();
        scanf("%d", &cho);
        switch(cho)
        {
            case 1:
                mydata = head;
                while(mydata->next != NULL){
                    printf("%d\n", mydata->value);
                    mydata = mydata->next;
                }
                if(mydata->pre != NULL){
                    mydata = mydata->pre;   //back to before the NULL_next
                }
                break;
            case 2:
                while(mydata->next != NULL){
                    mydata = mydata->next;
                }
                printf("Please input value:");
                scanf("%d", &mydata->value);
                mydata->next = malloc(sizeof(DATA));
                mydata->next->pre = mydata;
                mydata->next->next = NULL;
                break;
            case 3:
                printf("Input the new one:");
                scanf("%d", &(mydata->value));
                break;
            case 4:
                if(mydata->pre != NULL){
                    mydata = mydata->pre;
                }
                break;
            case 5:
                if((mydata->next != NULL) && (mydata->next->next != NULL)){
                    mydata = mydata->next;
                }
                break;
            case 6:
                if(mydata->pre != NULL){
                    mydata->pre->next = malloc(sizeof(DATA));
                    mydata->pre->next->next = mydata;
                    mydata->pre->next->pre = mydata->pre;
                    mydata->pre = mydata->pre->next;
                    mydata = mydata->pre;
                    printf("Input a number:");
                    scanf("%d", &(mydata->value));
                } else {
                    mydata->pre = malloc(sizeof(DATA));
                    mydata->pre->next = mydata;
                    mydata->pre->pre = NULL;
                    mydata = mydata->pre;
                    head = mydata;
                    printf("Input a number:");
                    scanf("%d", &(mydata->value));
                }
                break;
            case 7:
                if((mydata->pre != NULL) || (mydata->next != NULL)){    // not the number one struct
                    mydata->pre->next = mydata->next;
                    mydata->next->pre = mydata->pre;
                    DATA *tmp = mydata;
                    mydata = mydata->pre;
                    free(tmp);
                } else {
                    mydata = mydata->next;
                    free(mydata->pre);
                    mydata->pre = NULL;
                    head = mydata;
                }
                break;
            case 8:
                mydata = head;
                while(mydata->next != NULL){
                    mydata = mydata->next;
                    free(mydata->pre);
                }
                mydata->pre = NULL;
                head = mydata;
                break;
        }
    } while(cho != 9);
}

void show_menu(){
    printf("1)List 2)Add 3)Edit\n");
    printf("4)Move Pre. 5)Move Next 6)Insert 7)Delete\n");
    printf("8)Clear all 9)Exit:");
}
