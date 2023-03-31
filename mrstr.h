/*/
 * MetaReal String Library version 1.0.0
 *
 * Main header file
/*/

#ifndef __MRSTR__
#define __MRSTR__

#include <stdio.h>
#include <stdlib.h>

typedef char mrstr_chr;
typedef mrstr_chr* mrstr_str;
typedef const mrstr_chr* mrstr_cstr;

typedef size_t mrstr_size;
typedef size_t mrstr_idx;

typedef char mrstr_bool;

#define MRSTR_DEF_SIZE 128

#define MRSTR_TRUE 1
#define MRSTR_FALSE 0

struct __mrstr__
{
    mrstr_str _data;

    mrstr_size _size;
    mrstr_size _len;

    mrstr_idx _offset;
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

void mrstr_init2(mrstr_p str, mrstr_str data);
void mrstr_init3(mrstr_p str, mrstr_str data, mrstr_size size, mrstr_idx offset);

void mrstr_clear(mrstr_p str);
void mrstr_clears(mrstr_p str, ...);

/* set functions */

void mrstr_set(mrstr_p dst, mrstr_pc src);
void mrstr_set_str(mrstr_p dst, mrstr_cstr src);
void mrstr_set_chr(mrstr_p dst, mrstr_chr src);

void mrstr_nset(mrstr_p dst, mrstr_pc src, mrstr_size size);
void mrstr_nset_str(mrstr_p dst, mrstr_cstr, mrstr_size size);

void mrstr_link(mrstr_p dst, mrstr_p src);
void mrstr_swap(mrstr_p str1, mrstr_p str2);

/* get functions */

mrstr_str mrstr_get_str(mrstr_pc src);
mrstr_chr mrstr_get_chr(mrstr_pc src, mrstr_idx idx);

mrstr_str mrstr_nget_str(mrstr_pc src, mrstr_size size);

/* input and output functions */

void mrstr_inp(mrstr_p dst, FILE* src);
void mrstr_ninp(mrstr_p dst, FILE* src, mrstr_size size);

void mrstr_out(FILE* dst, mrstr_pc src);
void mrstr_nout(FILE* dst, mrstr_pc src, mrstr_size size);

/* binary operation functions */

void mrstr_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2); //
void mrstr_nconcat(mrstr_p res, mrstr_pc str1, mrstr_pc str2, mrstr_size size); //

void mrstr_remove(mrstr_p res, mrstr_pc str, mrstr_idx idx); //
void mrstr_eremove(mrstr_p res, mrstr_p str, mrstr_idx eidx); //
void mrstr_rremove(mrstr_p res, mrstr_p str, mrstr_idx sidx, mrstr_idx eidx); //

void mrstr_repeat(mrstr_p res, mrstr_pc str, mrstr_size count); //

/* unary operation functions */

void mrstr_reverse(mrstr_p res, mrstr_pc str); //

/* comparison functions */

mrstr_bool mrstr_equal(mrstr_pc str1, mrstr_pc str2); //

/* find functions */

mrstr_bool mrstr_contains(mrstr_pc str, mrstr_pc substr); //
mrstr_bool mrstr_contains_str(mrstr_pc str, mrstr_cstr substr); //
mrstr_bool mrstr_contains_chr(mrstr_pc str, mrstr_chr chr); //

/* manual debugging system */

#ifndef __MRSTR_DBG__

enum _err_codes_
{
    NONE_ERR, // nothing
    ALOC_ERR, // allocation error
    ORNG_ERR  // out of range error
};

typedef char err_code_t;

extern err_code_t err_code;

#endif

/* alloc system */

extern void* (*__mrstr_das_alloc)(size_t size);
extern void* (*__mrstr_das_realloc)(void* block, size_t size);
extern void (*__mrstr_das_free)(void* block);

void mrstr_set_def_alloc_sys(
    void* (*mrstr_alloc)(size_t size),
    void* (*mrstr_realloc)(void* block, size_t size),
    void (*mrstr_free)(void* block)
);

#endif /* __MRSTR__ */
