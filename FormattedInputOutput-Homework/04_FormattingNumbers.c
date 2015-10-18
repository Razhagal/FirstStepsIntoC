/*
 * Write a program that reads 3 numbers: an integer a (0 ≤ a ≤ 500),
 * a floating-point b and a floating-point c and prints them in 4 virtual
 * columns on the console. Each column should have a width of 10 characters.
 * The number a should be printed in hexadecimal, left aligned; then the number
 * a should be printed in binary form, padded with zeros,then the number
 * b should be printed with 2 digits after the decimal point, right aligned;
 * the number c should be printed with 3 digits after the decimal point,
 * left aligned.
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    char formatter[] = "|%-10X|%s|%10.2f|%-10.3f|";
    int a, temp = 0;
    float b, c;

    scanf("%d %f %f", &a, &b, &c);
    if (a < 0 || a > 500)
    {
        printf("First number should be in range of 0 to 500 inclusive");
    }
    else
    {
        char aToBinary[11] = "0000000000";
        temp = a;
        for(int i = sizeof(aToBinary) - 2; i >= 0; i--)
        {
            if (temp & 1)
            {
                aToBinary[i] = '1';
            }
            else
            {
                aToBinary[i] = '0';
            }

            temp >>= 1;
        }

        printf(formatter, a, aToBinary, b, c);
    }

    return 0;
}
