/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_reset_offset(mrstr_p)
 * Resets the offset back to zero and removes the data before it
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_reset_offset(mrstr_p str)
{
    mrstr_str tdata;

    if (!MRSTR_OFFSET(str))
        return;

    MRSTR_DATA(str) -= MRSTR_OFFSET(str);

    if (!MRSTR_LEN(str))
    {
        __mrstr_free(MRSTR_DATA(str));
        MRSTR_DATA(str) = NULL;
        MRSTR_OFFSET(str) = 0;
        return;
    }

    memmove(MRSTR_DATA(str), MRSTR_DATA(str) + MRSTR_OFFSET(str), MRSTR_LEN(str) + 1);
    MRSTR_OFFSET(str) = 0;

    tdata = __mrstr_realloc(MRSTR_DATA(str), MRSTR_LEN(str) + 1);
    if (!tdata)
        mrstr_dbg_aloc_err("mrstr_reset_offset", MRSTR_LEN(str) + 1, );

    MRSTR_DATA(str) = tdata;
}
