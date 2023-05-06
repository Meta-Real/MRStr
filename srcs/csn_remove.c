/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_csn_remove(mrstr_p, mrstr_pc, mrstr_size, mrstr_cstr)
 * Removes the matched characters from the string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_csn_remove(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr chrs)
{
    mrstr_size clen, i, j;
    mrstr_str tdata;

    if (!(MRSTR_LEN(str) && chrs && (clen = strlen(chrs))))
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    for (i = 0; i < len && !memchr(chrs, MRSTR_DATA(str)[i], clen); i++);

    if (res == str)
    {
        if (i == len)
            return;

        for (j = i++; i < len; i++)
            if (!memchr(chrs, MRSTR_DATA(res)[i], clen))
                MRSTR_DATA(res)[j++] = MRSTR_DATA(res)[i];

        if (!j && i == MRSTR_LEN(res))
            mrstr_data_free("mrstr_csn_remove");

        memmove(MRSTR_DATA(res) + j, MRSTR_DATA(res) + i, MRSTR_LEN(res) - i + 1);
        MRSTR_LEN(res) -= i - j;

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_csn_remove", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_csn_remove", MRSTR_LEN(str) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), i);

    if (i == len)
    {
        memcpy(MRSTR_DATA(res) + i, MRSTR_DATA(str) + i, MRSTR_LEN(str) - i + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    for (j = i++; i < len; i++)
        if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
            MRSTR_DATA(res)[j++] = MRSTR_DATA(str)[i];

    if (!j && i == MRSTR_LEN(str))
    {
        __mrstr_free(MRSTR_DATA(res));
        MRSTR_DATA(res) = NULL;
        return;
    }

    MRSTR_LEN(res) = MRSTR_LEN(str) - i + j;
    memcpy(MRSTR_DATA(res) + j, MRSTR_DATA(str) + i, MRSTR_LEN(res) + 1);

    tdata = __mrstr_realloc(MRSTR_DATA(res), MRSTR_LEN(res) + 1);
    if (!tdata)
        mrstr_dbg_aloc_err("mrstr_csn_remove", MRSTR_LEN(res) + 1, );

    MRSTR_DATA(res) = tdata;
}
