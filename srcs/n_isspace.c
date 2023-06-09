/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_isspace(mrstr_pc)
 * Checks whether the string consists of only spaces (' ', '\f', '\n', '\r', '\t', '\v') up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_isspace(mrstr_pc str, mrstr_size len)
{
    mrstr_size i;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_TRUE;

    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] != ' ' && MRSTR_DATA(str)[i] != '\f' &&
            MRSTR_DATA(str)[i] != '\n' && MRSTR_DATA(str)[i] != '\r' &&
            MRSTR_DATA(str)[i] != '\t' && MRSTR_DATA(str)[i] != '\v')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
