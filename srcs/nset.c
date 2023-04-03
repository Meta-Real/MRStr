/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_nset(mrstr_p, mrstr_pc, mrstr_size)
 * Sets the destination data with the source data (up to the specified length)
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) pointer equals (src) pointer) (memory leak)
 *  (src) pointer must be valid
/*/

#include "intern.h"
#include <string.h>

void mrstr_nset(mrstr_p dst, mrstr_pc src, mrstr_size len)
{
    if (dst == src)
    {
        if (len >= MRSTR_LEN(dst))
            return;

        if (!len && !MRSTR_OFFSET(dst))
        {
            __mrstr_das_free(MRSTR_DATA(dst));
            MRSTR_LEN(dst) = 0;

            return;
        }

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(dst) - MRSTR_OFFSET(dst),
            len + MRSTR_OFFSET(dst) + 1);

        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_nset", len + MRSTR_OFFSET(dst) + 1,);

        MRSTR_DATA(dst) = t_data + MRSTR_OFFSET(dst);
        MRSTR_DATA(dst)[len] = '\0';

        MRSTR_LEN(dst) = len;

        return;
    }

    if (!MRSTR_LEN(src) || !len)
        return;

    if (len > MRSTR_LEN(src))
        len = MRSTR_LEN(src);

    MRSTR_DATA(dst) = __mrstr_das_alloc(len + 1);

    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_nset", len + 1,);

    memcpy(MRSTR_DATA(dst), MRSTR_DATA(src), len);
    MRSTR_DATA(dst)[len] = '\0';

    MRSTR_LEN(dst) = len;
}
