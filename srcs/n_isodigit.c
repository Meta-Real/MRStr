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
    const mrstr_size *cdata;
    mrstr_size i;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_TRUE;

    cdata = (const mrstr_size*)MRSTR_DATA(str);

    for (i = 0; i < len / sizeof(mrstr_size); i++)
        if ((cdata[i] | 0xf0f0f0f0f0f0f0f) != 0x3f3f3f3f3f3f3f3f ||
            cdata[i] & 0x808080808080808)
            return MRSTR_FALSE;

    for (i *= sizeof(mrstr_size); i < len; i++)
        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '7')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
