/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_isalpha(mrstr_pc, mrstr_size)
 * Checks whether the string consists of only alphabets up to the specified length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_isalpha(mrstr_pc str, mrstr_size len)
{
    if (!MRSTR_LEN(str) || !len)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_size i;
    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] < 'A' || MRSTR_DATA(str)[i] > 'Z' &&
            (MRSTR_DATA(str)[i] < 'a' || MRSTR_DATA(str)[i] > 'z'))
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
