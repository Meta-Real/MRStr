/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_isxdigit(mrstr_pc, mrstr_size)
 * Checks whether the string consists of only hexadecimal digits up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_isxdigit(mrstr_pc str, mrstr_size len)
{
    if (!(MRSTR_LEN(str) && len))
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_size i;
    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '9' &&
            (MRSTR_DATA(str)[i] < 'A' || MRSTR_DATA(str)[i] > 'F' &&
            (MRSTR_DATA(str)[i] < 'a' || MRSTR_DATA(str)[i] > 'f')))
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
