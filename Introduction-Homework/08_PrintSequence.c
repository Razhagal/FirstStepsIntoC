#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    
    /*
     * ANSI C doesn't support that declaration
     * You need to set your project to use C99 or above
     */
    for(int i = 2; i <= n; i++)
    {
        if (i % 2 == 0)
        {
            printf("%d", i);
        }
        else
        {
            printf("%d", -i);
        }
        
        if (i < n)
        {
            printf(", ");
        }
    }
    
    return 0;
}

