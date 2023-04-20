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
    if (!MRSTR_LEN(str))
        return MRSTR_TRUE;

    const uint64_t* cdata = (const uint64_t*)MRSTR_DATA(str);
    uint64_t mask = chr * 0x0101010101010101;

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str) / sizeof(uint64_t); i++)
        if (cdata[i] ^ mask)
            return MRSTR_FALSE;

    for (i *= sizeof(uint64_t); i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] != chr)
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
