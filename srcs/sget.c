/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_str mrstr_sget(mrstr_pc)
 * Returns the source string in the form of standard c string
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

mrstr_str mrstr_sget(mrstr_pc src)
{
    if (!MRSTR_LEN(src))
        return NULL;

    mrstr_str dst = __mrstr_das_alloc(MRSTR_LEN(src) + 1);
    if (!dst)
        mrstr_dbg_aloc_err("mrstr_sget", MRSTR_LEN(src) + 1, NULL);

    memcpy(dst, MRSTR_DATA(src), MRSTR_LEN(src) + 1);
    return dst;
}
