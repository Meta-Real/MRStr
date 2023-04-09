/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_idx mrstr_n_find(mrstr_pc, mrstr_size, mrstr_pc)
 * Returns the index of the substring within the string up to the length (MRSTR_NF if it does not exist)
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_idx mrstr_n_find(mrstr_pc str, mrstr_size len, mrstr_pc substr)
{
    if (!MRSTR_LEN(substr) || str == substr)
        return 0;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (MRSTR_LEN(substr) > len)
        return MRSTR_NF;

    if (len == MRSTR_LEN(substr))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), len) ? MRSTR_NF : 0;

    mrstr_size i, l;
    for (i = 0; i <= len - MRSTR_LEN(substr); i++)
        if (MRSTR_DATA(str)[i] == *MRSTR_DATA(substr))
        {
            l = len - i;
            if (l > MRSTR_LEN(substr))
                l = MRSTR_LEN(substr);

            if (!memcmp(MRSTR_DATA(str) + i + 1, MRSTR_DATA(substr) + 1, l - 1))
                return i;
        }

    return MRSTR_NF;
}
