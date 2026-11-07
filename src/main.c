#include "core\startup.h"
#include "core\menu.h"
#include "core\errors.h"	

int main(void)
{
	int result;
	if ((result = nexus_startup()) == ERROR_SUCCESS)
	{
	 nexus_menu();
	}
	else
	{
		nexus_print_error(result);
	}

	return 0; 
}