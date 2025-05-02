#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "api.h"

int main() {
    InitProgram();

    int current_note = C5_NOTE;
    bool running = true;
    
    Draw(current_note);
    
    while (running) {
        int ch = getch();
        
        if (ch == 'q') {
            running =false;
        }
        
        // Обновляем интерфейс
        Draw(current_note);

        // Управление звуком
        if (current_note > 0) {
            startNote(current_note);
        } else {
            stopNote();
        }

        // Небольшая задержка для снижения нагрузки на CPU
        usleep(10000); // 10 мс
    }
    
    // Завершение работы
    DestroyProgram();
    
    return 0;
}


