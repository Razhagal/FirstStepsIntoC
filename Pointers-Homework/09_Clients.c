/* 
 * Declare a struct called Client with the following members: name, age and account balance.
 * Write a function that sorts an array of clients using a specific comparator.
 * The comparator should be another function that determines how the clients are sorted.
 * Write comparators for sorting the clients by name, age and account balance.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct Client
{
    char* name;
    unsigned char age;
    long double balance;
};

void bubbleSortClients(struct Client* clients, int count, int (*compare)(struct Client*, struct Client*));
int compareName(struct Client* first, struct Client* second);
int compareAge(struct Client* first, struct Client* second);
int compareBalance(struct Client* first, struct Client* second);
int compareDoubles(long double first, long double second);
void swap(void* first, void* second, size_t size);
void printClients(struct Client* clients, int count);

int main()
{
    struct Client clients[] =
    {
        {.name = "Pesho", .age = 23, .balance = 15.50 },
        {.name = "Jonny", .age = 18, .balance = 5.49 }
    };
    
    int clientsCount = 2;
    printf("Clients before sorting:\n");
    printClients(clients, clientsCount);
    
    printf("Clients after sorting by Name:\n");
    bubbleSortClients(clients, clientsCount, &compareName);
    printClients(clients, clientsCount);
    
    printf("Clients after sorting by Age:\n");
    bubbleSortClients(clients, clientsCount, &compareAge);
    printClients(clients, clientsCount);
    
    printf("Clients after sorting by Balance:\n");
    bubbleSortClients(clients, clientsCount, &compareBalance);
    printClients(clients, clientsCount);
    
    return 0;
}

int compareName(struct Client* first, struct Client* second)
{
    int diff = strcmp(first->name, second->name);
    if (diff >= 0)
    {
        return 1;
    }
    
    return 0;
}

int compareAge(struct Client* first, struct Client* second)
{
    return first->age > second->age;
}

int compareBalance(struct Client* first, struct Client* second)
{
    int isBigger = compareDoubles(first->balance, second->balance);
    return isBigger;
}

int compareDoubles(long double first, long double second)
{
    return first > second;
}

void bubbleSortClients(struct Client* clients, int count, int (*compare)(struct Client*, struct Client*))
{
    int isSwapped = 1;
    while (isSwapped)
    {
        isSwapped = 0;
        for (int i = 0; i < count - 1; i++)
        {
            if (compare(&clients[i], &clients[i + 1]))
            {
                swap(&clients[i].age, &clients[i + 1].age, sizeof(char));
                swap(&clients[i].balance, &clients[i + 1].balance, sizeof(long double));
                swap(&clients[i].name, &clients[i + 1].name, sizeof(char));
                
                isSwapped = 1;
            }
        }
    }
}

void swap(void* first, void* second, size_t size)
{
    char* firstPtr = first;
    char* secondPtr = second;
    for (int i = 0; i < size; i++)
    {
        char tmpByte = firstPtr[i];
        firstPtr[i] = secondPtr[i];
        secondPtr[i] = tmpByte;
    }
}

void printClients(struct Client* clients, int count)
{
    for (int i = 0; i < count; i++)
    {
        printf("Name: %s; Age: %d; Balance: %.2Lf\n",
               clients[i].name, clients[i].age, clients[i].balance);
    }
}