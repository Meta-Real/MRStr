/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_contains(mrstr_pc, mrstr_pc)
 * Checks the existence of substring within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_contains(mrstr_pc str, mrstr_pc substr)
{
    if (str == substr)
        return MRSTR_TRUE;

    if (!MRSTR_LEN(substr))
        return MRSTR_TRUE;

    if (MRSTR_LEN(substr) > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (MRSTR_LEN(str) == MRSTR_LEN(substr))
    {
        if (!memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), MRSTR_LEN(str)))
            return MRSTR_TRUE;
        return MRSTR_FALSE;
    }

    mrstr_size i, l;
    for (i = 0; i <= MRSTR_LEN(str) - MRSTR_LEN(substr); i++)
        if (MRSTR_DATA(str)[i] == *MRSTR_DATA(substr))
        {
            l = MRSTR_LEN(str) - i;
            if (l > MRSTR_LEN(substr))
                l = MRSTR_LEN(substr);

            if (!memcmp(MRSTR_DATA(str) + i + 1, MRSTR_DATA(substr) + 1, l - 1))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
