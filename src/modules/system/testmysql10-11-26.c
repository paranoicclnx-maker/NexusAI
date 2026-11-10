#include <stdio.h>
#include "mysql.h"
void nexus_give(char * db, char * table)

// Возвращаемые значения
//Ноль означает успех. 
// Ненулевое значение — если произошла ошибка.

int nexus_database_connector (MYSQL *conn)
{
int connect_result = 0;
            connect_result == mysql_real_connect(conn, 
            "localhost", // ip_adress
            "my_user", // user
            "my_password",// pass
            "my_database", // dbname
0, NULL, 0);
printf("Происходит подключение к MYSQL");

if(connect_result == 0)
{
    printf("Подключение к MYSQL удачно");
}
else
{
    printf("Подключения к базе данных неудачно");
    mysql_close(conn);
    break;

}


}
