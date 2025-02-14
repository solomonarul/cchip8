#include "state.h"
#include "memory.h"

#include <string.h>

void chip8_state_init(chip8_state_t* self)
{
    self->pc = 0x200;
    memset(self->v, 0x00, sizeof(uint8_t) * 0x10);
    self->read_b = chip8_memory_read_b; self->read_w = chip8_memory_read_w; self->write_b = chip8_memory_write_b;
    self->draw_sprite = NULL; self->clear_screen = NULL;
}

void chip8_state_log(chip8_state_t* self, FILE* file)
{
    fprintf(file, "[INFO]: Current CHIP8 state:\n");
    fprintf(file, "| PC: %04X |  I: %04X |\n", self->pc, self->i);
    for(uint8_t base = 0x00; base <= 0x8; base += 0x8)
    {
        for(uint8_t index = base; index < base + 0x8; index++)
            fprintf(file, "| V[%01X]: %02X ", index, self->v[index]);
        fprintf(file, "|\n");
    }
}
