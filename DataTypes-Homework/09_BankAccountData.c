#include <stdio.h>
#include <stdlib.h>

int main()
{
    char firstName[10] = "Sebastian";
    char middleName[4] = "von";
    char lastName[4] = "Pan";

    double balance = 19.99;
    char bankName[7] = "MyBank";
    char IBAN[11] = "1234567890";

    char firstCardNum[11] = "0987654321";
    char secondCardNum[11] = "1237890456";
    char thirdCardNum[11] = "9871230564";

    printf("First name: %s\n", firstName);
    printf("Middle name: %s\n", middleName);
    printf("Last name: %s\n", lastName);
    printf("Account balance: $%.2f\n", balance);
    printf("Bank name: %s\n", bankName);
    printf("IBAN: %s\n", IBAN);
    printf("First card number: %s\n", firstCardNum);
    printf("Second card number: %s\n", secondCardNum);
    printf("Third card number: %s\n", thirdCardNum);

    return 0;
}
