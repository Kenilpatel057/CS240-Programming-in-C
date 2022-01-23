#include <stdio.h>
int main()
{
    char storage[10000];
    int count = 0;
    int inputline = 0;
    scanf("%d", &inputline);
    char c = getchar();
    int linecount = 0;
    while (c != EOF)
    {
        if (c == '\n')
        {
            linecount++;
        }
        if (linecount >= inputline + 1)
            break;
        if (c != '\n')
        {
            storage[count] = c;
            count++;
        }
        c = getchar();
    }
    //substracting last line used to break
    linecount = linecount - 1;
    printf("%d\n", count);
    printf("%s\n", storage);
    return 0;
}
