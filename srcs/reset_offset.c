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

void mrstr_reset_offset(mrstr_p str)
{
    if (!MRSTR_OFFSET(str))
        return;

    MRSTR_DATA(str) -= MRSTR_OFFSET(str);
    MRSTR_OFFSET(str) = 0;

    if (!MRSTR_LEN(str))
    {
        __mrstr_das_free(MRSTR_DATA(str));
        return;
    }

    mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(str), MRSTR_LEN(str) + 1);
    if (!t_data)
        mrstr_dbg_aloc_err("mrstr_reset_offset", MRSTR_LEN(str) + 1, );

    MRSTR_DATA(str) = t_data;
    MRSTR_DATA(str)[MRSTR_LEN(str)] = '\0';
}
