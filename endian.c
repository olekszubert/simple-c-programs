#include <stdint.h>
#include <stdio.h>

/*
A simple program to check system's endianess
A x86/x64 CPU should show little endian
*/

int main() 
{
	//Create an int
	const uint32_t check = 0xDEADBEEF; 

	//Cast it to a char pointer (dividing it into bytes)
	uint8_t* p = (uint8_t*)&check;

	//If the first byte is the left-most one - big endian
	if (*p == 0xDE) printf("Big endian\n");

	//If the first byte is the right-most one - little endian
	else printf("Little endian\n");

	return 0;
}
