#include <stdio.h>
#include "errors.h"
void nexus_print_error(NexusError error)
{
    switch(error)
    {
        case ERROR_SUCCESS:
            printf("Success!\n");
            break;
        case ERROR_INPUT:
            printf("Error: Invalid input.\n");
            break;
        case ERROR_STREAM:
            printf("Error: Stream error occurred.\n");
            break;
        case ERROR_UNKNOWN:
            printf("Error: An unknown error occurred.\n");
            break;
        case ERROR_STARTUP:
            printf("Error: NEXUS AI startup failed.\n");
            break; 
        case ERROR_CONFIG:
        printf("Error: Configuration file could not be opened.");
        break;
        case ERROR_CONFIG_READ:
        printf("Error: Failed to read configuration file.");
        break;
        case ERROR_LOG:
        printf("Error: Failed to write log file.");
        break;
        default:
            printf("Error: Unrecognized error code.\n");
            break;
    }
}