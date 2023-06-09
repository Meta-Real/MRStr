/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_concat(mrstr_p, mrstr_pc, mrstr_pc)
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

void mrstr_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2)
{
    if (res == str1)
    {
        mrstr_size len;
        mrstr_str tdata;

        if (!MRSTR_LEN(str2))
            return;

        len = MRSTR_LEN(res) + MRSTR_LEN(str2);
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_concat", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);

        if (res == str2)
            memmove(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), MRSTR_LEN(res) + 1);
        else
            memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);

        MRSTR_LEN(res) = len;
        return;
    }

    if (res == str2)
    {
        mrstr_size len;
        mrstr_str tdata;

        if (!MRSTR_LEN(str1))
            return;

        if (!MRSTR_LEN(res))
        {
            MRSTR_LEN(res) = MRSTR_LEN(str1);
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(res) + 1);
            return;
        }

        len = MRSTR_LEN(res) + MRSTR_LEN(str1);
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_concat", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        memmove(MRSTR_DATA(res) + MRSTR_LEN(str1), MRSTR_DATA(res), MRSTR_LEN(res) + 1);
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1));
        MRSTR_LEN(res) = len;
        return;
    }

    if (!MRSTR_LEN(str1))
    {
        if (!MRSTR_LEN(str2))
            return;

        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str2) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_concat", MRSTR_LEN(str2) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str2);
        return;
    }

    if (!MRSTR_LEN(str2))
    {
        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str1) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_concat", MRSTR_LEN(str1) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str1);
        return;
    }

    MRSTR_LEN(res) = MRSTR_LEN(str1) + MRSTR_LEN(str2);
    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_concat", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1));
    memcpy(MRSTR_DATA(res) + MRSTR_LEN(str1), MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);
}
