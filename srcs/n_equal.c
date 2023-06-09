/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_equal(mrstr_pc, mrstr_pc, mrstr_size)
 * Checks whether the first string equals the second string up to the length
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_n_equal(mrstr_pc str1, mrstr_pc str2, mrstr_size len)
{
    if (str1 == str2 || !len)
        return MRSTR_TRUE;

    if (MRSTR_LEN(str1) == MRSTR_LEN(str2))
    {
        if (!MRSTR_LEN(str1))
            return MRSTR_TRUE;

        if (len > MRSTR_LEN(str1))
            len = MRSTR_LEN(str1);

        return memcmp(MRSTR_DATA(str1), MRSTR_DATA(str2), len) ? MRSTR_FALSE : MRSTR_TRUE;
    }

    if (MRSTR_LEN(str1) < len || MRSTR_LEN(str2) < len)
        return MRSTR_FALSE;

    return memcmp(MRSTR_DATA(str1), MRSTR_DATA(str2), len) ? MRSTR_FALSE : MRSTR_TRUE;
}
