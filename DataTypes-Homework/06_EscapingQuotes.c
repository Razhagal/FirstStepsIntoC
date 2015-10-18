#include <stdio.h>
#include <stdlib.h>

int main()
{
    char someText[87] = "The \"use\" of quotations causes difficulties. \\n, \\t and \\ are also special characters.";
    printf("%s", someText);
    return 0;
}
