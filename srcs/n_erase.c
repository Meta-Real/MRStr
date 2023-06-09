/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_erase(mrstr_p, mrstr_pc, mrstr_size, mrstr_pc)
 * Removes the matched substrings from the string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (memory leak)
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_erase(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_pc sub)
{
    mrstr_size i, j;
    mrstr_bool clr = MRSTR_FALSE;
    mrstr_str tdata;

    if (!MRSTR_LEN(str))
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!(len && MRSTR_LEN(sub)))
    {
        if (res == str)
            return;

        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_erase", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    if (str == sub)
    {
        if (len == MRSTR_LEN(str))
        {
            if (res == str)
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
                    mrstr_dbg_aloc_err("mrstr_n_erase", MRSTR_OFFSET(res) + 1, );

                MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
                *MRSTR_DATA(res) = '\0';
                return;
            }

            return;
        }

        if (res == str)
            return;

        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_erase", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    len -= MRSTR_LEN(sub);
    for (i = 0; memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)); i++)
        if (i == len)
        {
            clr = MRSTR_TRUE;
            break;
        }

    if (res == str)
    {
        if (clr)
            return;

        j = i;
        for (i += MRSTR_LEN(sub); i <= len;)
        {
            if (!memcmp(MRSTR_DATA(res) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
                i += MRSTR_LEN(sub);
            else
                MRSTR_DATA(res)[j++] = MRSTR_DATA(res)[i++];
        }

        MRSTR_LEN(res) -= i;
        if (!(j || MRSTR_LEN(res)))
        {
            if (!MRSTR_OFFSET(res))
            {
                __mrstr_free(MRSTR_DATA(res));
                MRSTR_DATA(res) = NULL;
                return;
            }

            tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_OFFSET(res) + 1);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_erase", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        memmove(MRSTR_DATA(res) + j, MRSTR_DATA(res) + i, MRSTR_LEN(res) + 1);
        MRSTR_LEN(res) += j;

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_n_erase", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_erase", MRSTR_LEN(str) + 1, );

    if (clr)
    {
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), i);

    j = i;
    for (i += MRSTR_LEN(sub); i <= len;)
    {
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
            i += MRSTR_LEN(sub);
        else
            MRSTR_DATA(res)[j++] = MRSTR_DATA(str)[i++];
    }

    MRSTR_LEN(res) = MRSTR_LEN(str) - i;
    if (!(j || MRSTR_LEN(res)))
    {
        __mrstr_free(MRSTR_DATA(res));
        MRSTR_DATA(res) = NULL;
        MRSTR_LEN(res) = 0;
        return;
    }

    memcpy(MRSTR_DATA(res) + j, MRSTR_DATA(str) + i, MRSTR_LEN(res) + 1);
    MRSTR_LEN(res) += j;

    tdata = __mrstr_realloc(MRSTR_DATA(res), MRSTR_LEN(res) + 1);
    if (!tdata)
        mrstr_dbg_aloc_err("mrstr_n_erase", MRSTR_LEN(res) + 1, );

    MRSTR_DATA(res) = tdata;
}
