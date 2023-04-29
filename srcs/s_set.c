/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_s_set(mrstr_p, mrstr_cstr)
 * Sets the destination string with the source string
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_s_set(mrstr_p dst, mrstr_cstr src)
{
    mrstr_size slen;
    if (!(src && (slen = strlen(src))))
        return;

    MRSTR_DATA(dst) = __mrstr_alloc(slen + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_s_set", slen + 1, );

    memcpy(MRSTR_DATA(dst), src, slen + 1);
    MRSTR_LEN(dst) = slen;
}
