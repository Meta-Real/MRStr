/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isdigit(mrstr_pc)
 * Checks that the string consists of only digits
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isdigit(mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '9')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
