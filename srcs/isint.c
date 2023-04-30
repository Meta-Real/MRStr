/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isint(mrstr_pc)
 * Checks whether the string is in the form of an integer
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isint(mrstr_pc str)
{
    mrstr_size i;

    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    if (*MRSTR_DATA(str) == '-' || *MRSTR_DATA(str) == '+')
    {
        if (MRSTR_LEN(str) == 1)
            return MRSTR_FALSE;

        i = 1;
    }
    else
        i = 0;

    for (; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '9')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
