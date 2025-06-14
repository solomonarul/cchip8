#pragma once
#ifndef CHIP8_STATE_H
#define CHIP8_STATE_H

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

typedef uint8_t(*chip8_read_b_f)(void*, uint16_t);
typedef uint16_t(*chip8_read_w_f)(void*, uint16_t);
typedef void(*chip8_write_b_f)(void*, uint16_t, uint8_t);
typedef bool(*chip8_draw_sprite_f)(void*, uint16_t, uint8_t, uint8_t, uint8_t);
typedef void(*chip8_clear_f)(void*);
typedef void(*chip8_set_dt_f)(void*, uint8_t);
typedef uint8_t(*chip8_get_dt_f)(void*);
typedef bool(*chip8_key_status_f)(void*, uint8_t);
typedef uint8_t(*chip8_random_f)(void*);
typedef void(*chip8_resize_f)(void*, uint8_t, uint8_t);
typedef enum {
    CHIP8_SCROLL_DOWN = 0,
    CHIP8_SCROLL_LEFT,
    CHIP8_SCROLL_RIGHT,
} chip8_scroll_direction_t;
typedef void(*chip8_scroll_f)(void*, uint8_t, chip8_scroll_direction_t);

typedef enum chip8_run_mode {
    CHIP8_MODE_NORMAL = 0,
    CHIP8_MODE_SCHIP_MODERN
} chip8_run_mode_t;

typedef struct chip8_state
{
    bool draw_flag;
    chip8_run_mode_t mode;
    uint16_t pc, i, stack[0x100];
    uint8_t display_width, display_height;
    uint8_t v[0x10], sp, dt, st, last_key;
    uint16_t lowres_font_address, hires_font_address;
    chip8_read_b_f read_b;
    chip8_read_w_f read_w;
    chip8_write_b_f write_b;
    chip8_draw_sprite_f draw_sprite;
    chip8_clear_f clear_screen;
    chip8_key_status_f get_key_status;
    chip8_random_f get_random;
    chip8_resize_f resize;
    chip8_scroll_f scroll;
    void* aux_arg;
} chip8_state_t;

void chip8_state_init(chip8_state_t* self);
void chip8_state_log(chip8_state_t* self, FILE* file);

#endif
