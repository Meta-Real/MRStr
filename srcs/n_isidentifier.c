/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_isidentifier(mrstr_pc, mrstr_size)
 * Checks whether the string is in the form of an identifier up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_isidentifier(mrstr_pc str, mrstr_size len)
{
    mrstr_size i;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_TRUE;

    if (*MRSTR_DATA(str) < 'A' || *MRSTR_DATA(str) > 'Z' &&
        *MRSTR_DATA(str) != '_' &&
        (*MRSTR_DATA(str) < 'a' || *MRSTR_DATA(str) > 'z'))
        return MRSTR_FALSE;

    for (i = 1; i < len; i++)
        if (MRSTR_DATA(str)[i] < 'A' && (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '9') ||
            MRSTR_DATA(str)[i] > 'Z' && *MRSTR_DATA(str) != '_' &&
            (*MRSTR_DATA(str) < 'a' || *MRSTR_DATA(str) > 'z'))
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
