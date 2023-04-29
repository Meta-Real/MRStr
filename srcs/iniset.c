/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_iniset(mrstr_p, mrstr_pc)
 * Initializes sets the destination string with the source string
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) pointer equals (src) pointer) (memory leak)
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_iniset(mrstr_p dst, mrstr_pc src)
{
    if (dst == src)
        return;

    if (!MRSTR_LEN(src))
    {
        MRSTR_DATA(dst) = NULL;
        MRSTR_LEN(dst) = 0;
        MRSTR_OFFSET(dst) = 0;
        return;
    }

    MRSTR_DATA(dst) = __mrstr_alloc(MRSTR_LEN(src) + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_iniset", MRSTR_LEN(src) + 1, );

    memcpy(MRSTR_DATA(dst), MRSTR_DATA(src), MRSTR_LEN(src) + 1);
    MRSTR_LEN(dst) = MRSTR_LEN(src);
    MRSTR_OFFSET(dst) = 0;
}
