/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_contains_str(mrstr_pc, mrstr_cstr)
 * Checks the existence of substring within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_contains_str(mrstr_pc str, mrstr_cstr substr)
{
    if (!substr)
        return MRSTR_TRUE;

    size_t len = strlen(substr);

    if (!len)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (MRSTR_LEN(str) == len)
    {
        mrstr_size i;
        for (i = 0; i < MRSTR_LEN(str); i++)
            if (MRSTR_DATA(str)[i] != substr[i])
                return MRSTR_FALSE;

        return MRSTR_TRUE;
    }

    mrstr_size i;
    for (i = 0; i <= MRSTR_LEN(str) - len; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            mrstr_size j, k;
            for (j = ++i, k = 1; j < MRSTR_LEN(str) && k < len; j++, k++)
                if (MRSTR_DATA(str)[j] != substr[k])
                    break;

            if (k == len)
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
