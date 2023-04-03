/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_str mrstr_nget_str(mrstr_pc, mrstr_size)
 * Returns the data of source in string form (up to specified length)
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include "intern.h"
#include <string.h>

mrstr_str mrstr_nget_str(mrstr_pc src, mrstr_size len)
{
    if (!MRSTR_LEN(src) || !len)
        return NULL;

    if (len > MRSTR_LEN(src))
        len = MRSTR_LEN(src);

    mrstr_str dst = __mrstr_das_alloc(len + 1);

    if (!dst)
        mrstr_dbg_aloc_err("mrstr_nget_str", len + 1, NULL);

    memcpy(dst, MRSTR_DATA(src), len);
    dst[len] = '\0';

    return dst;
}
