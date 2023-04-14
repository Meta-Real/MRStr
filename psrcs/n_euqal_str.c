/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_equal_str(mrstr_pc, mrstr_cstr, mrstr_size)
 * Checks whether the first string equals the second string up to the length
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_n_equal_str(mrstr_pc str1, mrstr_cstr str2, mrstr_size len)
{
    if (!len)
        return MRSTR_TRUE;

    if (!str2)
        return MRSTR_LEN(str1) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size slen = strlen(str2);
    if (MRSTR_LEN(str1) == slen)
    {
        if (!slen)
            return MRSTR_TRUE;

        if (len > slen)
            len = slen;

        return memcmp(MRSTR_DATA(str1), str2, len) ? MRSTR_FALSE : MRSTR_TRUE;
    }

    if (MRSTR_LEN(str1) < len || slen < len)
        return MRSTR_FALSE;

    return memcmp(MRSTR_DATA(str1), str2, len) ? MRSTR_FALSE : MRSTR_TRUE;
}
