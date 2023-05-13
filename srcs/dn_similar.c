/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_dn_similar(mrstr_pc, mrstr_pc, mrstr_size, mrstr_bool (*)(mrstr_chr, mrstr_cdata_t, mrstr_chr, mrstr_cdata_t))
 * Checks whether all the characters of the strings are similar in the defined way up to the length (with data)
 * The similarity must be checked by the function
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
 *  (func) pointer must be valid
 *  (func) must return MRSTR_TRUE if characters are similar and MRSTR_FALSE otherwise (non-fatal error)
/*/

#include <mrstr.h>

mrstr_bool mrstr_dn_similar(mrstr_pc str1, mrstr_pc str2, mrstr_size len,
                            mrstr_bool (*func)(mrstr_chr chr1, mrstr_cdata_t data1, mrstr_chr chr2, mrstr_cdata_t data2))
{
    mrstr_cdata_t data1, data2;

    if (MRSTR_LEN(str1) != MRSTR_LEN(str2))
        return MRSTR_FALSE;

    if (len > MRSTR_LEN(str1))
        len = MRSTR_LEN(str1);

    if (!len)
        return MRSTR_TRUE;

    data1.str = str1;
    data1.idx = 0;
    data1.prev = '\0';
    data1.next = MRSTR_DATA(str1)[1];

    data2.str = str2;
    data2.idx = 0;
    data2.prev = '\0';
    data2.next = MRSTR_DATA(str2)[1];

    for (; data1.idx < len; data1.idx++, data2.idx++)
    {
        if (func(MRSTR_DATA(str1)[data1.idx], data1, MRSTR_DATA(str2)[data1.idx], data2) == MRSTR_FALSE)
            return MRSTR_FALSE;

        data1.prev = MRSTR_DATA(str1)[data1.idx];
        data1.next = MRSTR_DATA(str1)[data1.idx + 2];

        data2.prev = MRSTR_DATA(str2)[data1.idx];
        data2.next = MRSTR_DATA(str2)[data1.idx + 2];
    }

    return MRSTR_TRUE;
}
