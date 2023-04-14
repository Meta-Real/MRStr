/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_contains_str(mrstr_pc, mrstr_size, mrstr_cstr)
 * Checks the existence of the substring within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_n_contains_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr)
{
    mrstr_size slen;
    if (!(substr && (slen = strlen(substr))))
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (len < slen)
        return MRSTR_FALSE;

    if (len == slen)
        return memcmp(MRSTR_DATA(str), substr, len) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i, l;
    for (i = 0; i <= len - slen; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            l = len - i - 1;
            if (l > slen)
                l = slen;

            if (!memcmp(MRSTR_DATA(str) + i + 1, substr + 1, l))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
