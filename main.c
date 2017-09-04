#include <stdlib.h>
#include "hexdump.h"

int main()
{
    unsigned char c;
    unsigned char *buffer = malloc(200);
    for (c = '0'; c <= 'z'; ++c)
        buffer[c] = c;
    hexdump(buffer, 140, 18, 16);  
    free(buffer);
}
