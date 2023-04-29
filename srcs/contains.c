/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_contains(mrstr_pc, mrstr_pc)
 * Checks the existence of the substring within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_contains(mrstr_pc str, mrstr_pc sub)
{
    mrstr_size i;

    if (str == sub || !MRSTR_LEN(sub))
        return MRSTR_TRUE;

    if (MRSTR_LEN(str) < MRSTR_LEN(sub))
        return MRSTR_FALSE;

    if (MRSTR_LEN(str) == MRSTR_LEN(sub))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(sub), MRSTR_LEN(str)) ? MRSTR_FALSE : MRSTR_TRUE;

    for (i = 0; i <= MRSTR_LEN(str) - MRSTR_LEN(sub); i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
            return MRSTR_TRUE;

    return MRSTR_FALSE;
}
