/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_repeat(mrstr_p, mrstr_pc, mrstr_size)
 * Repeats the string count times
 * Throws MOVF_ERR if the length of the result string exceeds the mrstr_size limit
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_repeat(mrstr_p res, mrstr_pc str, mrstr_size cnt)
{
    mrstr_size len;

    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_str tdata;

        if (cnt == 1)
            return;

        if (!cnt)
        {
            MRSTR_LEN(res) = 0;

            if (!MRSTR_OFFSET(res))
            {
                __mrstr_free(MRSTR_DATA(res));
                MRSTR_DATA(res) = NULL;
                return;
            }

            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_repeat", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        len = MRSTR_LEN(res) * cnt;
        if (len / MRSTR_LEN(res) != cnt)
            mrstr_dbg_movf_err("mrstr_repeat", );

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_repeat", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);

        if (MRSTR_LEN(res) == 1)
        {
            memset(MRSTR_DATA(res) + 1, *MRSTR_DATA(res), len - 1);
            MRSTR_DATA(res)[len] = '\0';
            MRSTR_LEN(res) = len;
            return;
        }

        while (MRSTR_LEN(res) <= len - MRSTR_LEN(res))
        {
            memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), MRSTR_LEN(res));
            MRSTR_LEN(res) *= 2;
        }

        memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), len - MRSTR_LEN(res));
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    if (!cnt)
        return;

    len = MRSTR_LEN(str) * cnt;
    if (len / MRSTR_LEN(str) != cnt)
        mrstr_dbg_movf_err("mrstr_repeat", );

    MRSTR_DATA(res) = __mrstr_alloc(len + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_repeat", len + 1, );

    if (MRSTR_LEN(str) == 1)
    {
        memset(MRSTR_DATA(res), *MRSTR_DATA(str), len);
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str));
    MRSTR_LEN(res) = MRSTR_LEN(str);

    while (MRSTR_LEN(res) <= len - MRSTR_LEN(res))
    {
        memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), MRSTR_LEN(res));
        MRSTR_LEN(res) *= 2;
    }

    memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), len - MRSTR_LEN(res));
    MRSTR_DATA(res)[len] = '\0';
    MRSTR_LEN(res) = len;
}
