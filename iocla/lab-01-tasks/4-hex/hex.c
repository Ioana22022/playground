#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main()
{
    // TODO declare a char[] variable that stores the string
    char c[] = "48455820526f636b73210a";
    uint8_t *p = c;
    int sz = sizeof(c) / 2;
    uint8_t v[sz];
    int i, k = 0;
    
    for(i = 0; i < sizeof(c) - 1; i += 2)
    {
        sscanf(p, "%2hhx", &v[k++]);
        p+=2;
    }
    // TODO print the char[] variable

    for(i = 0; i < k; i++)
    {
        printf("%c ", v[i]);
    }

    return 0;
}
