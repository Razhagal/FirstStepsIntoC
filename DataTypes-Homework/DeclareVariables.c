#include <stdio.h>
#include <stdlib.h>

int main()
{
    //52130, 8942492113, -115, 4825932, 97, -10000, -35982859328592389
    char smallNum = -115;
    char anotherSmallNum = 97;
    short mediumNum = -10000;
    unsigned short mediumUnsignedNum = 52130;
    int bigNum = 4825932;
    long long veryBigNumber = 8942492113LL;
    long long veryVeryBigNumber = -35982859328592389LL;

    printf("%lld", veryVeryBigNumber);
    return 0;
}
