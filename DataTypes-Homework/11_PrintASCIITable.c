#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char lastASCIICode = 255;
    for(int i = 1; i < lastASCIICode; i++)
    {
        printf("%c ", i);
    }

    return 0;
}
