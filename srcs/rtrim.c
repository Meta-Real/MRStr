/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_rtrim(mrstr_p, mrstr_pc, mrstr_chr)
 * Trims the right set of characters matching the character
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_rtrim(mrstr_p res, mrstr_pc str, mrstr_chr chr)
{
    mrstr_size i;

    if (!MRSTR_LEN(str))
        return;

    for (i = MRSTR_LEN(str); i;)
        if (MRSTR_DATA(str)[--i] != chr)
        {
            i++;
            break;
        }

    if (res == str)
    {
        mrstr_str tdata;

        if (i == MRSTR_LEN(res))
            return;

        if (!i)
            mrstr_data_free("mrstr_rtrim");

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), i + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_rtrim", i + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[i] = '\0';
        MRSTR_LEN(res) = i;
        return;
    }

    if (!i)
        return;

    MRSTR_DATA(res) = __mrstr_alloc(i + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_rtrim", i + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), i);
    MRSTR_DATA(res)[i] = '\0';
    MRSTR_LEN(res) = i;
}
