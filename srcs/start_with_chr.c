/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_start_with_chr(mrstr_pc, mrstr_chr)
 * Checks that the string starts with the character
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_start_with_chr(mrstr_pc str, mrstr_chr chr)
{
    if (!MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (*MRSTR_DATA(str) == chr)
        return MRSTR_TRUE;
    return MRSTR_FALSE;
}
