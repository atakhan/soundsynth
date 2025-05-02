#include <SDL.h>
#include "sound.h"
#include <math.h>

static struct {
    bool sdl_inited;
    bool note_playing;
    int current_freq;
    SDL_atomic_t stop_flag;
} g_sound = {0};

static void AudioCallback(void* userdata, Uint8* stream, int len) {
    (void) userdata;
    static double phase = 0.0;
    double phase_increment = 2.0 * M_PI * g_sound.current_freq / SAMPLE_RATE;
    
    for (int i = 0; i < len; i++) {
        stream[i] = (Uint8)(AMPLITUDE * sin(phase) + 128);
        phase += phase_increment;
    }
}

bool InitSdlAudio() {
    if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0) {
        return false;
    }

    SDL_AudioSpec desired = {
        .freq = SAMPLE_RATE,
        .format = AUDIO_U8,
        .channels = 1,
        .samples = AUDIO_BUFFER_SAMPLES,
        .callback = AudioCallback,
        .userdata = NULL
    };

    if (SDL_OpenAudio(&desired, NULL) < 0) {
        return false;
    }

    return true;
}

void SoundSystem_Init() {
    if (!g_sound.sdl_inited) {
        g_sound.sdl_inited = InitSdlAudio();
        SDL_PauseAudio(0);
    }
}

void SoundSystem_Shutdown() {
    if (g_sound.sdl_inited) {
        SDL_CloseAudio();
        SDL_QuitSubSystem(SDL_INIT_AUDIO);
        g_sound.sdl_inited = false;
    }
}

void SoundSystem_StartNote(int frequency) {
    if (!g_sound.sdl_inited) return;
    
    g_sound.current_freq = frequency;
    g_sound.note_playing = true;
}

void SoundSystem_StopNote() {
    g_sound.note_playing = false;
    g_sound.current_freq = 0;
}