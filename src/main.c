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
        Draw(current_note);
        int ch = getch();
        

        switch(ch) {
            case 27:
                running =false;
                break;
            case 'q': current_note = C2_NOTE; break;
            case 'w': current_note = CS2_NOTE; break;
            case 'e': current_note = D2_NOTE; break;
            case 'r': current_note = DS2_NOTE; break;
            case 't': current_note = E2_NOTE; break;
            case 'y': current_note = F2_NOTE; break;
            case 'u': current_note = FS2_NOTE; break;
            case 'i': current_note = G2_NOTE; break;
            case 'o': current_note = GS2_NOTE; break;
            case 'p': current_note = A2_NOTE; break;
            case '[': current_note = AS2_NOTE; break;
            case ']': current_note = B2_NOTE; break;
            default: current_note = REST; break;
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


