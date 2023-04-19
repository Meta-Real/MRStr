/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n_rfind_str(mrstr_pc, mrstr_size, mrstr_cstr)
 * Returns the index of the last matched substring within the string up to the length
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n_rfind_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_NF;

    mrstr_size clen;
    if (!(substr && (clen = strlen(substr))))
        return MRSTR_LEN(str);

    if (len < clen)
        return MRSTR_NF;

    mrstr_size sidx = MRSTR_LEN(str) - len;

    if (len == clen)
        return memcmp(MRSTR_DATA(str) + sidx, substr, len) ? MRSTR_NF : sidx;

    mrstr_size i;
    for (i = MRSTR_LEN(str) - clen + 1; i != sidx;)
        if (!memcmp(MRSTR_DATA(str) + --i, substr, clen))
            return i;

    return MRSTR_NF;
}
