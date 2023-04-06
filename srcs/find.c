/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_idx mrstr_find(mrstr_pc, mrstr_pc)
 * Returns the index of the substring within the string (-1 if it does not exist)
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_idx mrstr_find(mrstr_pc str, mrstr_pc substr)
{
    if (!MRSTR_LEN(substr) || str == substr)
        return 0;

    if (MRSTR_LEN(substr) > MRSTR_LEN(str))
        return -1;

    if (MRSTR_LEN(str) == MRSTR_LEN(substr))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), MRSTR_LEN(str)) ? -1 : 0;

    mrstr_size i, l;
    for (i = 0; i <= MRSTR_LEN(str) - MRSTR_LEN(substr); i++)
        if (MRSTR_DATA(str)[i] == *MRSTR_DATA(substr))
        {
            l = MRSTR_LEN(str) - i;
            if (l > MRSTR_LEN(substr))
                l = MRSTR_LEN(substr);

            if (!memcmp(MRSTR_DATA(str) + i + 1, MRSTR_DATA(substr) + 1, l - 1))
                return i;
        }

    return -1;
}
