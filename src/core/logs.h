#ifndef LOGS_H
#define LOGS_H




typedef enum
{
    LOG_INFO,
    LOG_WARNING,
    LOG_ERROR
} LogLevel;

int nexus_log_write(LogLevel level , const char *module , const char *message);

#endif