/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_sn_rfind(mrstr_pc, mrstr_size, mrstr_cstr)
 * Returns the index of the last matched substring within the string up to the length
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_sn_rfind(mrstr_pc str, mrstr_size len, mrstr_cstr sub)
{
    mrstr_size slen, sidx, i;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_NF;

    if (!(sub && (slen = strlen(sub))))
        return MRSTR_LEN(str);

    if (len < slen)
        return MRSTR_NF;

    sidx = MRSTR_LEN(str) - len;

    if (len == slen)
        return memcmp(MRSTR_DATA(str) + sidx, sub, len) ? MRSTR_NF : sidx;

    for (i = MRSTR_LEN(str) - slen + 1; i != sidx;)
        if (!memcmp(MRSTR_DATA(str) + --i, sub, slen))
            return i;

    return MRSTR_NF;
}
