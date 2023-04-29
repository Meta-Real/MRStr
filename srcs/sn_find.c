/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_sn_find(mrstr_pc, mrstr_size, mrstr_cstr)
 * Returns the index of the first matched substring within the string up to the length
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_sn_find(mrstr_pc str, mrstr_size len, mrstr_cstr sub)
{
    mrstr_size slen, i;

    if (!(sub && (slen = strlen(sub))))
        return 0;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (len < slen)
        return MRSTR_NF;

    if (len == slen)
        return memcmp(MRSTR_DATA(str), sub, len) ? MRSTR_NF : 0;

    for (i = 0; i <= len - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, sub, slen))
            return i;

    return MRSTR_NF;
}
