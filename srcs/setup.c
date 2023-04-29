/*/
 * MetaReal String Library version 1.0.0
 *
 * Setup file for manual debugging (if enabled) and allocation system
/*/

#include <mrstr.h>

#ifndef __MRSTR_DBG__
mrstr_err_code_t mrstr_err_code = NONE_ERR;
#endif

void *(*__mrstr_alloc)(mrstr_size size) = mrstr_def_alloc;
void *(*__mrstr_realloc)(void *block, mrstr_size size) = mrstr_def_realloc;
void (*__mrstr_free)(void *block) = mrstr_def_free;

void *mrstr_def_alloc(mrstr_size size)
{
    return malloc(size);
}

void *mrstr_def_realloc(void *block, mrstr_size size)
{
    return realloc(block, size);
}

void mrstr_def_free(void *block)
{
    free(block);
}
