/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_c_equal(mrstr_pc, mrstr_chr)
 * Checks whether the string equals the character
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_c_equal(mrstr_pc str, mrstr_chr chr)
{
    if (MRSTR_LEN(str) != 1)
        return MRSTR_FALSE;

    return *MRSTR_DATA(str) == chr ? MRSTR_TRUE : MRSTR_FALSE;
}
