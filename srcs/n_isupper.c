/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_isupper(mrstr_pc)
 * Checks whether the string does not contain the lowercase alphabet characters up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_isupper(mrstr_pc str, mrstr_size len)
{
    mrstr_size i;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_TRUE;

    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] >= 'a' && MRSTR_DATA(str)[i] <= 'z')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
