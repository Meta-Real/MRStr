/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_contains(mrstr_pc, mrstr_size, mrstr_pc)
 * Checks the existence of the substring within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_n_contains(mrstr_pc str, mrstr_size len, mrstr_pc sub)
{
    mrstr_size i;

    if (str == sub || !MRSTR_LEN(sub))
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (len < MRSTR_LEN(sub))
        return MRSTR_FALSE;

    if (len == MRSTR_LEN(sub))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(sub), len) ? MRSTR_FALSE : MRSTR_TRUE;

    for (i = 0; i <= len - MRSTR_LEN(sub); i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
            return MRSTR_TRUE;

    return MRSTR_FALSE;
}
