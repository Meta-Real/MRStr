/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n2_concat(mrstr_p, mrstr_pc, mrstr_pc, mrstr_size)
 * Concatenates the first string and the second string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n2_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2, mrstr_size len)
{
    if (len > MRSTR_LEN(str2))
        len = MRSTR_LEN(str2);

    if (res == str1)
    {
        mrstr_size nlen;
        mrstr_str tdata;

        if (!len)
            return;

        nlen = MRSTR_LEN(res) + len;
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), nlen + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_n2_concat", nlen + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);

        if (res == str2)
            memmove(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), len);
        else
            memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(str2), len);

        MRSTR_DATA(res)[nlen] = '\0';
        MRSTR_LEN(res) = nlen;
        return;
    }

    if (res == str2)
    {
        mrstr_str tdata;

        if (!len)
        {
            if (!MRSTR_LEN(str1))
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
                    mrstr_dbg_aloc_err("mrstr_n2_concat", MRSTR_OFFSET(res) + 1, );

                MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
                *MRSTR_DATA(res) = '\0';
                return;
            }

            MRSTR_LEN(res) = MRSTR_LEN(str1);
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_n2_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(res) + 1);
            return;
        }

        if (!MRSTR_LEN(str1))
        {
            if (len == MRSTR_LEN(res))
                return;

            MRSTR_LEN(res) = len;
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_n2_concat", len + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len] = '\0';
            return;
        }

        MRSTR_LEN(res) = MRSTR_LEN(str1) + len;
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_n2_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        memmove(MRSTR_DATA(res) + MRSTR_LEN(str1), MRSTR_DATA(res), len);
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1));
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
        return;
    }

    if (!MRSTR_LEN(str1))
    {
        if (!len)
            return;

        MRSTR_DATA(res) = __mrstr_alloc(len + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n2_concat", len + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), len + 1);
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    if (!len)
    {
        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str1) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n2_concat", MRSTR_LEN(str1) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str1);
        return;
    }

    MRSTR_LEN(res) = MRSTR_LEN(str1) + len;
    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n2_concat", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1));
    memcpy(MRSTR_DATA(res) + MRSTR_LEN(str1), MRSTR_DATA(str2), len);
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
