/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isfloat(mrstr_pc)
 * Checks whether the string is in the form of a float
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isfloat(mrstr_pc str)
{
    mrstr_size i;
    mrstr_bool point = MRSTR_FALSE;

    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    if (*MRSTR_DATA(str) == '-' || *MRSTR_DATA(str) == '+')
    {
        if (MRSTR_LEN(str) == 1)
            return MRSTR_FALSE;

        if (MRSTR_DATA(str)[1] == '.')
        {
            if (MRSTR_LEN(str) == 2)
                return MRSTR_FALSE;

            point = MRSTR_TRUE;
            i = 2;
        }
        else
            i = 1;
    }
    else
        i = 0;

    for (; i < MRSTR_LEN(str); i++)
    {
        if (MRSTR_DATA(str)[i] == '.')
        {
            if (point == MRSTR_TRUE)
                return MRSTR_FALSE;

            point = MRSTR_TRUE;
            continue;
        }

        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '9')
            return MRSTR_FALSE;
    }

    return MRSTR_TRUE;
}
