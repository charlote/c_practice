/* to calculate the day of week
 * 1. input the target year and the day of week for the first day(01/01)
 * 2. input how many times do you went to calculate
 * 3. input the dates
 * 4. output the day of week
 */

#include <stdio.h>

void main()
{
    int i, j, x, y, count, mon, day, tmp, day_f, total;
    int ans[10];
    printf("input the year and the first day:\n");
    scanf("%d %d", &x, &y);
    printf("input the times:\n");
    scanf("%d", &count);
    printf("input dates:\n");
    if((x % 400 == 0) || ((x % 4 == 0) && x % 100))
        x = 1;
    else
        x = 0;
    for(i=0;i<count;i++){
        total = 0;
        day_f = 0;
        scanf("%d %d", &mon, &day);
        if((mon < 1) || (mon > 12)){
            ans[i] = -1;
            continue;
        }
        switch(mon){
            case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                if(day > 31)
                    day_f = 1;
                break;
            case 2:
                if((x && day>29) || ((!x) && day>28))
                    day_f = 1;
                break;
            case 4: case 6: case 9: case 11:
                if(day > 30)
                    day_f = 1;
                break;
            }
        if((day_f) || (day <= 0) || (day > 32)){
            ans[i] = -2;
            continue;
        }
        for(j=1;j<mon;j++){
            switch(j){
                case 1: case 3: case 5: case 7: case 8: case 10: case 12:
                    total += 31;
                    break;
                case 2:
                    if(x) total += 29;
                    else total += 28;
                    break;
                case 4: case 6: case 9: case 11:
                    total += 30;
            }
        }
        ans[i] = (y + total + day - 1) % 7;
    }
    for(i=0;i<count;i++)
        printf("%d ", ans[i]);
}
