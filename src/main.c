#include "core/startup.h"
#include "../modules/system/system.h"
#include "core/shutdown.h"
#include "core/menu.h"	

int main(void)
{
	nexus_startup();
	nexus_menu();

	return 0; 
}