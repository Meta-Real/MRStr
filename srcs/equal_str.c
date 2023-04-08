/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_equal_str(mrstr_pc, mrstr_cstr)
 * Checks whether the first string equals the second string
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_equal_str(mrstr_pc str1, mrstr_cstr str2)
{
    if (!str2)
        return MRSTR_LEN(str1) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size slen = strlen(str2);

    if (MRSTR_LEN(str1) != slen)
        return MRSTR_FALSE;

    if (!slen)
        return MRSTR_TRUE;

    return memcmp(MRSTR_DATA(str1), str2, slen) ? MRSTR_FALSE : MRSTR_TRUE;
}
