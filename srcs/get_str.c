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

mrstr_str mrstr_get_str(mrstr_pc src)
{
    if (!MRSTR_LEN(src))
        return NULL;

    mrstr_str dst = __mrstr_das_alloc(MRSTR_LEN(src) + 1);

    if (!dst)
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_get_str function: can not allocate %llu bytes from memory\n",
            MRSTR_LEN(src) + 1);
        abort();
#else
        err_code = ALOC_ERR;
        return NULL;
#endif
    }

    mrstr_size i;
    for (i = 0; i <= MRSTR_LEN(src); i++)
        dst[i] = MRSTR_DATA(src)[i];

    return dst;
}
