/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_sn_set(mrstr_p, mrstr_cstr, mrstr_size)
 * Sets the destination string with the source string up to the length
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_sn_set(mrstr_p dst, mrstr_cstr src, mrstr_size len)
{
    mrstr_size slen;
    if (!(src && (slen = strlen(src)) && len))
        return;

    if (len > slen)
        len = slen;

    MRSTR_DATA(dst) = __mrstr_alloc(len + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_sn_set", len + 1, );

    memcpy(MRSTR_DATA(dst), src, len);
    MRSTR_DATA(dst)[len] = '\0';
    MRSTR_LEN(dst) = len;
}
