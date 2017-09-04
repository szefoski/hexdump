#include <stdlib.h>
#include "hexdump.h"

int main()
{
    int i;
    unsigned char *buffer = malloc(300);

    for (i = 0; i <= 255; ++i)
        buffer[i] = (unsigned char)i;

    hexdump(buffer, 300, 22, 16);  
    free(buffer);
    return 0;
}
