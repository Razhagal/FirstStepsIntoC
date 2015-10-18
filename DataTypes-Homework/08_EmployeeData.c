#include <stdio.h>
#include <stdlib.h>

int main()
{
    char firstName[10] = "Sebastian";
    char lastName[4] = "Pan";
    unsigned char age = 19;
    char gender = 'm';
    char personalId[11] = "8306112507";
    char uniqueEmployeeNumber[9] = "27563571";

    printf("First name: %s\n", firstName);
    printf("Last name: %s\n", lastName);
    printf("Age: %d\n", age);
    printf("Gender: %c\n", gender);
    printf("Personal ID: %s\n", personalId);
    printf("Unique Employee number: %s\n", uniqueEmployeeNumber);

    return 0;
}
