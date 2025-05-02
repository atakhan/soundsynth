#ifndef SOUNDSYNTH_SRC_FRONTEND_INC_CLI_H
#define SOUNDSYNTH_SRC_FRONTEND_INC_CLI_H

#include <ncurses.h>
#include "sound_notes.h"

void InitNcurses();
void Draw(int current_note);

#endif  // SOUNDSYNTH_SRC_FRONTEND_INC_CLI_H