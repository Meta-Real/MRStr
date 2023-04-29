/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_s_contains(mrstr_pc, mrstr_cstr)
 * Checks the existence of the substring within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_s_contains(mrstr_pc str, mrstr_cstr sub)
{
    mrstr_size slen, i;

    if (!(sub && (slen = strlen(sub))))
        return MRSTR_TRUE;

    if (slen > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (slen == MRSTR_LEN(str))
        return memcmp(MRSTR_DATA(str), sub, slen) ? MRSTR_FALSE : MRSTR_TRUE;

    for (i = 0; i <= MRSTR_LEN(str) - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, sub, slen))
            return MRSTR_TRUE;

    return MRSTR_FALSE;
}
