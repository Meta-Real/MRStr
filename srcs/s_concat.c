/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_s_concat(mrstr_p, mrstr_pc, mrstr_cstr)
 * Concatenates the first string and the second string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_s_concat(mrstr_p res, mrstr_pc str1, mrstr_cstr str2)
{
    mrstr_size slen;

    if (res == str1)
    {
        mrstr_size len;
        mrstr_str tdata;

        if (!(str2 && (slen = strlen(str2))))
            return;

        len = MRSTR_LEN(res) + slen;
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_s_concat", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), str2, slen + 1);
        MRSTR_LEN(res) = len;
        return;
    }

    if (!MRSTR_LEN(str1))
    {
        if (!(str2 && (slen = strlen(str2))))
            return;

        MRSTR_DATA(res) = __mrstr_alloc(slen + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_s_concat", slen + 1, );

        memcpy(MRSTR_DATA(res), str2, slen + 1);
        MRSTR_LEN(res) = slen;
        return;
    }

    if (!(str2 && (slen = strlen(str2))))
    {
        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str1) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_s_concat", MRSTR_LEN(str1) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str1);
        return;
    }

    MRSTR_LEN(res) = MRSTR_LEN(str1) + slen;
    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_s_concat", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1));
    memcpy(MRSTR_DATA(res) + MRSTR_LEN(str1), str2, slen + 1);
}
