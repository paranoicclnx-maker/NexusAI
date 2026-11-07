#include <stdio.h>
#include "errors.h"
#define N 128

int nexus_config_read(FILE *file)
{
  
  

    char buffer[N];
    while ( fgets(buffer, sizeof(buffer), file) != NULL)
    {
    printf("%s",buffer);
    }

   if (ferror(file) != 0) 
  {
    fclose(file);
    return ERROR_CONFIG_READ;
  }
  else 
  {
  fclose(file);
  return ERROR_SUCCESS;
  }

}


  