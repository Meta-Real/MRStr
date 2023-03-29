/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_nget_str(mrstr_pc, size_t)
 * Returns the data of source in string form (up to specified size)
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

char* mrstr_nget_str(mrstr_pc src, size_t size)
{
    if (!MRSTR_LEN(src) || !size)
        return NULL;

    if (size > MRSTR_LEN(src))
        size = MRSTR_LEN(src);

    char* dst = __mrstr_das_alloc(size + 1);

    if (!dst)
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_nget_str function: can not allocate %llu bytes from memory\n",
            size + 1);
        abort();
#else
        err_code = ALLOC_ERR;
        return NULL;
#endif
    }

    dst[size--] = '\0';

    do
        dst[size] = MRSTR_DATA(src)[size];
    while (size--);

    return dst;
}
