/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isodigit(mrstr_pc)
 * Checks whether the string consists of only octal digits
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isodigit(mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    const uint64_t* c_data = (const uint64_t*)MRSTR_DATA(str);

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str) / sizeof(uint64_t); i++)
        if ((c_data[i] | 0xf0f0f0f0f0f0f0f) != 0x3f3f3f3f3f3f3f3f || c_data[i] & 0x808080808080808)
            return MRSTR_FALSE;

    for (i *= sizeof(uint64_t); i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '7')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
