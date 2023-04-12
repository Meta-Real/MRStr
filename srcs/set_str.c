/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_set_str(mrstr_p, mrstr_cstr)
 * Sets the destination string with the source string
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_set_str(mrstr_p dst, mrstr_cstr src)
{
#ifndef __MRSTR_ADV__
    if (!src)
        return;
#endif

    mrstr_size slen = strlen(src);
    if (!slen)
        return;

    MRSTR_DATA(dst) = __mrstr_das_alloc(slen + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_set_str", slen + 1, );

    memcpy(MRSTR_DATA(dst), src, slen + 1);
    MRSTR_LEN(dst) = slen;
}
