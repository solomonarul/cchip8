#pragma once
#ifndef CCHIP8_DRIVER_H
#define CCHIP8_DRIVER_H

#include <auxum/file/ini.h>
#include <auxum/data/bitset.h>
#include <cchip8/state.h>
#include <cchip8/cpu/interpreter.h>
#include <SDL3/SDL.h>

struct cchip8_context {
    chip8_state_t state;
    bitset_t display_memory;
    SDL_RWLock* display_lock;
    uint32_t speed;
    dynarray_t key_mappings[0x10];
    union {
        chip8_interpreter_t interpreter;
    } cpu;
    uint8_t memory[0x10000];
};
typedef struct cchip8_context cchip8_context_t;

maybe_t cchip8_run_from_ini(ini_file_t* config);

#endif
