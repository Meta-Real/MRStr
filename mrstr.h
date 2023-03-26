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

char mrstr_set(mrstr_p dst, mrstr_pc src);
char mrstr_set_str(mrstr_p dst, const char* src);
char mrstr_set_char(mrstr_p dst, char src);

char mrstr_nset(mrstr_p dst, mrstr_pc src, size_t size);
char mrstr_nset_str(mrstr_p dst, const char* src, size_t size);

char mrstr_oset(mrstr_p dst, mrstr_pc src, size_t offset);

char mrstr_onset(mrstr_p dst, mrstr_pc src, size_t size, size_t offset);

void mrstr_link(mrstr_p dst, mrstr_p src);
void mrstr_swap(mrstr_p str1, mrstr_p str2);

/* alloc system */

#define __VAR_ATTR__ static __attribute__((unused))

__VAR_ATTR__ void* (*__mrstr_das_alloc)(size_t size)  = malloc;
__VAR_ATTR__ void* (*__mrstr_das_realloc)(void* block, size_t size) = realloc;
__VAR_ATTR__ void (*__mrstr_das_free)(void* block) = free;

void mrstr_set_def_alloc_sys(
    void* (*mrstr_alloc)(size_t size),
    void* (*mrstr_realloc)(void* block, size_t size),
    void (*mrstr_free)(void* block)
);

#endif /* __MRSTR__ */
