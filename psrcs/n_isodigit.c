/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_isodigit(mrstr_pc, mrstr_size)
 * Checks whether the string consists of only octal digits up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_isodigit(mrstr_pc str, mrstr_size len)
{
    if (!MRSTR_LEN(str) || !len)
        return MRSTR_TRUE;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    const uint64_t* c_data = (const uint64_t*)MRSTR_DATA(str);

    mrstr_size i;
    for (i = 0; i < len / sizeof(uint64_t); i++)
        if ((c_data[i] | 0xf0f0f0f0f0f0f0f) != 0x3f3f3f3f3f3f3f3f || c_data[i] & 0x808080808080808)
            return MRSTR_FALSE;

    for (i *= sizeof(uint64_t); i < len; i++)
        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '7')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
