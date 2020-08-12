#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Binary Gap - calculate the longest row of consecutive 0s surrounded by a 1 on each side, example:
10001 - Gap = 3
0011100001110 - Gap = 4
0000001 - Gap = 0
*/

uint32_t binary_gap_recursive(uint32_t subj)
{
    static uint32_t currGap = 0;
    static uint32_t maxGap = 0;

    //Zero the maxGap on first function run
    maxGap = 0; 

    //Subject at least 0b10, place subj bit by bit on stack
    if (subj > 1) {
        binary_gap_recursive(subj / 2); //Subject >> 1
    }

    //Check if Subject's LSB bit is 0, increment gap
    if (subj % 2 == 0) { 
        currGap += 1;
        return maxGap;
    }

    //Otherwise - 1 detected, try to update maxGap
    else if (maxGap < currGap) {
            maxGap = currGap;
    }
    currGap = 0;
    return maxGap;
}

uint8_t binary_gap_iterative(uint32_t subj)
{
    uint8_t currBitValue = 0, prevBitValue = 0;
    uint8_t currGap = 0, maxGap = 0;

    //Calculate the number of bits in subject
    uint8_t nBits = (uint8_t)log2(subj) + 1; 

    for (int currBit = 0; currBit < nBits; ++currBit)
    {
        //Remember previous bit (except while being on first bit)
        if (currBit != 0)
            prevBitValue = currBitValue; 

        //Mask for one bit
        currBitValue = (subj >> currBit) & 1;

        //Wait for the first 0
        if (currBitValue == 1 && currGap == 0) continue;

        //First 0, Gap = 1
        else if (currBitValue == 0 && prevBitValue == 1) currGap = 1;

        //Consecutive 0
        else if (currBitValue == 0 && currGap != 0) currGap++;

        //First bits are 0s
        else if (currBitValue == 0 && currGap == 0 && prevBitValue == 0) continue;

        //If last bit is 0, there is no edge gap
        else if (currBitValue != 1 && currBit == nBits - 1)
            currGap = 0;

        //Detected a 1 - Gap ends, update maxGap
        else if (currBitValue == 1 && currGap != 0)
        {
            if (currGap > maxGap) 
                maxGap = currGap;

            currGap = 0;
        }
        else
        {
            printf("Error: Your code sucks.\n\r");
        }
        //printf("Iteration = %u, currBitValue = %u, currGap = %u\n\r", currBit, currBitValue, currGap);
    }
    return maxGap;
}

int main()
{
    const uint32_t subject1 = 0b1000001111000001;
    const uint32_t subject2 = 0b10011110001;
    const uint32_t subject3 = 0b1000111100000001;
    const uint32_t subject4 = 0b1010111010101010;
    const uint32_t subject5 = 0b0011010001000000;

    printf("\nMax binary gap of %u is: \nIterative: %u \nRecursive: %u\n", subject1, binary_gap_iterative(subject1), binary_gap_recursive(subject1));
    printf("\nMax binary gap of %u is: \nIterative: %u \nRecursive: %u\n", subject2, binary_gap_iterative(subject2), binary_gap_recursive(subject2));
    printf("\nMax binary gap of %u is: \nIterative: %u \nRecursive: %u\n", subject3, binary_gap_iterative(subject3), binary_gap_recursive(subject3));
    printf("\nMax binary gap of %u is: \nIterative: %u \nRecursive: %u\n", subject4, binary_gap_iterative(subject4), binary_gap_recursive(subject4));
    printf("\nMax binary gap of %u is: \nIterative: %u \nRecursive: %u\n", subject5, binary_gap_iterative(subject5), binary_gap_recursive(subject5));

    return 0;
}
