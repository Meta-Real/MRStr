/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_concat(mrstr_p, mrstr_pc, mrstr_size, mrstr_pc)
 * Concatenates the first string up to the length and the second string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_concat(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_pc str2)
{
    if (len > MRSTR_LEN(str1))
        len = MRSTR_LEN(str1);

    if (res == str1)
    {
        mrstr_str tdata;

        if (!len)
        {
            if (res == str2)
                return;

            if (!MRSTR_LEN(str2))
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
                    mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_OFFSET(res) + 1, );

                MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
                *MRSTR_DATA(res) = '\0';
                return;
            }

            MRSTR_LEN(res) = MRSTR_LEN(str2);
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), MRSTR_LEN(res) + 1);
            return;
        }

        if (!MRSTR_LEN(str2))
        {
            if (len == MRSTR_LEN(res))
                return;

            MRSTR_LEN(res) = len;
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_n_concat", len + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len] = '\0';
            return;
        }

        MRSTR_LEN(res) = len + MRSTR_LEN(str2);
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);

        if (res == str2)
            memmove(MRSTR_DATA(res) + len, MRSTR_DATA(res), MRSTR_LEN(res) + 1);
        else
            memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);

        return;
    }

    if (res == str2)
    {
        mrstr_str tdata;
        mrstr_size nlen;

        if (!len)
            return;

        if (!MRSTR_LEN(res))
        {
            MRSTR_LEN(res) = len;
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_n_concat", len + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
            MRSTR_DATA(res)[len] = '\0';
            return;
        }

        nlen = len + MRSTR_LEN(res);
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), nlen + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_n_concat", nlen + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        memmove(MRSTR_DATA(res) + len, MRSTR_DATA(res), MRSTR_LEN(res) + 1);
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
        MRSTR_LEN(res) = nlen;
        return;
    }

    if (!len)
    {
        if (!MRSTR_LEN(str2))
            return;

        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str2) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(str2) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str2);
        return;
    }

    if (!MRSTR_LEN(str2))
    {
        MRSTR_DATA(res) = __mrstr_alloc(len + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat", len + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    MRSTR_LEN(res) = len + MRSTR_LEN(str2);
    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
    memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);
}
