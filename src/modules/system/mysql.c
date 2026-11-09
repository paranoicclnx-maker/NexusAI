/*
 * Программа "Звонок в справочную MySQL".
 * Для чайников: учим функции через аналогию с телефонным звонком.
 * 
 * Инструкция:
 * 1. Сохрани этот текст в файл db_phone.c
 * 2. Замени "my_user", "my_password", "my_database" на свои данные в функции connect().
 * 3. Скомпилируй и запусти.
 */

#include <stdio.h>
#include <stdlib.h>
#include <mysql.h>

// Функция, которая имитирует "набор номера и авторизацию"
void connect_to_database(MYSQL *conn) {
    printf("Шаг 2: Берем трубку и набираем номер сервера...\n");

    /* 
     * mysql_real_connect - это наш "набор номера".
     * Мы передаем: адрес ("localhost"), логин, пароль и имя базы.
     */
    if (mysql_real_connect(conn, "localhost", "my_user", "my_password", "my_database", 0, NULL, 0) == NULL) {
        /* 
         * Если в трубке сказали "Номер не существует" или "Пароль неверный":
         * Функция вернула NULL. Мы спрашиваем у библиотеки текст ошибки 
         * (как будто прослушиваем запись автоответчика) и завершаем звонок.
         */
        printf("ОШИБКА: Сервер сбросил звонок! Причина: %s\n", mysql_error(conn));
        mysql_close(conn); // Вешаем трубку
        exit(1);           // Выходим из программы
    }

    printf("Успешно! Оператор на связи.\n");
}

// Функция, которая отправляет запрос и слушает ответ
void ask_database(MYSQL *conn) {
    printf("Шаг 3: Диктуем запрос: 'Какая у тебя версия?'\n");

    // mysql_query - это мы "диктуем текст" в трубку
    if (mysql_query(conn, "SELECT VERSION()")) {
        // Если оператор нас не понял (ошибка SQL)
        printf("ОШИБКА: Оператор не понял запрос! Причина: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    printf("Оператор принял запрос. Ждем ответ...\n");

    // mysql_store_result - это мы "записываем ответ оператора на бумагу"
    MYSQL_RES *result = mysql_store_result(conn);
    if (result == NULL) {
        printf("ОШИБКА: Не смогли записать ответ! Причина: %s\n", mysql_error(conn));
        mysql_close(conn);
        exit(1);
    }

    printf("Шаг 5: Читаем, что написал оператор на листке:\n");

    // mysql_fetch_row - это мы "читаем по одной строчке с нашего листа"
    MYSQL_ROW row = mysql_fetch_row(result);
    if (row != NULL) {
        // row[0] - это первая (и единственная) колонка в ответе
        printf("Ответ сервера: %s\n", row[0]);
    }

    // mysql_free_result - это мы "сдаем исписанный лист в макулатуру"
    printf("Шаг 6: Утилизируем черновик с ответом.\n");
    mysql_free_result(result);
}

int main() {
    printf("=== Программа 'Звонок в MySQL' ===\n");
    printf("Шаг 1: Покупаем телефонный аппарат (инициализация).\n");

    // mysql_init - мы "покупаем или берем свой телефон", чтобы было откуда звонить
    MYSQL *conn = mysql_init(NULL);
    if (conn == NULL) {
        printf("ОШИБКА: Телефон сломан, не включается!\n");
        return 1;
    }

    // === Начинаем наш разговор ===
    connect_to_database(conn); // Шаг 2: Набираем номер
    ask_database(conn);        // Шаги 3, 4, 5: Говорим и слушаем

    // mysql_close - "Вешаем трубку и убираем телефон в тумбочку"
    printf("Шаг 7: Вешаем трубку. Разговор окончен.\n");
    mysql_close(conn);

    return 0;
}
