#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
A program to find if a number is a prime number
Prime numbers:  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 
                37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 
                79, 83, 89, 97, 101, 103, 107, 109, 113, 
                127, 131, 137, 139, 149, 151, 157, 163, 
                167, 173, 179, 181, 191, 193, 197, 199, etc.


Iterate from i=2 to i=num/2 - if number isn't divisible by any number from 2 to num/2, it is a prime number
If the number is divisible by anything other than 1 and itself, it is not a prime number
*/

uint8_t isPrimeNumBrute(uint32_t num) 
{
    uint32_t divResult = 0;
    uint32_t rest = 0;
    uint32_t i = 2;
    while (1) 
    {
        //Get division result and remainder
        divResult = (num / i);
        rest = (num % i);

        //Numbers 0 and 1 are not prime
        if (num == 0 || num == 1)
            return 0;

        //No numbers less than num fulfil the statement below
        if (i == num)
            return 1;

        //Check if num is divisible without remainder by any number below it
        if (divResult != 0 && rest == 0) 
            return 0;

        //Increment the number for division
        i++;
    }
}

uint8_t isPrimeNumAlt(uint32_t num)
{
    int isPrime = 1;

    //Numbers 0 and 1 are not prime
    if (num == 0 || num == 1){
        isPrime = 0;
        return isPrime;
    }

    //Iterate from i=2 to i=num/2 - if number isn't divisible by any number from 2 to num/2, it is a prime number
    for (int i = 2; i <= num / 2; ++i)
    {
        //If the number is divisible by anything other than 1 and itself, it is not a prime number
        if (num % i == 0) {
            isPrime = 0;
            break;
        }
    }
    return isPrime;
}

int main() 
{
    const size_t SIZE = 10;
    uint32_t numbers[SIZE] = { 2, 19, 61, 157, 199, 0, 1, 6, 86, 180 };

    printf("Brute force:\n");
    for(int i=0; i < SIZE; ++i)
    { 
        isPrimeNumBrute(numbers[i]) ?
            printf("Number %u\t is a prime number.\n", numbers[i]) :
            printf("Number %u\t is not a prime number.\n", numbers[i]);
    }

    printf("\nAlternative:\n");
    for (int i = 0; i < SIZE; ++i)
    {
        isPrimeNumAlt(numbers[i]) ?
            printf("Number %u\t is a prime number.\n", numbers[i]) :
            printf("Number %u\t is not a prime number.\n", numbers[i]);
    }
}
