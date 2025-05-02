#ifndef SOUNDSYNTH_SRC_BACKEND_INC_SOUND_H
#define SOUNDSYNTH_SRC_BACKEND_INC_SOUND_H

#include <math.h>
#include <stdio.h>
#include <stdbool.h>

#include <SDL.h>

#include "sound_notes.h"

// Defines
#define TWO_PI                (2.0 * M_PI)
#define BUFFER_SIZE_MS        100  // Размер буфера в миллисекундах
#define SAMPLE_RATE           44100
#define AMPLITUDE             127
#define AUDIO_BUFFER_SAMPLES  2048



typedef struct {
    int *sequence;
    int length;
    int tempo;
    SDL_atomic_t stop_flag;
} MelodyData;

typedef struct {
    MelodyData melody;
    SDL_Thread *music_thread;
    bool sdl_inited;
} BrickGameSound;

// FUNCTION DEFINES
void SoundSystem_Init();
void SoundSystem_Shutdown();

void SoundSystem_StartNote(int note);
void SoundSystem_StopNote();


#endif // SOUNDSYNTH_SRC_BACKEND_INC_SOUND_H
