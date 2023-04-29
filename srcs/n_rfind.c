/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n_rfind(mrstr_pc, mrstr_size, mrstr_pc)
 * Returns the index of the last matched substring within the string up to the length
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n_rfind(mrstr_pc str, mrstr_size len, mrstr_pc sub)
{
    mrstr_size sidx, i;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_NF;

    if (!MRSTR_LEN(sub))
        return MRSTR_LEN(str);

    if (len < MRSTR_LEN(sub))
        return MRSTR_NF;

    if (str == sub)
        return 0;

    sidx = MRSTR_LEN(str) - len;

    if (len == MRSTR_LEN(sub))
        return memcmp(MRSTR_DATA(str) + sidx, MRSTR_DATA(sub), len) ? MRSTR_NF : sidx;

    for (i = MRSTR_LEN(str) - MRSTR_LEN(sub) + 1; i != sidx;)
        if (!memcmp(MRSTR_DATA(str) + --i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
            return i;

    return MRSTR_NF;
}
