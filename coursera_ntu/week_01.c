/* to calculate the surface area and volume of cube
 * 1. input the long, wide and high of cube
 * 2. output the surfacearea and volume
 */

#include <stdio.h>

void main()
{
    int i, j, k;
    scanf("%d", &i);
    scanf("%d", &j);
    scanf("%d", &k);
    printf("%d %d\n", 2*(i*j+j*k+i*k), i*j*k);
}
