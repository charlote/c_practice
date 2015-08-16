#include <stdio.h>

#define toBig(v) \
    ((v&0xff000000) >> 24)|((v&0xff0000) >> 8)|((v&0xff00) << 8)|((v&0xff) << 24)

void main()
{
    unsigned int a = 0x12345678;
    unsigned int b = toBig(a);
    printf("%x\n%x\n", a, b);
}

