#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "../modules/system/system.h"
#include "shutdown.h"
#include "../modules/ai/ai.h"
#include "errors.h"
void nexus_menu(void)
{
int running = 1;
while(running == 1 )
{
    printf("========================\n");
    printf("        NEXUS AI        \n");
    printf("========================\n\n");
    printf(" System information(/system)\n");
    printf(" Start AI(/start)\n"); 
    printf(" Shutdown || Exit(/exit)\n");

    printf("Select command: ");
    char command[50];
    
    if(fgets(  command, sizeof(command), stdin) == NULL) //  считывание строки если вернулся 0 то ошибка где то произошла

    {
        if (feof(stdin)) // EOF (Конец файла) проверка на конец ввода
        {
            running = 0; 
            nexus_shutdown(); 
            continue;
        }
        else if (ferror(stdin)) // Ветка ошибки чтения
        {
            nexus_print_error(ERROR_STREAM);
                running = 0; 
                nexus_shutdown(); 
                continue; // Continue to the next iteration of the loop
        }
        else
        {
            
            nexus_print_error(ERROR_UNKNOWN);
            continue; 
        }
       
    }

    
    

    command[strcspn(command, "\n")] = '\0';
    if(strcmp(command,"/system") == 0)
    {
    nexus_system_info();  // использования функции систем инфо  
    }    
    else if (strcmp(command,"/start") == 0) // start ai
    {
        if(nexus_check_ai()  == AI_SUCCESS)  // использования функции проверки установленного по для запуска  
        {
             printf("Ollama is installed!\n");
        }
        else
        {
            printf("Ollama is not installed!\n"); // fail ai
        }
    }
    
    else if (strcmp(command,"/exit") == 0) // exit / shutdown
    {
        nexus_shutdown(); // использования функции выключения системы  
        printf("Exiting Nexus AI...\n");
        running = 0; 
    }
    
    else
    {
        printf("Unknown command\n");
      }

    }

}
       
        

     

   
// int nexus_get_status(void)
// {
//  int ai_running = 0;
//   if(ai_running == 1)
//   {
//     return 1; // AI is running
//   }
//   else
//   {
//     return 0; // AI is not running
//   }
// }

// int nexus_status(void)
// {
//     return nexus_get_status();
// }

// //
// void nexus_info(int version, int status, int year)
// {
//    printf("========================\n");
//     printf("        NEXUS AI        \n");
//     printf("========================\n");
//     printf("Version: %d\n", version);
//     printf("Status: %d\n", status);
//     printf("Year: %d\n", year);


// }

// void nexus_print_info(void)
// {
//    nexus_info(1, 1, 2026);
   
// }