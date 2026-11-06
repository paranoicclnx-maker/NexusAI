#include <stdio.h>
#include "errors.h"
void nexus_print_error(NexusError error)
{
    switch(error)
    {
        case ERROR_INPUT:
            printf("Error: Invalid input.\n");
            break;
        case ERROR_STREAM:
            printf("Error: Stream error occurred.\n");
            break;
        case ERROR_UNKNOWN:
            printf("Error: An unknown error occurred.\n");
            break;
        default:
            printf("Error: Unrecognized error code.\n");
            break;
    }
}