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
 *  (src) pointer must not be NULL
/*/

#include <mrstr.h>
#include <string.h>

char mrstr_set_str(mrstr_p dst, const char* src)
{
    size_t size = strlen(src);

    if (!size)
        return 0;

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
        return 1;
#endif
    }

    MRSTR_SIZE(dst) = size;

    do
        MRSTR_DATA(dst)[size] = src[size];
    while (size--);

    return 0;
}
