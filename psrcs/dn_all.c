/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_dn_all(mrstr_pc, mrstr_size, mrstr_bool (*)(mrstr_chr, mrstr_chr_data_pc))
 * Checks whether all the characters of the string are satisfying the given condition up to the length (with data)
 * The condition must be checked by the function
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
 *  (func) must return MRSTR_TRUE if the condition is satisfied and MRSTR_FALSE otherwise (non-fatal error)
/*/

#include <mrstr.h>

mrstr_bool mrstr_dn_all(mrstr_pc str, mrstr_size len,
                        mrstr_bool (*func)(mrstr_chr chr, mrstr_chr_data_pc data))
{
    if (!MRSTR_LEN(str) || !len)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_chr_data_t data;
    data.str = str;
    data.idx = 0;
    data.prev = '\0';
    data.next = MRSTR_DATA(str)[1];

    for (; data.idx < len; data.idx++)
    {
        if (func(MRSTR_DATA(str)[data.idx], &data) == MRSTR_FALSE)
            return MRSTR_FALSE;

        data.prev = MRSTR_DATA(str)[data.idx];
        data.next = MRSTR_DATA(str)[data.idx + 2];
    }

    return MRSTR_TRUE;
}
