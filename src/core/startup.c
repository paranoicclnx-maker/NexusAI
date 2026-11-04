#include <stdio.h>
#include "startup.h"
void nexus_startup(void)
{
    printf("========================\n");
    printf("        NEXUS AI        \n");
    printf("========================\n");
    int count = 0;
    while(count <= 100)
    {
        printf("Starting Nexus AI... %d%%\n",count);
        printf("Loading core modules... %d%%\n",count);

        count = count + 10;
    }
}

