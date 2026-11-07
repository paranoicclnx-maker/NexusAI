#include <stdio.h>
#include "startup.h"
#include "errors.h"
#include "config.h"
#include "logs.h"
#include <time.h>
int nexus_startup(void)
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
  nexus_log_write(LOG_INFO, "STARTUP", "Starting Nexus AI  \n");
  nexus_log_write(LOG_INFO, "STARTUP", "Loading core modules  \n");
  FILE *file = fopen("core/config.ini", "r");
      if(file != NULL)
      {
       
       return nexus_config_read(file);
       
      }
      else{
        return ERROR_CONFIG; // если конфиг не открывается ошибка конфиг 
      }
      
}

