/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_all(mrstr_pc, mrstr_bool (*)(mrstr_chr))
 * Checks whether all the characters of the string are satisfying the given condition
 * The condition must be checked by the function
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
 *  (func) must return MRSTR_TRUE if the condition is satisfied and MRSTR_FALSE otherwise (non-fatal error)
/*/

#include <mrstr.h>

mrstr_bool mrstr_all(mrstr_pc str, mrstr_bool (*func)(mrstr_chr chr))
{
    mrstr_size i;

    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    for (i = 0; i < MRSTR_LEN(str); i++)
        if (func(MRSTR_DATA(str)[i]) == MRSTR_FALSE)
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
