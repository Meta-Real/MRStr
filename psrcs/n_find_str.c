/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_idx mrstr_find_str(mrstr_pc, mrstr_size, mrstr_cstr)
 * Returns the index of the substring within the string up to the length (MRSTR_NF if it does not exist)
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_idx mrstr_n_find_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr)
{
    mrstr_size slen;
    if (!substr || !(slen = strlen(substr)))
        return 0;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (slen > len)
        return MRSTR_NF;

    if (len == slen)
        return memcmp(MRSTR_DATA(str), substr, len) ? MRSTR_NF : 0;

    mrstr_size i, l;
    for (i = 0; i <= len - slen; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            l = len - i - 1;
            if (l > slen)
                l = slen;

            if (!memcmp(MRSTR_DATA(str) + i + 1, substr + 1, l))
                return i;
        }

    return MRSTR_NF;
}
