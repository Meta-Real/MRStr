/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_isalnum(mrstr_pc, mrstr_size)
 * Checks whether the string consists of only alphabets and digits up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_isalnum(mrstr_pc str, mrstr_size len)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_TRUE;

    mrstr_size i;
    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '9' &&
            (MRSTR_DATA(str)[i] < 'A' || MRSTR_DATA(str)[i] > 'Z' &&
            (MRSTR_DATA(str)[i] < 'a' || MRSTR_DATA(str)[i] > 'z')))
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
