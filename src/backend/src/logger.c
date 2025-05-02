#include "logger.h"

// Функция для логирования
void log_message(log_level_t level, const char *format, ...) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        return; // Не удалось открыть файл, просто выходим
    }

    // Получаем текущее время
    time_t now = time(NULL);
    struct tm *tm_info = localtime(&now);
    char time_buffer[26];
    strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    // Записываем уровень логирования
    switch (level) {
        case LOG_INFO:
            fprintf(log_file, "[%s] [INFO] ", time_buffer);
            break;
        case LOG_WARNING:
            fprintf(log_file, "[%s] [WARNING] ", time_buffer);
            break;
        case LOG_ERROR:
            fprintf(log_file, "[%s] [ERROR] ", time_buffer);
            break;
        case LOG_ACTION:
            fprintf(log_file, "[%s] [ACTION] ", time_buffer);
            break;
        case LOG_TRACE:
            fprintf(log_file, "[%s] [TRACELOG] ", time_buffer);
            break;
        case LOG_DEBUG:
            fprintf(log_file, "[%s] [DEBUG] ", time_buffer);
            break;
    }

    // Записываем сообщение
    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    va_end(args);

    fprintf(log_file, "\n"); // Перевод строки
    fclose(log_file);
}