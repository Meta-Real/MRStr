/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_equal_str(mrstr_pc, mrstr_cstr, mrstr_size)
 * Compares str1 and str2 up to the specified length
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
    {
        if (!MRSTR_LEN(str1))
            return MRSTR_TRUE;
        return MRSTR_FALSE;
    }

    mrstr_size str2_len = strlen(str2);

    if (MRSTR_LEN(str1) == str2_len)
    {
        if (!str2_len)
            return MRSTR_TRUE;

        if (len > str2_len)
            len = str2_len;

        if (!memcmp(MRSTR_DATA(str1), str2, len))
            return MRSTR_TRUE;
        return MRSTR_FALSE;
    }

    if (MRSTR_LEN(str1) < len || str2_len < len)
        return MRSTR_FALSE;

    if (!memcmp(MRSTR_DATA(str1), str2, len))
        return MRSTR_TRUE;
    return MRSTR_FALSE;
}
