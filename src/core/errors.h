#ifndef ERRORS_H
#define ERRORS_H

typedef enum 
{
    ERROR_SUCCESS = 0,
    ERROR_INPUT,
    ERROR_STREAM,
    ERROR_UNKNOWN,
    ERROR_STARTUP,
    ERROR_CONFIG,
    ERROR_CONFIG_READ,
    ERROR_LOG
} NexusError;
    
void nexus_print_error(NexusError error);

#endif
   

