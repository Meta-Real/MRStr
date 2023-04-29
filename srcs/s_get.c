/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_str mrstr_s_get(mrstr_pc)
 * Returns the source string in the form of standard c string
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

mrstr_str mrstr_s_get(mrstr_pc src)
{
    mrstr_str dst;

    if (!MRSTR_LEN(src))
        return NULL;

    dst = __mrstr_alloc(MRSTR_LEN(src) + 1);
    if (!dst)
        mrstr_dbg_aloc_err("mrstr_s_get", MRSTR_LEN(src) + 1, NULL);

    memcpy(dst, MRSTR_DATA(src), MRSTR_LEN(src) + 1);
    return dst;
}
