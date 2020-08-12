#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*
A palindrome is a word, phrase, or sequence that reads the same backwards as forwards.
Keep in mind that a leading zero denotes that the literal is expressed using octal (a base-8 number).
*/

uint8_t isPalindrome(uint32_t num)
{
    uint32_t revNumber=0;

    //Iterate through each digit
    for (int i = 1; num / i != 0; i *= 10)
    {
        //Get the first/next left-most digit of the number, 
        //then add it to the revNumber and move all to the left
        revNumber = (revNumber * 10) + (num / i) % 10;
    }
    if (revNumber == num) return 1;
    return 0;
}

int main(void) {

    const size_t SIZE = 6;
    uint32_t numbers[SIZE] = { 0, 2345432, 34699643, 111100, 23454321, 34565432 };

    for (int i = 0; i < SIZE; ++i)
    {
        isPalindrome(numbers[i]) ?
            printf("Number %u\t is a palindrome.\n", numbers[i]) :
            printf("Number %u\t is not a palindrome.\n", numbers[i]);
    }
    return 0;
}
