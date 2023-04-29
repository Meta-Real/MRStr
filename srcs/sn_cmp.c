/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_cmpr mrstr_sn_cmp(mrstr_pc, mrstr_cstr, mrstr_size)
 * Compares the first string and the second string up to the length and returns their signed difference
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_cmpr mrstr_sn_cmp(mrstr_pc str1, mrstr_cstr str2, mrstr_size len)
{
    mrstr_size slen, i;

    if (!(str2 && (slen = strlen(str2))))
        return MRSTR_LEN(str1) ? *MRSTR_DATA(str1) : 0;

    if (MRSTR_LEN(str1) == slen)
    {
        if (len > slen)
            len = slen;

        for (i = 0; i < len; i++)
            if (MRSTR_DATA(str1)[i] != str2[i])
                return str2[i] - MRSTR_DATA(str1)[i];

        return 0;
    }

    if (MRSTR_LEN(str1) < slen)
    {
        if (len > MRSTR_LEN(str1))
            len = MRSTR_LEN(str1);

        for (i = 0; i <= len; i++)
            if (MRSTR_DATA(str1)[i] != str2[i])
                return str2[i] - MRSTR_DATA(str1)[i];

        return str2[i];
    }

    if (len > slen)
        len = slen;

    for (i = 0; i <= len; i++)
        if (MRSTR_DATA(str1)[i] != str2[i])
            return str2[i] - MRSTR_DATA(str1)[i];

    return -MRSTR_DATA(str1)[i];
}
