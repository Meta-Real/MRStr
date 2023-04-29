/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n_find(mrstr_pc, mrstr_size, mrstr_pc)
 * Returns the index of the first matched substring within the string up to the length
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n_find(mrstr_pc str, mrstr_size len, mrstr_pc sub)
{
    mrstr_size i;

    if (str == sub || !MRSTR_LEN(sub))
        return 0;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (len < MRSTR_LEN(sub))
        return MRSTR_NF;

    if (len == MRSTR_LEN(sub))
        return memcmp(MRSTR_DATA(str), MRSTR_DATA(sub), len) ? MRSTR_NF : 0;

    for (i = 0; i <= len - MRSTR_LEN(sub); i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
            return i;

    return MRSTR_NF;
}
