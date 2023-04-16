/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_isblank(mrstr_pc)
 * Checks whether the string consists of only blanks (' ', '\t') up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_isblank(mrstr_pc str, mrstr_size len)
{
    if (!(MRSTR_LEN(str) && len))
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_size i;
    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] != ' ' && MRSTR_DATA(str)[i] != '\t')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
