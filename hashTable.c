#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;

void allocHash(int *hashTable, int key, int value)
{
    if (hashTable[key] != 0)
    {
        allocHash(hashTable, key + 1, value);
    }
    else
    {
        hashTable[key] = value;
    }
}

int operator(int val)
{
    int operatorNumber = 100;
    int rest = val % operatorNumber;
    return rest;
}

int getNumber(int key, int number, int rounds, int *hashTable)
{
    int hash = hashTable[key];
    if (hash == 0)
        return 0;
    if (number != (hash + key - rounds))
    {
        return getNumber(key++, number, rounds--, hashTable);
    }
    return 1;
}

int verifyNumberExists(int number, int *hashTable)
{
    int key = operator(number);
    int exists = getNumber(key, number, 0, hashTable);
    return exists;
}

void main()
{
    int hashTable[1243] = {0};
    int read;
    for (int i = 0; i < 5; i++)
    {
        printf("Digite um numero:\n");
        scanf("%d", &read);
        int key = operator(read);
        allocHash(hashTable, key, read);
    }
    for (int i = 0; i < 1243; i++)
    {
        printf("%d\n", hashTable[i]);
    }
    
}