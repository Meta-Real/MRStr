/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_end_with_chr(mrstr_pc, mrstr_chr)
 * Checks whether the string ends with the character
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_end_with_chr(mrstr_pc str, mrstr_chr chr)
{
    if (!MRSTR_LEN(str))
        return MRSTR_FALSE;

    return MRSTR_DATA(str)[MRSTR_LEN(str) - 1] == chr ? MRSTR_TRUE : MRSTR_FALSE;
}
