/**
 * @file cpu_interpreter.h
 * @brief Prototypes, macros, enumerators and global variables...
 *
 * Most of the macros in this file play a decisive role in what this system can achieve.
 * The program memory size determines the maximum size of the programs, while the stack size
 * determines the maximum number of nested function calls.
 */

#ifndef CPU_INTERPRETER_H
#define CPU_INTERPRETER_H

// ------------------------------------------------------------------------------
// INCLUDES
// ------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>

#include "thread_cpu.h"
#include "bas_various.h"
#include "bas_video.h"
#include "bas_audio.h"

// ------------------------------------------------------------------------------
// PROTOTYPES
// ------------------------------------------------------------------------------

uint16_t get_linenumber (void);
void init_basic (void);
void interpreter (void);

// ------------------------------------------------------------------------------
// MACROS
// ------------------------------------------------------------------------------

/*
 * MEMORY_SIZE = PROGRAM_SPACE + VAR_SIZE + STACK_SIZE
 * 1200 is the approximate footprint of CPU stack and variables used by the firmware
 */

#define HIGHLOW_HIGH    1
#define HIGHLOW_UNKNOWN 4

#define MEMORY_SIZE 65526       // 64 kB
#define INPUT_BUFFER_SIZE 8     // 8 Byte
#define MAX_FRAME_COUNT 10

#define STACK_SIZE (sizeof(struct stack_for_frame) * MAX_FRAME_COUNT)
#define VAR_SIZE sizeof(int16_t)

#define STACK_GOSUB_FLAG 'G'
#define STACK_FOR_FLAG 'F'

// ------------------------------------------------------------------------------
// ENUMERATORS
// ------------------------------------------------------------------------------

enum EXECUTION_STATUS {
        POST_CMD_NOTHING = 0,
        POST_CMD_EXEC_LINE = 1,
        POST_CMD_NEXT_LINE = 2,
        POST_CMD_NEXT_STATEMENT = 3,
        POST_CMD_WARM_RESET = 4,
        POST_CMD_PROMPT = 5,
        POST_CMD_LOOP = 6
};


// ------------------------------------------------------------------------------
// DATA TYPES
// ------------------------------------------------------------------------------

typedef uint16_t LINE_NUMBER;
typedef guchar LINE_LENGTH;

struct stack_for_frame {
        guchar frame_type;
        guchar for_var;
        uint16_t terminal;
        uint16_t step;
        guchar *line_ptr;
        guchar *text_ptr;
};

struct stack_gosub_frame {
        uint16_t frame_type;
        guchar *line_ptr;
        guchar *text_ptr;
};

// ------------------------------------------------------------------------------
// GLOBALS
// ------------------------------------------------------------------------------

// general messages (definitions in printing.c)
extern const guchar msg_welcome[25];
extern const guchar msg_ram_bytes[11];
extern const guchar msg_rom_bytes[11];
extern const guchar msg_available[17];
extern const guchar msg_break[7];
extern const guchar msg_ok[3];

// error messages (definitions in printing.c)
extern const guchar err_msgxl[6];
extern const guchar err_msgxr[7];
extern const guchar err_msg01[20];
extern const guchar err_msg02[13];
extern const guchar err_msg03[15];
extern const guchar err_msg04[21];
extern const guchar err_msg05[20];
extern const guchar err_msg07[18];
extern const guchar err_msg08[21];
extern const guchar err_msg09[20];
extern const guchar err_msg0A[18];
extern const guchar err_msg0B[17];
extern const guchar err_msg0C[19];
extern const guchar err_msg0D[14];
extern const guchar err_msg0E[17];
extern const guchar err_msg0F[16];
extern const guchar err_msg10[20];
extern const guchar err_msg11[22];
extern const guchar err_msg12[23];
extern const guchar err_msg13[13];
extern const guchar err_msg14[24];
extern const guchar err_msg15[21];

// functions that return nothing / might print a value (definition in parser.c)
extern const guchar commands[208];

// functions that return a value / print nothing (definition in parser.c)
extern const guchar functions[27];

// relational operators (definition in parser.c)
extern const guchar relop_table[12];

// other keywords (definitions in parser.c)
extern const guchar to_tab[3];
extern const guchar step_tab[5];
extern const guchar highlow_tab[12];

LINE_LENGTH linelen;
LINE_NUMBER linenum;

guchar program_space[MEMORY_SIZE];
guchar input_buffer[INPUT_BUFFER_SIZE];

guchar *variables_ptr;
guchar *stack_ptr;
guchar *line_ptr;
guchar *text_ptr;
guchar *prog_end_ptr;
guchar *stack_limit;
guchar error_code;


#endif
