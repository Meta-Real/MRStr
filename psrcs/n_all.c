/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_all(mrstr_pc, mrstr_size, mrstr_bool (*)(mrstr_chr))
 * Checks whether all the characters of the string up to the length are satisfying the given condition
 * The condition must be checked by the function
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
 *  (func) must return MRSTR_TRUE if the condition satisfied and MRSTR_FALSE otherwise (non-fatal error)
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_all(mrstr_pc str, mrstr_size len, mrstr_bool (*func)(mrstr_chr chr))
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
