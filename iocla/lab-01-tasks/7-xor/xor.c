#include <stdio.h>
#define BYTE_TO_BINARY_PATTERN "%c%c%c%c%c%c%c%c"
#define BYTE_TO_BINARY(byte)  \
  (byte & 0x80 ? '1' : '0'), \
  (byte & 0x40 ? '1' : '0'), \
  (byte & 0x20 ? '1' : '0'), \
  (byte & 0x10 ? '1' : '0'), \
  (byte & 0x08 ? '1' : '0'), \
  (byte & 0x04 ? '1' : '0'), \
  (byte & 0x02 ? '1' : '0'), \
  (byte & 0x01 ? '1' : '0') 

int main() {
    char hex1[] = "\x4c\x26\xe3\xb4\x4c\x86\xc2\x1e\xf8\x90\x89\x70\xc7\xaf\x74\x75\xc1\x7e\x83\x4c\x7c\x01\xaa\x70\x2e\x77";
    char hex2[] = "\x00\x43\x82\xc6\x22\xa6\xb6\x71\xd8\xe5\xfa\x15\xe7\xc7\x11\x0d\xe1\x07\xec\x39\x5c\x6c\xdf\x03\x5a\x56";

    char xor[26];

    // TODO - xor hex1 and hex2 byte by byte
    for(int i = 0; i < sizeof(hex1)/sizeof(char); i++)
    {
        xor[i] = hex1[i] ^ hex2[i];
        printf(BYTE_TO_BINARY_PATTERN "^" BYTE_TO_BINARY_PATTERN "=" BYTE_TO_BINARY_PATTERN, BYTE_TO_BINARY(hex1[i]), BYTE_TO_BINARY(hex2[i]), BYTE_TO_BINARY(xor[i]));
        printf("\n");
    }

    printf("%s\n", xor);
    return 0;
}
