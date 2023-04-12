/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_contains_str(mrstr_pc, mrstr_cstr)
 * Checks the existence of the substring within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_contains_str(mrstr_pc str, mrstr_cstr substr)
{
#ifndef __MRSTR_ADV__
    if (!substr)
        return MRSTR_TRUE;
#endif

    mrstr_size slen = strlen(substr);
    if (!slen)
        return MRSTR_TRUE;

    if (slen > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (MRSTR_LEN(str) == slen)
        return memcmp(MRSTR_DATA(str), substr, slen) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i, l;
    for (i = 0; i <= MRSTR_LEN(str) - slen; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            l = MRSTR_LEN(str) - i;
            if (l > slen)
                l = slen;

            if (!memcmp(MRSTR_DATA(str) + i + 1, substr + 1, l - 1))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
