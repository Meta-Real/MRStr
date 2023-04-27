/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_str mrstr_sn_get(mrstr_pc, mrstr_size)
 * Returns the source string in the form of standard c string up to the length
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

mrstr_str mrstr_sn_get(mrstr_pc src, mrstr_size len)
{
    mrstr_str dst;

    if (len > MRSTR_LEN(src))
        len = MRSTR_LEN(src);

    if (!len)
        return NULL;

    dst = __mrstr_das_alloc(len + 1);
    if (!dst)
        mrstr_dbg_aloc_err("mrstr_sn_get", len + 1, NULL);

    memcpy(dst, MRSTR_DATA(src), len);
    dst[len] = '\0';
    return dst;
}
