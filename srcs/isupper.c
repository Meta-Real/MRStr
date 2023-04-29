/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isupper(mrstr_pc)
 * Checks whether the string does not contain the lowercase alphabet characters
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isupper(mrstr_pc str)
{
    mrstr_size i;

    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] >= 'a' && MRSTR_DATA(str)[i] <= 'z')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
