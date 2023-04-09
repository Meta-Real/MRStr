/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_contains_chr(mrstr_pc, mrstr_size, mrstr_chr)
 * Checks the existence of the character within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_contains_chr(mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (!MRSTR_LEN(str) || !len)
        return MRSTR_FALSE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_size i;
    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] == chr)
            return MRSTR_TRUE;

    return MRSTR_FALSE;
}
