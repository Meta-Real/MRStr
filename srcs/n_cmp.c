/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_cmpr mrstr_n_cmp(mrstr_pc, mrstr_pc, mrstr_size)
 * Compares the first string and the second string up to the length and returns their signed difference
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_cmpr mrstr_n_cmp(mrstr_pc str1, mrstr_pc str2, mrstr_size len)
{
    mrstr_size i;

    if (str1 == str2)
        return 0;

    if (MRSTR_LEN(str1) == MRSTR_LEN(str2))
    {
        if (len > MRSTR_LEN(str1))
            len = MRSTR_LEN(str1);

        for (i = 0; i < len; i++)
            if (MRSTR_DATA(str1)[i] != MRSTR_DATA(str2)[i])
                return MRSTR_DATA(str2)[i] - MRSTR_DATA(str1)[i];

        return 0;
    }

    if (MRSTR_LEN(str1) < MRSTR_LEN(str2))
    {
        if (len > MRSTR_LEN(str1))
            len = MRSTR_LEN(str1);

        for (i = 0; i <= len; i++)
            if (MRSTR_DATA(str1)[i] != MRSTR_DATA(str2)[i])
                return MRSTR_DATA(str2)[i] - MRSTR_DATA(str1)[i];

        return MRSTR_DATA(str2)[i];
    }

    if (len > MRSTR_LEN(str2))
        len = MRSTR_LEN(str2);

    for (i = 0; i <= len; i++)
        if (MRSTR_DATA(str1)[i] != MRSTR_DATA(str2)[i])
            return MRSTR_DATA(str2)[i] - MRSTR_DATA(str1)[i];

    return -MRSTR_DATA(str1)[i];
}
