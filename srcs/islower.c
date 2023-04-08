/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_islower(mrstr_pc)
 * Checks whether the string does not contain the uppercase alphabet characters
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_islower(mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] >= 'A' && MRSTR_DATA(str)[i] <= 'Z')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
