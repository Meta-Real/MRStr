/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_d_all(mrstr_pc, mrstr_bool (*)(mrstr_chr, mrstr_chr_data_t))
 * Checks whether all the characters of the string are satisfying the given condition (with data)
 * The condition must be checked by the function
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
 *  (func) must return MRSTR_TRUE if the condition is satisfied and MRSTR_FALSE otherwise (non-fatal error)
/*/

#include <mrstr.h>

mrstr_bool mrstr_d_all(mrstr_pc str, mrstr_bool (*func)(mrstr_chr chr, mrstr_chr_data_t data))
{
    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    mrstr_chr_data_t data;
    data.str = str;
    data.idx = 0;
    data.prev = '\0';
    data.next = MRSTR_DATA(str)[1];

    for (; data.idx < MRSTR_LEN(str); data.idx++)
    {
        if (func(MRSTR_DATA(str)[data.idx], data) == MRSTR_FALSE)
            return MRSTR_FALSE;

        data.prev = MRSTR_DATA(str)[data.idx];
        data.next = MRSTR_DATA(str)[data.idx + 2];
    }

    return MRSTR_TRUE;
}
