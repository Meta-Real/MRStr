/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_cmpr mrstr_cmp(mrstr_pc, mrstr_pc)
 * Compares the first string and the second string and returns their signed difference
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_cmpr mrstr_cmp(mrstr_pc str1, mrstr_pc str2)
{
    mrstr_size i;

    if (str1 == str2)
        return 0;

    if (MRSTR_LEN(str1) == MRSTR_LEN(str2))
    {
        for (i = 0; i < MRSTR_LEN(str1); i++)
            if (MRSTR_DATA(str1)[i] != MRSTR_DATA(str2)[i])
                return MRSTR_DATA(str2)[i] - MRSTR_DATA(str1)[i];

        return 0;
    }

    if (MRSTR_LEN(str1) < MRSTR_LEN(str2))
    {
        for (i = 0; i <= MRSTR_LEN(str1); i++)
            if (MRSTR_DATA(str1)[i] != MRSTR_DATA(str2)[i])
                return MRSTR_DATA(str2)[i] - MRSTR_DATA(str1)[i];

        return MRSTR_DATA(str2)[i];
    }

    for (i = 0; i <= MRSTR_LEN(str2); i++)
        if (MRSTR_DATA(str1)[i] != MRSTR_DATA(str2)[i])
            return MRSTR_DATA(str2)[i] - MRSTR_DATA(str1)[i];

    return -MRSTR_DATA(str1)[i];
}
