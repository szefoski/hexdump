#include <stdio.h>

void hexDump(void* addr, int size, int skip, int linechars)
{
    if (size - skip <= 0)
    {
        return;
    }

    int currline = skip / linechars;
    int lasLine = size / linechars;
    if (size % linechars != 0)
    {
        ++lasLine;
    }

    char buff[256];
    char buff2[256];
    unsigned char* pc = (unsigned char*)addr;

    for (; currline < lasLine; ++currline)
    {
        sprintf(buff, "  0x%04x ", currline * linechars);
        sprintf(buff2, "  ");

        for (int i = 0; i < linechars; ++i)
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
            }
        }
        printf("%s%s\n", buff, buff2);
    }
}

