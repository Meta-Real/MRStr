/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_set_str(mrstr_p, const char*)
 * Sets the destination data with the source
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

void mrstr_set_str(mrstr_p dst, const char* src)
{
    if (!src)
        return;

    size_t size = strlen(src);

    if (!size)
        return;

    MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_set_str function: can not allocate %llu bytes from memory\n",
            size + 1
        );
        abort();
#else
        err_code = ALLOC_ERR;
        return;
#endif
    }

    MRSTR_SIZE(dst) = size;

    do
        MRSTR_DATA(dst)[size] = src[size];
    while (size--);
}
