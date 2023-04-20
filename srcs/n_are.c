/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_n_are(mrstr_pc, mrstr_size, mrstr_chr)
 * Checks whether the string consists of only the specified character up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

mrstr_bool mrstr_n_are(mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return MRSTR_TRUE;

    const uint64_t* cdata = (const uint64_t*)MRSTR_DATA(str);
    uint64_t mask = chr * 0x0101010101010101;

    mrstr_size i;
    for (i = 0; i < len / sizeof(uint64_t); i++)
        if (cdata[i] ^ mask)
            return MRSTR_FALSE;

    for (i *= sizeof(uint64_t); i < len; i++)
        if (MRSTR_DATA(str)[i] != chr)
            return MRSTR_FALSE;

    return MRSTR_TRUE;
}
