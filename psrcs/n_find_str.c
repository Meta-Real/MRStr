/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_idx mrstr_find_str(mrstr_pc, mrstr_size, mrstr_cstr)
 * Returns the index of the substring within the string up to the specified length (MRSTR_NF if it does not exist)
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_idx mrstr_n_find_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr)
{
    if (!substr)
        return 0;

    size_t substr_len = strlen(substr);

    if (!substr_len)
        return 0;

    if (len > substr_len)
        len = substr_len;

    if (len > MRSTR_LEN(str))
        return MRSTR_NF;

    if (MRSTR_LEN(str) == len)
        return memcmp(MRSTR_DATA(str), substr, len) ? MRSTR_NF : 0;

    mrstr_size i, l;
    for (i = 0; i <= MRSTR_LEN(str) - len; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            l = MRSTR_LEN(str) - i;
            if (l > len)
                l = len;

            if (!memcmp(MRSTR_DATA(str) + i + 1, substr + 1, l - 1))
                return i;
        }

    return MRSTR_NF;
}
