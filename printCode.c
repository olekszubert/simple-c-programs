#include <stdint.h>
#include <stdio.h>

/*
A simple program to print out the contents of its file.
Keep in mind that EOF is a negative number, so c must be signed.
*/

int main() {

    FILE* fp = NULL;
    fopen_s(&fp, __FILE__, "r");
    if (fp)
    {
        int8_t c;

        do {
            c = fgetc(fp);
            putchar(c);
        } while (c != EOF);

        fclose(fp);
    }
    return 0;
}
