/*/
 * MetaReal String Library version 1.0.0
 *
 * void mstr_n_set_str(mrstr_p restrict, mrstr_cstr restrict, mrstr_size)
 * Sets the destination data with the source up to the specified length
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include "intern.h"
#include <string.h>

void mrstr_n_set_str(mrstr_p restrict dst, mrstr_cstr restrict src, mrstr_size len)
{
    if (!len || !src)
        return;

    mrstr_size src_len = strlen(src);
    if (!src_len)
        return;

    if (len > src_len)
        len = src_len;

    MRSTR_DATA(dst) = __mrstr_das_alloc(len + 1);

    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_n_set_str", len + 1, );

    memcpy(MRSTR_DATA(dst), src, len);
    MRSTR_DATA(dst)[len] = '\0';

    MRSTR_LEN(dst) = len;
}
