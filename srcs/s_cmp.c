/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_cmpr mrstr_s_cmp(mrstr_pc, mrstr_cstr)
 * Compares the first string and the second string and returns their signed difference
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_cmpr mrstr_s_cmp(mrstr_pc str1, mrstr_cstr str2)
{
    mrstr_size slen, i;

    if (!(str2 && (slen = strlen(str2))))
        return MRSTR_LEN(str1) ? *MRSTR_DATA(str1) : 0;

    if (MRSTR_LEN(str1) == slen)
    {
        for (i = 0; i < slen; i++)
            if (MRSTR_DATA(str1)[i] != str2[i])
                return str2[i] - MRSTR_DATA(str1)[i];

        return 0;
    }

    if (MRSTR_LEN(str1) < slen)
    {
        for (i = 0; i <= MRSTR_LEN(str1); i++)
            if (MRSTR_DATA(str1)[i] != str2[i])
                return str2[i] - MRSTR_DATA(str1)[i];

        return str2[i];
    }

    for (i = 0; i <= slen; i++)
        if (MRSTR_DATA(str1)[i] != str2[i])
            return str2[i] - MRSTR_DATA(str1)[i];

    return -MRSTR_DATA(str1)[i];
}
