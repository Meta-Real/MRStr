/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isspace(mrstr_pc)
 * Checks whether the string consists of only spaces (' ', '\f', '\n', '\r', '\t', '\v')
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isspace(mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] != ' ' && MRSTR_DATA(str)[i] != '\f' &&
            MRSTR_DATA(str)[i] != '\n' && MRSTR_DATA(str)[i] != '\r' &&
            MRSTR_DATA(str)[i] != '\t' && MRSTR_DATA(str)[i] != '\v')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
