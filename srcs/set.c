/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_set(mrstr_p, mrstr_pc)
 * Sets the destination string with the source string
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) pointer equals (src) pointer) (memory leak)
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_set(mrstr_p dst, mrstr_pc src)
{
#ifndef __MRSTR_ADV__
    if (dst == src)
        return;
#endif

    if (!MRSTR_LEN(src))
        return;

    MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_LEN(src) + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_set", MRSTR_LEN(src) + 1, );

    memcpy(MRSTR_DATA(dst), MRSTR_DATA(src), MRSTR_LEN(src) + 1);
    MRSTR_LEN(dst) = MRSTR_LEN(src);
}
