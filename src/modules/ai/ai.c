/*stdlib.h — это стандартная библиотека языка C (Standard Library).
 Она предоставляет функции для различных системных и общих задач:
 Функция	Назначение
System()	Выполняет команду операционной системы
malloc()	Выделяет динамическую память
free()	Освобождает выделенную память
atoi()	Преобразует строку в целое число
exit()	Завершает программу*/

#include <stdio.h>
#include <stdlib.h>
#include "ai.h"
#include "../../core/logs.h"
int nexus_check_ai(void)
{
    int status = system("where.exe ollama");
        // status == 0 — команда завершилась успешно.
        //status != 0 — команда завершилась с ошибкой.
        // данная команда изучена с помощью и выше варианты которые она может вернуть 

    if( status == 0)
    {
    nexus_log_write(LOG_INFO, "AI", "Ollama found in PATH \n");
    return AI_SUCCESS;
    }
    nexus_log_write(LOG_ERROR, "AI", "Ollama was not found in PATH \n");
    return AI_ERROR;
    
}

