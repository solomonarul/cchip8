#pragma once
#ifndef AUXUM_INI_H
#define AUXUM_INI_H

#include "../data/dynarray.h"
#include <stdio.h>

#define MAX_LINE_WIDTH 255

struct ini_file {
    dynarray_t sections;
};
typedef struct ini_file ini_file_t;

struct ini_section{
    char* key;
    dynarray_t values;
};
typedef struct ini_section ini_section_t;

struct ini_data{
    enum {
        NONE = (uint8_t)0,
        ARRAY,
        VALUE,
        COUNT
    } type;

    union {
        char* string;       // For values.
        dynarray_t array;   // For arrays, should allow nesting.
    } data;
};
typedef struct ini_data ini_data_t;

struct ini_value {
    char* key;
    ini_data_t value;
};
typedef struct ini_value ini_value_t;

ini_file_t ini_file_parse(FILE* file);
void ini_file_print(ini_file_t* self, FILE* file);
void ini_file_free(ini_file_t* self);

ini_section_t* ini_file_get_section(ini_file_t* self, char* const key);
ini_data_t* ini_file_get_data(ini_file_t* self, char* const section, char* const key);
ini_data_t* ini_section_get_data(ini_section_t* self, char* const key);
int ini_data_get_array_size(ini_data_t* self);
ini_data_t* ini_data_get_from_array(ini_data_t* self, uint32_t index);
char* ini_data_get_as_string(ini_data_t* self);
int ini_data_get_as_int(ini_data_t* self);
bool ini_data_get_as_bool(ini_data_t* self);
#define ini_get_string(file, section, key) (ini_data_get_as_string(ini_file_get_data(file, section, key)))
#define ini_get_int(file, section, key) (ini_data_get_as_int(ini_file_get_data(file, section, key)))
#define ini_get_bool(file, section, key) (ini_data_get_as_bool(ini_file_get_data(file, section, key)))

#endif
