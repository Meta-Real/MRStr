/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n_rfind(mrstr_pc, mrstr_size, mrstr_pc)
 * Returns the index of the last matched substring within the string up to the length
 * Returns MRSTR_NF if it does not exist
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n_rfind(mrstr_pc str, mrstr_size len, mrstr_pc substr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_NF;

    if (!MRSTR_LEN(substr))
        return MRSTR_LEN(str);

    if (len < MRSTR_LEN(substr))
        return MRSTR_NF;

    mrstr_size sidx = MRSTR_LEN(str) - len;

    if (len == MRSTR_LEN(substr))
        return memcmp(MRSTR_DATA(str) + sidx, MRSTR_DATA(substr), len) ? MRSTR_NF : 0;

    mrstr_size i;
    for (i = MRSTR_LEN(str) - MRSTR_LEN(substr); i != sidx; i--)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(substr), MRSTR_LEN(substr)))
            return i;

    return MRSTR_NF;
}
