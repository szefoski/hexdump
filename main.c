#include <stdlib.h>
#include "hexdump.h"

int main()
{
    unsigned char *buffer = malloc(200);
    for (unsigned char c = '0'; c <= 'z'; ++c)
        buffer[c] = c;
    hexdump(buffer, 140, 18, 16);  
    free(buffer);
}
