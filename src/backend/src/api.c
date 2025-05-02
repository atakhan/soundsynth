#include "api.h"

void startNote(int note) {
    SoundSystem_StartNote(note);
}

void stopNote() {
    SoundSystem_StopNote();
}

void InitProgram() {
    InitNcurses();
    SoundSystem_Init();
}

void DestroyProgram() {
    endwin();
    SoundSystem_Shutdown();
}