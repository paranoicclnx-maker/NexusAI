#ifndef ERRORS_H
#define ERRORS_H

typedef enum 
{
    ERROR_INPUT,
    ERROR_STREAM,
    ERROR_UNKNOWN

} NexusError;
    
void nexus_print_error(NexusError error);

#endif
   

