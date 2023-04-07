/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_contains_str(mrstr_pc restrict, mrstr_size, mrstr_cstr restrict)
 * Checks the existence of substring within the string up to the specified length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_n_contains_str(mrstr_pc restrict str, mrstr_size len, mrstr_cstr restrict substr)
{
    if (!substr)
        return MRSTR_TRUE;

    size_t substr_len = strlen(substr);

    if (!substr_len)
        return MRSTR_TRUE;

    if (len > substr_len)
        len = substr_len;

    if (len > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (MRSTR_LEN(str) == len)
        return memcmp(MRSTR_DATA(str), substr, len) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i, l;
    for (i = 0; i <= MRSTR_LEN(str) - len; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            l = MRSTR_LEN(str) - i;
            if (l > len)
                l = len;

            if (!memcmp(MRSTR_DATA(str) + i + 1, substr + 1, l - 1))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
