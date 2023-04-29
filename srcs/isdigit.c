/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_isdigit(mrstr_pc)
 * Checks whether the string consists of only digits
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_isdigit(mrstr_pc str)
{
    const mrstr_size *cdata;
    mrstr_size i;

    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    cdata = (const mrstr_size*)MRSTR_DATA(str);

    for (i = 0; i < MRSTR_LEN(str) / sizeof(mrstr_size); i++)
        if ((cdata[i] | 0xf0f0f0f0f0f0f0f) != 0x3f3f3f3f3f3f3f3f ||
            (cdata[i] & 0xe0e0e0e0e0e0e0e) >= 0xa0a0a0a0a0a0a0a)
            return MRSTR_FALSE;

    for (i *= sizeof(mrstr_size); i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] < '0' || MRSTR_DATA(str)[i] > '9')
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
