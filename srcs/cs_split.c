/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_t *mrstr_cs_split(mrstr_size*, mrstr_pc, mrstr_cstr)
 * Splits the string according to the character
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (cnt) pointer must be valid
 *  (cnt) value must be zero
/*/

#include <intern.h>
#include <string.h>

mrstr_t *mrstr_cs_split(mrstr_size *cnt, mrstr_pc str, mrstr_cstr chrs)
{
    mrstr_size clen, alloc, c, salloc, i;
    mrstr_t *strs;
    void* tdata;

    if (!MRSTR_LEN(str))
        return NULL;

    if (!(chrs && (clen = strlen(chrs))))
    {
        strs = __mrstr_alloc(sizeof(mrstr_t));
        if (!strs)
            mrstr_dbg_aloc_err("mrstr_cs_split", sizeof(mrstr_t), NULL);

        if (cnt)
            *cnt = 1;

        MRSTR_DATA(*strs) = __mrstr_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(*strs))
            mrstr_dbg_aloc_err("mrstr_cs_split", MRSTR_LEN(str) + 1, NULL);

        memcpy(MRSTR_DATA(*strs), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(*strs) = MRSTR_LEN(str);
        MRSTR_OFFSET(*strs) = 0;
        return strs;
    }

    strs = __mrstr_alloc(MRSTR_DEF_STR_LST_LEN * sizeof(mrstr_t));
    if (!strs)
        mrstr_dbg_aloc_err("mrstr_cs_split", MRSTR_DEF_STR_LST_LEN * sizeof(mrstr_t), NULL);

    alloc = MRSTR_DEF_STR_LST_LEN;

    c = 0;
    if (!cnt)
        cnt = &c;

    MRSTR_DATA(*strs) = __mrstr_alloc(MRSTR_DEF_LEN);
    if (!MRSTR_DATA(*strs))
    {
        __mrstr_free(strs);
        mrstr_dbg_aloc_err("mrstr_cs_split", MRSTR_DEF_LEN, NULL);
    }

    MRSTR_LEN(*strs) = 0;
    MRSTR_OFFSET(*strs) = 0;

    salloc = MRSTR_DEF_LEN;

    for (i = 0; i < MRSTR_LEN(str); i++)
    {
        if (memchr(chrs, MRSTR_DATA(str)[i], clen))
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
                        mrstr_dbg_aloc_err("mrstr_cs_split", MRSTR_LEN(*strs) + 1, NULL);
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
                    mrstr_dbg_aloc_err("mrstr_cs_split", alloc * sizeof(mrstr_t), NULL);
                }

                strs = tdata;
            }

            MRSTR_DATA(*strs) = __mrstr_alloc(MRSTR_DEF_LEN);
            if (!MRSTR_DATA(*strs))
            {
                for (i = 0; i < *cnt; i++)
                    __mrstr_free(MRSTR_DATA(strs[i]));

                __mrstr_free(strs);
                mrstr_dbg_aloc_err("mrstr_cs_split", MRSTR_DEF_LEN, NULL);
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
                    mrstr_dbg_aloc_err("mrstr_cs_split", salloc, NULL);
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
                mrstr_dbg_aloc_err("mrstr_cs_split", MRSTR_LEN(*strs) + 1, NULL);
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
            mrstr_dbg_aloc_err("mrstr_cs_split", *cnt * sizeof(mrstr_t), NULL);
        }

        strs = tdata;
    }

    return strs;
}
