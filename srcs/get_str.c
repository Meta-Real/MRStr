/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_get_str(mrstr_pc)
 * Returns the data of source in string form
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

char* mrstr_get_str(mrstr_pc src)
{
    if (!MRSTR_LEN(src))
        return NULL;

    char* dst = __mrstr_das_alloc(MRSTR_LEN(src) + 1);

    if (!dst)
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_get_str function: can not allocate %llu bytes from memory\n",
            MRSTR_LEN(src) + 1);
        abort();
#else
        err_code = ALLOC_ERR;
        return NULL;
#endif
    }

    size_t i;
    for (i = 0; i <= MRSTR_LEN(src); i++)
        dst[i] = MRSTR_DATA(src)[i];

    return dst;
}
