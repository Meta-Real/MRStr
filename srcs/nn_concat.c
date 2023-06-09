/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_nn_concat(mrstr_p, mrstr_pc, mrstr_size, mrstr_pc, mrstr_size)
 * Concatenates the first string up to the length and the second string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_nn_concat(mrstr_p res, mrstr_pc str1, mrstr_size len1, mrstr_pc str2, mrstr_size len2)
{
    if (len1 > MRSTR_LEN(str1))
        len1 = MRSTR_LEN(str1);

    if (len2 > MRSTR_LEN(str2))
        len2 = MRSTR_LEN(str2);

    if (res == str1)
    {
        mrstr_str tdata;

        if (!len1)
        {
            if (!len2)
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
                    mrstr_dbg_aloc_err("mrstr_nn_concat", MRSTR_OFFSET(res) + 1, );

                MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
                *MRSTR_DATA(res) = '\0';
                return;
            }

            MRSTR_LEN(res) = len2;
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len2 + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_nn_concat", len2 + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);

            if (res != str2)
                memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), len2 + 1);

            MRSTR_DATA(res)[len2] = '\0';
            return;
        }

        if (!len2)
        {
            if (len1 == MRSTR_LEN(res))
                return;

            MRSTR_LEN(res) = len1;
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len1 + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_nn_concat", len1 + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len1] = '\0';
            return;
        }

        MRSTR_LEN(res) = len1 + len2;
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_nn_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);

        if (res == str2)
            memmove(MRSTR_DATA(res) + len1, MRSTR_DATA(res), len2);
        else
            memcpy(MRSTR_DATA(res) + len1, MRSTR_DATA(str2), len2);

        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
        return;
    }

    if (res == str2)
    {
        mrstr_str tdata;

        if (!len2)
        {
            if (!len1)
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
                    mrstr_dbg_aloc_err("mrstr_nn_concat", MRSTR_OFFSET(res) + 1, );

                MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
                *MRSTR_DATA(res) = '\0';
                return;
            }

            MRSTR_LEN(res) = len1;
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len1 + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_nn_concat", len1 + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len1);
            MRSTR_DATA(res)[len1] = '\0';
            return;
        }

        if (!len1)
        {
            if (len2 == MRSTR_LEN(res))
                return;

            MRSTR_LEN(res) = len2;
            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len2 + MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_nn_concat", len2 + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len2] = '\0';
            return;
        }

        MRSTR_LEN(res) = len1 + len2;
        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_nn_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        memmove(MRSTR_DATA(res) + len1, MRSTR_DATA(res), len2);
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len1);
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
        return;
    }

    if (!len1)
    {
        if (!len2)
            return;

        MRSTR_DATA(res) = __mrstr_alloc(len2 + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_nn_concat", len2 + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), len2);
        MRSTR_DATA(res)[len2] = '\0';
        MRSTR_LEN(res) = len2;
        return;
    }

    if (!len2)
    {
        MRSTR_DATA(res) = __mrstr_alloc(len1 + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_nn_concat", len1 + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len1);
        MRSTR_DATA(res)[len1] = '\0';
        MRSTR_LEN(res) = len1;
        return;
    }

    MRSTR_LEN(res) = len1 + len2;
    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_nn_concat", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len1);
    memcpy(MRSTR_DATA(res) + len2, MRSTR_DATA(str2), len2);
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
