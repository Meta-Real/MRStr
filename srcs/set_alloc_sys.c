/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_set_alloc_sys(void *(*)(size_t), void *(*)(void*, size_t), void (*)(void*))
 * Replaces the default allocation system (DAS) functions
 *
 * input reqs:
 *  (mrstr_alloc) pointer must be valid
 *  (mrstr_realloc) pointer must be valid
 *  (mrstr_free) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_set_alloc_sys(
    void *(*mrstr_alloc)(mrstr_size size),
    void *(*mrstr_realloc)(void *block, mrstr_size size),
    void (*mrstr_free)(void *block))
{
    if (mrstr_alloc)
        __mrstr_alloc = mrstr_alloc;
    if (mrstr_realloc)
        __mrstr_realloc = mrstr_realloc;
    if (mrstr_free)
        __mrstr_free = mrstr_free;
}
