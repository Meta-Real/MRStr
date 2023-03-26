/*/
 * MetaReal String Library version 1.0.0
/*/

#ifndef __MRSTR__
#define __MRSTR__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define __MRSTR_DBG__

struct __mrstr__
{
    char* _data;
    size_t _size;
};

typedef struct __mrstr__ mrstr_t[1];
typedef struct __mrstr__* mrstr_p;
typedef const struct __mrstr__* mrstr_pc;

#define MRSTR_DATA(x) ((x)->_data)
#define MRSTR_SIZE(x) ((x)->_size)

/* init functions */

void mrstr_init(mrstr_p str);
void mrstr_inits(mrstr_p str, ...);

void mrstr_init2(mrstr_p str, char* data);
void mrstr_init3(mrstr_p str, char* data, size_t size);

void mrstr_clear(mrstr_p str);
void mrstr_clears(mrstr_p str, ...);

/* set functions */

void mrstr_set(mrstr_p dst, mrstr_pc src);
void mrstr_set_str(mrstr_p dst, const char* src);
void mrstr_set_char(mrstr_p dst, char src);

void mrstr_nset(mrstr_p dst, mrstr_pc src, size_t size);
void mrstr_nset_str(mrstr_p dst, const char* src, size_t size);

void mrstr_oset(mrstr_p dst, mrstr_pc src, size_t offset);

void mrstr_noset(mrstr_p dst, mrstr_pc src, size_t size, size_t offset);

void mrstr_link(mrstr_p dst, mrstr_p src);
void mrstr_swap(mrstr_p str1, mrstr_p str2);

/* get functions */

char* mrstr_get_str(mrstr_pc src);
char mrstr_get_char(mrstr_pc src, size_t idx);

char* mrstr_nget_str(mrstr_pc src, size_t size);

char* mrstr_oget_str(mrstr_pc src, size_t offset);

char* mrstr_noget_str(mrstr_pc src, size_t size, size_t offset);

/* manual debugging system */

enum _err_codes_
{
    NONE_ERR, // nothing
    ALOC_ERR, // allocation error
    ORNG_ERR  // out of range error
};

extern char err_code;

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
