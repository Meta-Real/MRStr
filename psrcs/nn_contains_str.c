/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_nn_contains_str(mrstr_pc, mrstr_size, mrstr_cstr, mrstr_size)
 * Checks the existence of the substring up to the length within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_nn_contains_str(mrstr_pc str, mrstr_size len1, mrstr_cstr substr, mrstr_size len2)
{
    mrstr_size slen;
    if (!substr || !(slen = strlen(substr)) || !len2)
        return MRSTR_TRUE;

    if (len1 > MRSTR_LEN(str))
        len1 = MRSTR_LEN(str);

    if (len2 > slen)
        len2 = slen;

    if (len1 < len2)
        return MRSTR_FALSE;

    if (len1 == len2)
        return memcmp(MRSTR_DATA(str), substr, len1) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i, l;
    for (i = 0; i <= len1 - len2; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            l = len1 - i - 1;
            if (l > len2)
                l = len2;

            if (!memcmp(MRSTR_DATA(str) + i + 1, substr + 1, l))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
