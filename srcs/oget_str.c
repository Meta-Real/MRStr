/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_oget_str(mrstr_pc, size_t)
 * Returns the data of source in string form (by the specified offset)
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

char* mrstr_oget_str(mrstr_pc src, size_t offset)
{
    if (offset >= MRSTR_SIZE(src))
        return NULL;

    char* dst = __mrstr_das_alloc(MRSTR_SIZE(src) - offset + 1);

    if (!dst)
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_oget_str function: can not allocate %llu bytes from memory\n",
            MRSTR_SIZE(src) - offset + 1);
        abort();
#else
        err_code = ALLOC_ERR;
        return NULL;
#endif
    }

    size_t i;
    for (i = offset; i <= MRSTR_SIZE(src); i++)
        dst[i - offset] = MRSTR_DATA(src)[i];

    return dst;
}
