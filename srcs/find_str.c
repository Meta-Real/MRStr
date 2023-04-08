/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_idx mrstr_find_str(mrstr_pc, mrstr_cstr)
 * Returns the index of the substring within the string (MRSTR_NF if it does not exist)
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_idx mrstr_find_str(mrstr_pc str, mrstr_cstr substr)
{
    mrstr_size slen;
    if (!substr || !(slen = strlen(substr)))
        return 0;

    if (slen > MRSTR_LEN(str))
        return MRSTR_NF;

    if (MRSTR_LEN(str) == slen)
        return memcmp(MRSTR_DATA(str), substr, slen) ? MRSTR_NF : 0;

    mrstr_size i, l;
    for (i = 0; i <= MRSTR_LEN(str) - slen; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            l = MRSTR_LEN(str) - i;
            if (l > slen)
                l = slen;

            if (!memcmp(MRSTR_DATA(str) + i + 1, substr + 1, l - 1))
                return i;
        }

    return MRSTR_NF;
}