#include "cli.h"

void InitNcurses() {
    // Инициализация ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
}

void Print(int y, int x, char *message) {
    mvprintw(y, x, message);
}

void Draw(int current_note) {
    clear();
    if (current_note) {
        printw("Current note: ");
        switch(current_note) {
            case C2_NOTE: printw("C2"); break;
            case CS2_NOTE: printw("CS2"); break;
            case D2_NOTE: printw("D2"); break;
            case DS2_NOTE: printw("DS2"); break;
            case E2_NOTE: printw("E2"); break;
            case F2_NOTE: printw("F2"); break;
            case FS2_NOTE: printw("FS2"); break;
            case G2_NOTE: printw("G2"); break;
            case GS2_NOTE: printw("GS2"); break;
            case A2_NOTE: printw("A2"); break;
            case AS2_NOTE: printw("AS2"); break;
            case B2_NOTE: printw("B2"); break;
            default: printw("Unknown");
        }
        printw(" (%d Hz)", current_note);
    } else {
        printw("No sound..");
    }

    refresh();
}