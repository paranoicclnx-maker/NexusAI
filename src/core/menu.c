#include <stdio.h>
#include "menu.h"
#include "../modules/system/system.h"
#include "shutdown.h"
#include "commands.h"
#include "../modules/ai/ai.h"
void nexus_menu(void)
{
int running = 1;
while(running == 1 )
{
    printf("========================\n");
    printf("        NEXUS AI        \n");
    printf("========================\n\n");
    printf("1. System information\n");
    printf("2. Start AI\n"); 
    printf("3. Shutdown || Exit \n");

    printf("Select command: ");
    int command = get_command();
    
  
    
   
    switch(command)
            {

        case SYSTEM_INFO: // 1. System information
        nexus_system_info();
        break;

        case START_AI: // Start AI
        if(nexus_check_ai()  == AI_SUCCESS)
        {
             printf("Ollama is installed!\n");
        }
        else
        {
            printf("Ollama is not installed!\n");
        }

        break;

        case SHUTDOWN: // Shutdown
        nexus_shutdown();
        printf("Exiting Nexus AI...\n");
        running = 0;
        break;

        default:
        printf("Invalid command!\n");
        break;

            }
        }
    }

   
