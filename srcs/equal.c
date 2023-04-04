/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_equal(mrstr_pc, mrstr_pc)
 * Compares str1 and str2
 *
 * input reqs:
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_equal(mrstr_pc str1, mrstr_pc str2)
{
    if (str1 == str2)
        return MRSTR_TRUE;

    if (MRSTR_LEN(str1) != MRSTR_LEN(str2))
        return MRSTR_FALSE;

    if (!MRSTR_LEN(str1))
        return MRSTR_TRUE;

    return memcmp(MRSTR_DATA(str1), MRSTR_DATA(str2), MRSTR_LEN(str1)) ? MRSTR_TRUE : MRSTR_FALSE;
}
