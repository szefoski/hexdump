#include <stdio.h>

void hexdump(void* addr, int size, int skip, int linechars)
{
    int currline;
    int lasLine;
    int i;
    unsigned char *pc;
    char buff[256];
    char buff2[256];

    if (size - skip <= 0)
    {
        return;
    }

    lasLine = size / linechars;
    if (size % linechars != 0)
    {
        ++lasLine;
    }

    pc = (unsigned char*)addr;

    for (currline = skip / linechars; currline < lasLine; ++currline)
    {
        sprintf(buff, "  0x%04x ", currline * linechars);
        sprintf(buff2, "  ");

        for (i = 0; i < linechars; ++i)
        {
            int charno = currline * linechars + i;
            if (charno >= skip && charno < size)
            {
                sprintf(buff, "%s %02x", buff, pc[charno]);
                if ((pc[charno] < 0x20) || (pc[charno] > 0x7e))
                {
                    sprintf(buff2, "%s.", buff2);
                }
                else
                {
                    sprintf(buff2, "%s%c", buff2, pc[charno]);
                }
            }
            else
            {
                sprintf(buff, "%s __", buff);
                sprintf(buff2, "%s ", buff2);
            }
        }
        printf("%s%s\n", buff, buff2);
    }
}

