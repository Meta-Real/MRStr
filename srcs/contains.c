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
        mrstr_size i;
        for (i = 0; i < MRSTR_LEN(str); i++)
            if (MRSTR_DATA(str)[i] != MRSTR_DATA(substr)[i])
                return MRSTR_FALSE;

        return MRSTR_TRUE;
    }

    mrstr_size i;
    for (i = 0; i <= MRSTR_LEN(str) - MRSTR_LEN(substr); i++)
        if (MRSTR_DATA(str)[i] == *MRSTR_DATA(substr))
        {
            mrstr_size j, k;
            for (j = ++i, k = 1; j < MRSTR_LEN(str) && k < MRSTR_LEN(substr); j++, k++)
                if (MRSTR_DATA(str)[j] != MRSTR_DATA(substr)[k])
                    break;

            if (k == MRSTR_LEN(substr))
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
