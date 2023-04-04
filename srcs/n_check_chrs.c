/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_check_chrs(mrstr_pc, mrstr_size, mrstr_bool (*)(mrstr_chr))
 * Checks that all the string characters up to the specified length match with the condition
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
 *  (func) must return MRSTR_TRUE if the condition satisfied and MRSTR_FALSE otherwise
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_check_chrs(mrstr_pc str, mrstr_size len, mrstr_bool (*func)(mrstr_chr chr))
{
    if (!MRSTR_LEN(str) || !len)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_size i;
    for (i = 0; i < len; i++)
        if (func(MRSTR_DATA(str)[i]) == MRSTR_FALSE)
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
