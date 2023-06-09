/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_cn_concat(mrstr_p, mrstr_pc, mrstr_size, mrstr_chr)
 * Concatenates the string up to the length and the character
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_cn_concat(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (res == str)
    {
        mrstr_str tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 2);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_cn_concat", len + MRSTR_OFFSET(res) + 2, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[len++] = chr;
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    if (!len)
    {
        MRSTR_DATA(res) = __mrstr_alloc(2);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_cn_concat", 2ULL, );

        *MRSTR_DATA(res) = chr;
        MRSTR_DATA(res)[1] = '\0';
        MRSTR_LEN(res) = 1;
        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(len + 2);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_cn_concat", len + 2, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), len);
    MRSTR_DATA(res)[len++] = chr;
    MRSTR_DATA(res)[len] = '\0';
    MRSTR_LEN(res) = len;
}
