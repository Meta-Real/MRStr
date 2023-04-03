/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_contains_chr(mrstr_pc, mrstr_chr)
 * Checks the existence of character within the string
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_contains_chr(mrstr_pc str, mrstr_chr chr)
{
    if (!MRSTR_LEN(str))
        return MRSTR_FALSE;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] == chr)
            return MRSTR_TRUE;

    return MRSTR_FALSE;
}
