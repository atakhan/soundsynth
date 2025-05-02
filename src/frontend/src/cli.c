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
            case C4_NOTE: printw("C4"); break;
            case D4_NOTE: printw("D4"); break;
            case E4_NOTE: printw("E4"); break;
            case F4_NOTE: printw("F4"); break;
            case G4_NOTE: printw("G4"); break;
            case A4_NOTE: printw("A4"); break;
            case B4_NOTE: printw("B4"); break;
            case C5_NOTE: printw("C5"); break;
            default: printw("Unknown");
        }
        printw(" (%d Hz)", current_note);
    } else {
        printw("No sound..");
    }

    refresh();
}