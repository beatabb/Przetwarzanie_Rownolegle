#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define PRIME 1
#define COMPLEX 0

void printVector(std::vector <int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        printf("%d ", vec[i]);
        if (i % 10 == 9) //co 10-ta liczba
            printf("\n");
    }
    printf("\nprime numbers count: %d\n", vec.size());
}

std::vector<int> seqSieve(int minNum, int maxNum) {

    int lastNum = (int)sqrt(maxNum);
    std::vector<bool> primeOrComplex;
    for (int i = 2; i <= maxNum; i++)
        primeOrComplex.push_back(PRIME);

    for (int i = 0; ; i++)
    {
        int number = 2 + i;
        if (lastNum < number)
            break;
        if (primeOrComplex[i] == COMPLEX)
            continue;

        for (int m = number + number; m <= maxNum; m += number) //usuwamy wszystkie wielokrotności
            primeOrComplex[m - 2] = COMPLEX;
    }

    std::vector <int> primeNumbers;
    for (int i = minNum - 2; i < primeOrComplex.size(); i++)
    {
        if (primeOrComplex[i] == PRIME)
            primeNumbers.push_back(i + 2);
    }

    return primeNumbers;
}

int main()
{
    std::vector <int> tmp = seqSieve(2, 300000000);
    //printVector(tmp);
}