/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_s_find(mrstr_pc, mrstr_cstr)
 * Returns the index of the first matched substring within the string
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_s_find(mrstr_pc str, mrstr_cstr sub)
{
    mrstr_size slen, i;

    if (!(sub && (slen = strlen(sub))))
        return 0;

    if (slen > MRSTR_LEN(str))
        return MRSTR_NF;

    if (slen == MRSTR_LEN(str))
        return memcmp(MRSTR_DATA(str), sub, slen) ? MRSTR_NF : 0;

    for (i = 0; i <= MRSTR_LEN(str) - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, sub, slen))
            return i;

    return MRSTR_NF;
}
