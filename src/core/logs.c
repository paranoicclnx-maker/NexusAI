
#include <stdio.h>      // Работа с файлами: FILE, fopen, fprintf, fclose
#include <time.h>       // Работа со временем: time, localtime, strftime
#include "errors.h"     // Коды ошибок NEXUS AI
#include "logs.h"       // Объявление функции и enum LogLevel

#define T 64            // Размер массива для хранения даты и времени

int nexus_log_write(LogLevel level, const char *module, const char *message)
{
    // Переменная для хранения текстового названия уровня
    const char *level_text;

    // Преобразуем числовой уровень enum в текст
    switch (level)
    {
        case LOG_INFO:
            level_text = "INFO";
            break;

        case LOG_WARNING:
            level_text = "WARNING";
            break;

        case LOG_ERROR:
            level_text = "ERROR";
            break;

        // Если передан неизвестный уровень
        default:
            level_text = "UNKNOWN";
            break;
    }

    // Получаем текущее календарное время
    time_t timenoreal = time(NULL);

    // Преобразуем время в локальную дату и время
    struct tm *timelogs = localtime(&timenoreal);

    // Проверяем, удалось ли получить локальное время
    if (timelogs == NULL)
    {
        return ERROR_LOG;
    }

    // Переменная для результата формирования даты
    size_t logs;

    // Массив для хранения даты и времени в виде строки
    char buffer[T];

    // Формируем дату в формате ГГГГ-ММ-ДД ЧЧ:ММ:СС
    logs = strftime( buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", timelogs);

    // Если дата не сформировалась, возвращаем ошибку
    if (logs == 0)
    {
        return ERROR_LOG;
    }

    // Открываем файл в режиме добавления
    // Старые записи сохраняются, новые добавляются в конец
    FILE *file = fopen("core/logs.txt", "a");

    // Проверяем, удалось ли открыть файл
    if (file == NULL)
    {
        return ERROR_LOG;
    }

    // Записываем дату, уровень, модуль и сообщение
    // Каждый %s заменяется соответствующей строкой
    int result = fprintf( file, "[%s] [%s] [%s] %s", buffer, level_text, module, message);

    // Закрываем файл и сохраняем результат закрытия
    int close_result = fclose(file);

    // Проверяем успешность записи и закрытия
    if (result >= 0 && close_result == 0)
    {
        return ERROR_SUCCESS;
    }

    // Если запись или закрытие завершились ошибкой
    return ERROR_LOG;
}
