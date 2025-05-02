#ifndef SOUNDSYNTH_SRC_BACKEND_INC_API_H
#define SOUNDSYNTH_SRC_BACKEND_INC_API_H

#include <ncurses.h>
#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

#include "sound_notes.h"
#include "sound.h"
#include "logger.h"
#include "cli.h"

void InitProgram();
void DestroyProgram();

void startNote(int note);
void stopNote();

#endif // SOUNDSYNTH_SRC_BACKEND_INC_API_H
