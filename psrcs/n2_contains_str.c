/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n2_contains_str(mrstr_pc, mrstr_cstr, mrstr_size)
 * Checks the existence of the substring up to the length within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_n2_contains_str(mrstr_pc str, mrstr_cstr substr, mrstr_size len)
{
    mrstr_size slen;
    if (!substr || !(slen = strlen(substr)) || !len)
        return MRSTR_TRUE;

    if (len > slen)
        len = slen;

    if (MRSTR_LEN(str) < len)
        return MRSTR_FALSE;

    if (MRSTR_LEN(str) == len)
        return memcmp(MRSTR_DATA(str), substr, len) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i, l;
    for (i = 0; i <= MRSTR_LEN(str) - len; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            l = MRSTR_LEN(str) - i - 1;
            if (l > len)
                l = len;

            if (!memcmp(MRSTR_DATA(str) + i + 1, substr + 1, l))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
