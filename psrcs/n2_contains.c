/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n2_contains(mrstr_pc, mrstr_pc, mrstr_size)
 * Checks the existence of the substring up to the length within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_n2_contains(mrstr_pc str, mrstr_pc substr, mrstr_size len)
{
    if (!MRSTR_LEN(substr) || !len || str == substr)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(substr))
        len = MRSTR_LEN(substr);

    if (len > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (MRSTR_LEN(str) == len)
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), len) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i, l;
    for (i = 0; i <= MRSTR_LEN(str) - len; i++)
        if (MRSTR_DATA(str)[i] == *MRSTR_DATA(substr))
        {
            l = MRSTR_LEN(str) - i - 1;
            if (l > len)
                l = len;

            if (!memcmp(MRSTR_DATA(str) + i + 1, MRSTR_DATA(substr) + 1, l))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
