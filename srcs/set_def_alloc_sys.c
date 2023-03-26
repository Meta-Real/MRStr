/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_set_def_alloc_sys(void* (*)(size_t), void* (*)(void*, size_t), void (*)(void*))
 * Replaces the default allocation system
 *
 * input reqs:
 *  (mrstr_alloc) pointer must be valid
 *  (mrstr_realloc) pointer must be valid
 *  (mrstr_free) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_set_def_alloc_sys(
    void* (*mrstr_alloc)(size_t size),
    void* (*mrstr_realloc)(void* block, size_t size),
    void (*mrstr_free)(void* block)
)
{
    if (mrstr_alloc)
       __mrstr_das_alloc = mrstr_alloc;

    if (mrstr_realloc)
       __mrstr_das_realloc = mrstr_realloc;

    if (mrstr_free)
       __mrstr_das_free = mrstr_free;
}
