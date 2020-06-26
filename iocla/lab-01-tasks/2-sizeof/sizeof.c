#include <stdio.h>
int main()
{
    char charT;
    short shortT;
    int integerT;	
    unsigned int unsignedIntegerT;
    long longT;
    long long longlongT;
    void * voidT;

    // TODO - use sizeof to print size of the above types
    printf("sizeof(char) = %d", sizeof(charT));
    printf("\n");
    printf("sizeof(shortT) = %d", sizeof(shortT));
    printf("\n");
    printf("sizeof(integerT) = %d", sizeof(integerT));
    printf("\n");
    printf("sizeof(unsignedIntegerT) = %d", sizeof(unsignedIntegerT));
    printf("\n");
    printf("sizeof(longT) = %d", sizeof(longT));
    printf("\n");
    printf("sizeof(longlongT) = %d", sizeof(longlongT));
    printf("\n");
    printf("sizeof(voidT) = %d", sizeof(voidT));
    printf("\n");

    return 0;
}
