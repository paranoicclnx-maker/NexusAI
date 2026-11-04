#include <stdio.h>
int get_command(void)
{
    int command = 0;
    while(1)
    {
    if (scanf("%d",&command) != 1 )
    {
        printf("Invalid input!\n");

        int ch; // функциия getchar была сделана с помощью ии пока просто вставил дальше буду изучать ее
    while ((ch = getchar()) != '\n' && ch != EOF) 
        {
    // Читаем символы, пока не встретим конец строки
    
        }
        continue; // повторять цикл будет
    
    }
    else 
    {
    break; //  выход из цикла т.к появилось число 
    }
}
    return command;
}