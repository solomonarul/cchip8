#pragma once
#ifndef CHIP8_INTERPRETER_H
#define CHIP8_INTERPRETER_H

#include "../state.h"
#include <stdbool.h>

typedef struct chip8_interpreter
{
    bool running;
    long timer;
    chip8_state_t* state;
} chip8_interpreter_t;

void chip8_interpreter_init(chip8_interpreter_t* self);
void chip8_interpreter_update_timers(chip8_interpreter_t* self, long dt);
void chip8_interpreter_step(chip8_interpreter_t* self);

#endif
