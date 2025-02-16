#pragma once
#ifndef CCHIP8_DRIVER_H
#define CCHIP8_DRIVER_H

#include <auxum/bitset.h>
#include <cchip8/state.h>
#include <cchip8/cpu/interpreter.h>

struct cchip8_context {
    chip8_state_t state;
    bitset_t display_memory;
    uint8_t memory[0x10000];
    chip8_interpreter_t* cpu;
};
typedef struct cchip8_context cchip8_context_t;

void cchip8_init(cchip8_context_t* self);
void cchip8_run(cchip8_context_t* self);
void cchip8_free(cchip8_context_t* self);

#endif
