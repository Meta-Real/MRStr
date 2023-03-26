/*/
 * MetaReal String Library version 1.0.0
 *
 * Setting up manual debugging and allocation system
/*/

#include <mrstr.h>

char err_code = NONE_ERR;

void* (*__mrstr_das_alloc)(size_t size) = malloc;
void* (*__mrstr_das_realloc)(void* block, size_t size) = realloc;
void (*__mrstr_das_free)(void* block) = free;
