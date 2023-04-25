/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_str mrstr_n_sget(mrstr_pc, mrstr_size)
 * Returns the source string in the form of standard c string up to the length
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

mrstr_str mrstr_n_sget(mrstr_pc src, mrstr_size len)
{
    if (len > MRSTR_LEN(src))
        len = MRSTR_LEN(src);

    if (!len)
        return NULL;

    mrstr_str dst = __mrstr_das_alloc(len + 1);
    if (!dst)
        mrstr_dbg_aloc_err("mrstr_n_sget", len + 1, NULL);

    memcpy(dst, MRSTR_DATA(src), len);
    dst[len] = '\0';
    return dst;
}
