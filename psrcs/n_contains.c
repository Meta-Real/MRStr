/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_contains(mrstr_pc, mrstr_size, mrstr_pc)
 * Checks the existence of substring within the string up to the specified length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_n_contains(mrstr_pc str, mrstr_size len, mrstr_pc substr)
{
    if (!MRSTR_LEN(substr) || str == substr)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (MRSTR_LEN(substr) > len)
        return MRSTR_FALSE;

    if (len == MRSTR_LEN(substr))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), len) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i, l;
    for (i = 0; i <= len - MRSTR_LEN(substr); i++)
        if (MRSTR_DATA(str)[i] == *MRSTR_DATA(substr))
        {
            l = len - i;
            if (l > MRSTR_LEN(substr))
                l = MRSTR_LEN(substr);

            if (!memcmp(MRSTR_DATA(str) + i + 1, MRSTR_DATA(substr) + 1, l - 1))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
