/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_set_str(mrstr_p restrict, mrstr_cstr restrict)
 * Sets the destination data with the source
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_set_str(mrstr_p restrict dst, mrstr_cstr restrict src)
{
    if (!src)
        return;

    mrstr_size len = strlen(src);

    if (!len)
        return;

    MRSTR_DATA(dst) = __mrstr_das_alloc(len + 1);

    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_set_str", len + 1, );

    memcpy(MRSTR_DATA(dst), src, len + 1);
    MRSTR_LEN(dst) = len;
}
