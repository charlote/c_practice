/* Bingo
 * 1. input the number of player and the size of bingo
 * 2. input the players 
 * 3. input the bingo 
 * 4. output the number of bingo and the winers
 */

#include <stdio.h>

void main()
{
    int n, m, h, i, j, k, x1, y1;
    int a[10][256*256];
    int result;
    int x[10][256] = {{0}};     // init 2-d-array
    int y[10][256] = {{0}};
    int z[10][2] = {{0}};
    int winer[10] = {0};        //init 1-d-array
    int out = 0;
    
    printf("input the number of player and size of bingo:\n");
    scanf("%d", &n);
    scanf("%d", &m);
    printf("input the players:\n");
    for(i=0;i<n;i++){
        for(j=0;j<m*m;j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("input the result:\n");
    while(!out){
        scanf("%d", &result);
        for(i=0;i<n;i++){
            for(j=0;j<(m*m);j++){
                if(result == a[i][j]){
                    x1 = j % m;
                    y1 = j / m;
                    if(x1 == y1)
                        z[i][0] += 1;
                    if((x1 + y1) == (m - 1))
                        z[i][1] += 1; 
                    x[i][x1] += 1;
                    y[i][y1] += 1;
                    break;
                }
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(x[i][j] == m || y[i][j] == m || z[i][0] == m || z[i][1] == m){
                    winer[i] = 1;
                    out = 1;
                }
            }
        }
        if(out){
            printf("%3d", result);
            for(i=0;i<n;i++){
                if(winer[i] == 1){
                    printf("%2d ", i);
                }
            }
        }
    }
}
