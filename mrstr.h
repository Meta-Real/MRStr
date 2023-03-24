/*/
 * MetaReal String Library version 1.0.0
/*/

#ifndef __MRSTR__
#define __MRSTR__

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define __MRSTR_DEBUG__ 0

struct __mrstr__
{
    char* _data;
    size_t _size;
};

typedef struct __mrstr__ mrstr_t[1];
typedef const struct __mrstr__ mrstr_tc[1];

#define MRSTR_DATA(x) ((x)->_data)
#define MRSTR_SIZE(x) ((x)->_size)

/* functions */

void mrstr_init(mrstr_t mrstr);
void mrstr_init2(mrstr_t mrstr, char* data);
void mrstr_init3(mrstr_t mrstr, char* data, size_t size);

void mrstr_clear(mrstr_t mrstr);

char mrstr_set(mrstr_t dst, mrstr_tc src);
char mrstr_set_str(mrstr_t dst, const char* src);
char mrstr_set_char(mrstr_t dst, char src);

char mrstr_nset(mrstr_t dst, mrstr_tc src, size_t size);
char mrstr_nset_str(mrstr_t dst, const char* src, size_t size);

// alloc system

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
