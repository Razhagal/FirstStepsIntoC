/*
A company has name, address, phone number, fax number, web site and manager.
The manager has first name, last name, age and a phone number.
Write a program that reads the information about a company and its
manager and prints it back on the console.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

void removeNewLine(char *input);

int main()
{
    char companyName[BUFFER_SIZE];
    printf("Company name:");
    fgets(companyName, BUFFER_SIZE, stdin);
    removeNewLine(companyName);

    char companyAddress[BUFFER_SIZE];
    printf("Company address:");
    fgets(companyAddress, BUFFER_SIZE, stdin);
    removeNewLine(companyAddress);

    char companyPhone[BUFFER_SIZE];
    printf("Phone number:");
    fgets(companyPhone, BUFFER_SIZE, stdin);
    removeNewLine(companyPhone);

    char faxNumber[BUFFER_SIZE];
    printf("Fax number:");
    fgets(faxNumber, BUFFER_SIZE, stdin);
    removeNewLine(faxNumber);

    char webSite[BUFFER_SIZE];
    printf("Web site:");
    fgets(webSite, BUFFER_SIZE, stdin);
    removeNewLine(webSite);

    char managerFirstName[BUFFER_SIZE];
    printf("Manager first name:");
    fgets(managerFirstName, BUFFER_SIZE, stdin);
    removeNewLine(managerFirstName);

    char managerLastName[BUFFER_SIZE];
    printf("Manager last name:");
    fgets(managerLastName, BUFFER_SIZE, stdin);
    removeNewLine(managerLastName);

    int managerAge;
    char ageInput[4];
    printf("Manager age:");
    fgets(ageInput, sizeof(ageInput), stdin);
    sscanf(ageInput, "%d", &managerAge);

    char managerPhone[BUFFER_SIZE];
    printf("Manager phone:");
    fgets(managerPhone, BUFFER_SIZE, stdin);
    removeNewLine(managerPhone);

    printf("%s\n", companyName);
    printf("%s\n", companyAddress);
    printf("Tel. %s\n", companyPhone);
    printf("Fax: %s\n", (faxNumber[0] != '\0' ? faxNumber : "(no fax)"));
    printf("Web site: %s\n", webSite);
    printf("Manager: %s %s (age: %d, tel. %s)", managerFirstName, managerLastName, managerAge, managerPhone);

    return 0;
}

void removeNewLine(char *input)
{
    int inputLength = strlen(input);
    if (input[inputLength - 1] == '\n')
    {
        input[inputLength - 1] = '\0';
    }
}
