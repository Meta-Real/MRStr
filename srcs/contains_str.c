/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_contains_str(mrstr_pc, mrstr_cstr)
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

    size_t size = strlen(substr);

    if (!size)
        return MRSTR_TRUE;

    if (size > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (MRSTR_LEN(str) == size)
    {
        mrstr_size i;
        for (i = 0; i < MRSTR_LEN(str); i++)
            if (MRSTR_DATA(str)[i] != substr[i])
                return MRSTR_FALSE;

        return MRSTR_TRUE;
    }

    mrstr_size i;
    for (i = 0; i <= MRSTR_LEN(str) - size; i++)
        if (MRSTR_DATA(str)[i] == *substr)
        {
            mrstr_size j, k;
            for (j = ++i, k = 1; j < MRSTR_LEN(str) && k < size; j++, k++)
                if (MRSTR_DATA(str)[j] != substr[k])
                    break;

            if (k == size)
                return MRSTR_TRUE;
        }

    return MRSTR_FALSE;
}
