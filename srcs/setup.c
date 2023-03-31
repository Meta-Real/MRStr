/*/
 * MetaReal String Library version 1.0.0
 *
 * Setting up manual debugging (if enabled) and allocation system
/*/

#include <mrstr.h>

#ifndef __MRSTR_DBG__
err_code_t err_code = NONE_ERR;
#endif

void* (*__mrstr_das_alloc)(size_t size) = malloc;
void* (*__mrstr_das_realloc)(void* block, size_t size) = realloc;
void (*__mrstr_das_free)(void* block) = free;
