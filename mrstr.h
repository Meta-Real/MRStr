/*/
 * MetaReal String Library version 1.0.0
 *
 * Main header file
/*/

#ifndef __MRSTR__
#define __MRSTR__

#include <stdio.h>
#include <stdlib.h>

#define __MRSTR_DBG__

struct __mrstr__
{
    char* _data;

    size_t _size;
    size_t _len;

    size_t _offset;
};

typedef struct __mrstr__ mrstr_t[1];
typedef struct __mrstr__* mrstr_p;
typedef const struct __mrstr__* mrstr_pc;

#define MRSTR_DATA(x) ((x)->_data)
#define MRSTR_SIZE(x) ((x)->_size)
#define MRSTR_LEN(x) ((x)->_len)
#define MRSTR_OFFSET(x) ((x)->_offset)

/* init functions */

void mrstr_init(mrstr_p str);
void mrstr_inits(mrstr_p str, ...);

void mrstr_init2(mrstr_p str, char* data);
void mrstr_init3(mrstr_p str, char* data, size_t size, size_t offset);

void mrstr_clear(mrstr_p str);
void mrstr_clears(mrstr_p str, ...);

/* set functions */

void mrstr_set(mrstr_p dst, mrstr_pc src);
void mrstr_nset(mrstr_p dst, mrstr_pc src, size_t size);

void mrstr_set_str(mrstr_p dst, const char* src);
void mrstr_nset_str(mrstr_p dst, const char* src, size_t size);

void mrstr_set_char(mrstr_p dst, char src);

void mrstr_link(mrstr_p dst, mrstr_p src);
void mrstr_swap(mrstr_p str1, mrstr_p str2);

/* get functions */

char* mrstr_get_str(mrstr_pc src);
char* mrstr_nget_str(mrstr_pc src, size_t size);

char mrstr_get_char(mrstr_pc src, size_t idx);

/* input and output functions */

void mrstr_inp(mrstr_p dst, FILE* src); //
void mrstr_ninp(mrstr_p dst, FILE* src, size_t size); //

void mrstr_out(FILE* dst, mrstr_pc src); //
void mrstr_nout(FILE* dst, mrstr_pc src, size_t size); //

/* binary operation functions */

void mrstr_append(mrstr_p res, mrstr_pc str1, mrstr_pc str2); //
void mrstr_nappend(mrstr_p res, mrstr_pc str1, mrstr_pc str2, size_t size); //

void mrstr_remove(mrstr_p res, mrstr_pc str, size_t idx); //
void mrstr_eremove(mrstr_p res, mrstr_p str, size_t eidx); //
void mrstr_rremove(mrstr_p res, mrstr_p str, size_t idx1, size_t idx2); //

void mrstr_repeat(mrstr_p res, mrstr_pc str, size_t count); //

/* comparison functions */

/* manual debugging system */

enum _err_codes_
{
    NONE_ERR, // nothing
    ALOC_ERR, // allocation error
    ORNG_ERR  // out of range error
};

char err_code;

/* alloc system */

void* (*__mrstr_das_alloc)(size_t size);
void* (*__mrstr_das_realloc)(void* block, size_t size);
void (*__mrstr_das_free)(void* block);

void mrstr_set_def_alloc_sys(
    void* (*mrstr_alloc)(size_t size),
    void* (*mrstr_realloc)(void* block, size_t size),
    void (*mrstr_free)(void* block)
);

#endif /* __MRSTR__ */
