/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_nn_contains(mrstr_pc, mrstr_size, mrstr_pc, mrstr_size)
 * Checks the existence of the substring up to the length within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_nn_contains(mrstr_pc str, mrstr_size len1, mrstr_pc substr, mrstr_size len2)
{
    if (str == substr || !(MRSTR_LEN(substr) && len2))
        return MRSTR_TRUE;

    if (len1 > MRSTR_LEN(str))
        len1 = MRSTR_LEN(str);

    if (len2 > MRSTR_LEN(substr))
        len2 = MRSTR_LEN(substr);

    if (len1 < len2)
        return MRSTR_FALSE;

    if (len1 == len2)
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(substr), len1) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i;
    for (i = 0; i <= len1 - len2; i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(substr), len2))
            return MRSTR_TRUE;

    return MRSTR_FALSE;
}
