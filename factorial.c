#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
In mathematics, the factorial of a positive integer n, denoted by n!,
is the product of all positive integers less than or equal to n.
The value of 0! is 1, according to the convention for an empty product.

Factorial of 0 and 1 is 1.
Calculating factorial with recursion.
*/


uint32_t findFactorial(uint32_t num)
{
    if (num == 0 || num == 1) return 1;
    else return findFactorial(num - 1) * num;
}

int main()
{
    const size_t SIZE = 10;
    uint32_t numbers[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    for(int i=0; i< SIZE; ++i)
        printf("Factorial of number %u equals %u.\n", numbers[i], findFactorial(numbers[i]));

    return 0;
}
