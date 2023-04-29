/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isblank(mrstr_pc)
 * Checks whether the string consists of only blanks (' ', '\t')
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isblank(mrstr_pc str)
{
    mrstr_size i;

    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] != ' ' && MRSTR_DATA(str)[i] != '\t')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
