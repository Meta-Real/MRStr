/*/
 * MetaReal String Library version 1.0.0
 *
 * Setting up manual debugging (if enabled) and allocation system
/*/

#include <mrstr.h>

#ifndef __MRSTR_DBG__
err_code_t err_code = NONE_ERR;
#endif

void* (*__mrstr_das_alloc)(mrstr_size size) = mrstr_def_alloc;
void* (*__mrstr_das_realloc)(void* block, mrstr_size size) = mrstr_def_realloc;
void (*__mrstr_das_free)(void* block) = mrstr_def_free;

void* mrstr_def_alloc(mrstr_size size)
{
    return malloc(size);
}

void* mrstr_def_realloc(void* block, mrstr_size size)
{
    return realloc(block, size);
}

void mrstr_def_free(void* block)
{
    free(block);
}
