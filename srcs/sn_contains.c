/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_sn_contains(mrstr_pc, mrstr_size, mrstr_cstr)
 * Checks the existence of the substring within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_sn_contains(mrstr_pc str, mrstr_size len, mrstr_cstr sub)
{
    mrstr_size slen, i;

    if (!(sub && (slen = strlen(sub))))
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (len < slen)
        return MRSTR_FALSE;

    if (len == slen)
        return memcmp(MRSTR_DATA(str), sub, len) ? MRSTR_FALSE : MRSTR_TRUE;

    for (i = 0; i <= len - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, sub, slen))
            return MRSTR_TRUE;

    return MRSTR_FALSE;
}
