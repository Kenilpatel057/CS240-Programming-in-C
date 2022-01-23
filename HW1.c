#include <stdio.h>

int main()
{
    int ch, i;
    int asciarray[94];
    for (i = 0; i < 94; ++i)
        asciarray[i] = 0;

    while ((ch = getchar()) != EOF)
    {
                                        // c is the ascii character
        
        if (ch >= '!' && ch <= '~')     //to remove blank space
        {
            putchar(ch);                // printing line without space
            ++asciarray[ch - 33];     // incrementing the count of each letter
        }
    }

    putchar('\n');
    for (i = 0; i < 94; ++i)
    {
        if (asciarray[i] > 0)
        {
            putchar(i + 33);    //to print the frequency in acii order
            printf(" %d\n", asciarray[i]);
        }
    }
    return 0;
}
