/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_cs_rtrim(mrstr_p, mrstr_pc, mrstr_cstr)
 * Trims the right set of characters matching one of the characters
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_cs_rtrim(mrstr_p res, mrstr_pc str, mrstr_cstr chrs)
{
    mrstr_size clen, i;

    if (!MRSTR_LEN(str))
        return;

    if (!(chrs && (clen = strlen(chrs))))
    {
        if (res == str)
            return;

        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_cs_rtrim", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
    }

    for (i = MRSTR_LEN(str); i;)
        if (!memchr(chrs, MRSTR_DATA(str)[--i], clen))
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
            mrstr_data_free("mrstr_cs_rtrim");

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                    i + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_cs_rtrim", i + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[i] = '\0';
        MRSTR_LEN(res) = i;
        return;
    }

    if (!i)
        return;

    MRSTR_DATA(res) = __mrstr_alloc(i + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_cs_rtrim", i + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), i);
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
    MRSTR_LEN(res) = i;
}
