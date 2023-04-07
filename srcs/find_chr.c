/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_idx mrstr_find_chr(mrstr_pc, mrstr_chr)
 * Returns the index of the character within the string (MRSTR_NF if it does not exist)
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_idx mrstr_find_chr(mrstr_pc str, mrstr_chr chr)
{
    if (!MRSTR_LEN(str))
        return MRSTR_NF;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] == chr)
            return i;

    return MRSTR_NF;
}
