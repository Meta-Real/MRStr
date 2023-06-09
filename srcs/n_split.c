/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_t *mrstr_n_split(mrstr_size*, mrstr_pc, mrstr_size, mrstr_chr)
 * Splits the string according to the character up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (cnt) pointer must be valid
 *  (cnt) value must be zero
/*/

#include <intern.h>
#include <string.h>

mrstr_t *mrstr_n_split(mrstr_size *cnt, mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    mrstr_t *strs;
    mrstr_size alloc, c, salloc, i;
    void *tdata;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return NULL;

    strs = __mrstr_alloc(MRSTR_DEF_STR_LST_LEN * sizeof(mrstr_t));
    if (!strs)
        mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_DEF_STR_LST_LEN * sizeof(mrstr_t), NULL);

    alloc = MRSTR_DEF_STR_LST_LEN;

    c = 0;
    if (!cnt)
        cnt = &c;

    MRSTR_DATA(*strs) = __mrstr_alloc(MRSTR_DEF_LEN);
    if (!MRSTR_DATA(*strs))
    {
        __mrstr_free(strs);
        mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_DEF_LEN, NULL);
    }

    MRSTR_LEN(*strs) = 0;
    MRSTR_OFFSET(*strs) = 0;

    salloc = MRSTR_DEF_LEN;

    for (i = 0; i < len; i++)
    {
        if (MRSTR_DATA(str)[i] == chr)
        {
            if (!MRSTR_LEN(*strs))
            {
                __mrstr_free(MRSTR_DATA(*strs));
                MRSTR_DATA(*strs) = NULL;
            }
            else
            {
                if (salloc != MRSTR_LEN(*strs) + 1)
                {
                    tdata = __mrstr_realloc(MRSTR_DATA(*strs), MRSTR_LEN(*strs) + 1);
                    if (!tdata)
                    {
                        for (i = 0; i <= *cnt; i++)
                            __mrstr_free(MRSTR_DATA(strs[i]));

                        __mrstr_free(strs);
                        mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_LEN(*strs) + 1, NULL);
                    }

                    MRSTR_DATA(*strs) = tdata;
                }

                MRSTR_DATA(*strs)[MRSTR_LEN(*strs)] = '\0';
            }

            if (++*cnt == alloc)
            {
                tdata = __mrstr_realloc(strs, (alloc += MRSTR_DEF_STR_LST_LEN) * sizeof(mrstr_t));
                if (!tdata)
                {
                    for (i = 0; i < *cnt; i++)
                        __mrstr_free(MRSTR_DATA(strs[i]));

                    __mrstr_free(strs);
                    mrstr_dbg_aloc_err("mrstr_n_split", alloc * sizeof(mrstr_t), NULL);
                }

                strs = tdata;
            }

            MRSTR_DATA(*strs) = __mrstr_alloc(MRSTR_DEF_LEN);
            if (!MRSTR_DATA(*strs))
            {
                for (i = 0; i < *cnt; i++)
                    __mrstr_free(MRSTR_DATA(strs[i]));

                __mrstr_free(strs);
                mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_DEF_LEN, NULL);
            }

            MRSTR_LEN(*strs) = 0;
            MRSTR_OFFSET(*strs) = 0;

            salloc = MRSTR_DEF_LEN;
        }
        else
        {
            if (MRSTR_LEN(*strs) == salloc)
            {
                tdata = __mrstr_realloc(MRSTR_DATA(*strs), salloc += MRSTR_DEF_LEN);
                if (!tdata)
                {
                    for (i = 0; i <= *cnt; i++)
                        __mrstr_free(MRSTR_DATA(strs[i]));

                    __mrstr_free(strs);
                    mrstr_dbg_aloc_err("mrstr_n_split", salloc, NULL);
                }

                MRSTR_DATA(*strs) = tdata;
            }

            MRSTR_DATA(*strs)[MRSTR_LEN(*strs)++] = MRSTR_DATA(str)[i];
        }
    }

    if (!MRSTR_LEN(*strs))
    {
        __mrstr_free(MRSTR_DATA(*strs));
        MRSTR_DATA(*strs) = NULL;
    }
    else
    {
        if (salloc != MRSTR_LEN(*strs) + 1)
        {
            tdata = __mrstr_realloc(MRSTR_DATA(*strs), MRSTR_LEN(*strs) + 1);
            if (!tdata)
            {
                for (i = 0; i <= *cnt; i++)
                    __mrstr_free(MRSTR_DATA(strs[i]));

                __mrstr_free(strs);
                mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_LEN(*strs) + 1, NULL);
            }

            MRSTR_DATA(*strs) = tdata;
        }

        MRSTR_DATA(*strs)[MRSTR_LEN(*strs)] = '\0';
    }

    if (++*cnt != alloc)
    {
        tdata = __mrstr_realloc(strs, *cnt * sizeof(mrstr_t));
        if (!tdata)
        {
            for (i = 0; i < *cnt; i++)
                __mrstr_free(MRSTR_DATA(strs[i]));

            __mrstr_free(strs);
            mrstr_dbg_aloc_err("mrstr_n_split", *cnt * sizeof(mrstr_t), NULL);
        }

        strs = tdata;
    }

    return strs;
}
