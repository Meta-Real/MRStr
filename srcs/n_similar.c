/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_similar(mrstr_pc, mrstr_pc, mrstr_size, mrstr_bool (*)(mrstr_chr, mrstr_chr))
 * Checks whether all the characters of the strings are similar in the defined way up to the length
 * The similarity must be checked by the function
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
 *  (func) pointer must be valid
 *  (func) must return MRSTR_TRUE if characters are similar and MRSTR_FALSE otherwise (non-fatal error)
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_similar(mrstr_pc str1, mrstr_pc str2, mrstr_size len,
                           mrstr_bool (*func)(mrstr_chr, mrstr_chr))
{
    mrstr_size i;

    if (MRSTR_LEN(str1) != MRSTR_LEN(str2))
        return MRSTR_FALSE;

    if (len > MRSTR_LEN(str1))
        len = MRSTR_LEN(str1);

    if (!len)
        return MRSTR_TRUE;

    for (i = 0; i < len; i++)
        if (func(MRSTR_DATA(str1)[i], MRSTR_DATA(str2)[i]) == MRSTR_FALSE)
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
