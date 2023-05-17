/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_sn_concat(mrstr_p, mrstr_pc, mrstr_size, mrstr_cstr)
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

void mrstr_sn_concat(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_cstr str2)
{
    mrstr_size slen;

    if (len > MRSTR_LEN(str1))
        len = MRSTR_LEN(str1);

    if (res == str1)
    {
        mrstr_str tdata;

        if (!len)
        {
            if (!(str2 && (slen = strlen(str2))))
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
                    mrstr_dbg_aloc_err("mrstr_sn_concat", MRSTR_OFFSET(res) + 1, );

                MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
                *MRSTR_DATA(res) = '\0';
                return;
            }

            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), slen + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_sn_concat", slen + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), str2, slen + 1);
            MRSTR_LEN(res) = slen;
            return;
        }

        if (!(str2 && (slen = strlen(str2))))
        {
            if (len == MRSTR_LEN(res))
                return;

            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_sn_concat", len + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len] = '\0';
            MRSTR_LEN(res) = len;
            return;
        }

        MRSTR_LEN(res) = len + slen;
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_sn_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res) + len, str2, slen + 1);
        return;
    }

    if (!len)
    {
        if (!(str2 && (slen = strlen(str2))))
            return;

        MRSTR_DATA(res) = __mrstr_alloc(slen + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_sn_concat", slen + 1, );

        memcpy(MRSTR_DATA(res), str2, slen + 1);
        MRSTR_LEN(res) = slen;
        return;
    }

    if (!(str2 && (slen = strlen(str2))))
    {
        MRSTR_DATA(res) = __mrstr_alloc(len + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_sn_concat", len + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    MRSTR_LEN(res) = len + slen;
    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_sn_concat", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
    memcpy(MRSTR_DATA(res) + len, str2, slen + 1);
}
