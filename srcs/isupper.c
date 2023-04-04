/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isupper(mrstr_pc)
 * Checks that the string not consists of lower characters
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isupper(mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] >= 'a' && MRSTR_DATA(str)[i] <= 'z')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
