/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isidentifier(mrstr_pc)
 * Checks whether the string is in the form of an identifier
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isidentifier(mrstr_pc str)
{
    mrstr_size i;

    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    if (*MRSTR_DATA(str) < 'A' || *MRSTR_DATA(str) > 'Z' &&
        *MRSTR_DATA(str) != '_' &&
        (*MRSTR_DATA(str) < 'a' || *MRSTR_DATA(str) > 'z'))
        return MRSTR_FALSE;

    for (i = 1; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] < 'A' && (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '9') ||
            MRSTR_DATA(str)[i] > 'Z' && *MRSTR_DATA(str) != '_' &&
            (*MRSTR_DATA(str) < 'a' || *MRSTR_DATA(str) > 'z'))
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
