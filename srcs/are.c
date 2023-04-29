/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_are(mrstr_pc, mrstr_chr)
 * Checks whether the string consists of only the specified character
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_are(mrstr_pc str, mrstr_chr chr)
{
    const mrstr_size *cdata;
    mrstr_size mask, i;

    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    cdata = (const mrstr_size*)MRSTR_DATA(str);
    mask = chr * 0x0101010101010101;

    for (i = 0; i < MRSTR_LEN(str) / sizeof(mrstr_size); i++)
        if (cdata[i] ^ mask)
            return MRSTR_FALSE;

    for (i *= sizeof(mrstr_size); i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] != chr)
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
