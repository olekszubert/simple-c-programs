#include <stdio.h>
#include <string.h>
/*
Program splitting a string at delimiters.
*/

int main()
{
    char str[] = "- Lots, of words: to. split. -";
    const char* delimiters = " ,.:-";
    char* token = NULL;
    char* nextToken = NULL;
    printf("Original string \"%s\"\n", str);

    printf("Tokens:\n");
    token = strtok_s(str, delimiters, &nextToken);
    while (token)
    {
        printf("%s\n", token);
        token = strtok_s(NULL, delimiters, &nextToken);
    }
    return 0;
}
