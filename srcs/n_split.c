/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_t *mrstr_n_split(mrstr_size*, mrstr_pc, mrstr_size, mrstr_chr)
 * Splits the string according to the character up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (count) pointer must be valid
 *  (count) value must be zero
/*/

#include <intern.h>
#include <string.h>

mrstr_t *mrstr_n_split(mrstr_size *count, mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return NULL;

    mrstr_t *strs = __mrstr_das_alloc(MRSTR_DEF_STR_LST_LEN * sizeof(mrstr_t));
    if (!strs)
        mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_DEF_STR_LST_LEN * sizeof(mrstr_t), NULL);

    mrstr_size alloc = MRSTR_DEF_STR_LST_LEN;

    mrstr_size c = 0;
    if (!count)
        count = &c;

    MRSTR_DATA(*strs) = __mrstr_das_alloc(MRSTR_DEF_LEN);
    if (!MRSTR_DATA(*strs))
    {
        __mrstr_das_free(strs);
        mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_DEF_LEN, NULL);
    }

    MRSTR_LEN(*strs) = 0;
    MRSTR_OFFSET(*strs) = 0;

    mrstr_size salloc = MRSTR_DEF_LEN;

    mrstr_p cstr = *strs;
    mrstr_size i;
    void *tdata;
    for (i = 0; i < len; i++)
    {
        if (MRSTR_DATA(str)[i] == chr)
        {
            if (!MRSTR_LEN(cstr))
            {
                __mrstr_das_free(MRSTR_DATA(cstr));
                MRSTR_DATA(cstr) = NULL;
            }
            else
            {
                if (salloc != MRSTR_LEN(cstr) + 1)
                {
                    tdata = __mrstr_das_realloc(MRSTR_DATA(cstr), MRSTR_LEN(cstr) + 1);
                    if (!tdata)
                    {
                        for (i = 0; i <= *count; i++)
                            __mrstr_das_free(MRSTR_DATA(strs[i]));

                        __mrstr_das_free(strs);
                        mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_LEN(cstr) + 1, NULL);
                    }

                    MRSTR_DATA(cstr) = tdata;
                }

                MRSTR_DATA(cstr)[MRSTR_LEN(cstr)] = '\0';
            }

            if (++*count == alloc)
            {
                tdata = __mrstr_das_realloc(strs, (alloc += MRSTR_DEF_STR_LST_LEN) * sizeof(mrstr_t));
                if (!tdata)
                {
                    for (i = 0; i < *count; i++)
                        __mrstr_das_free(MRSTR_DATA(strs[i]));

                    __mrstr_das_free(strs);
                    mrstr_dbg_aloc_err("mrstr_n_split", alloc * sizeof(mrstr_t), NULL);
                }

                strs = tdata;
            }

            cstr = strs[*count];

            MRSTR_DATA(cstr) = __mrstr_das_alloc(MRSTR_DEF_LEN);
            if (!MRSTR_DATA(cstr))
            {
                for (i = 0; i < *count; i++)
                    __mrstr_das_free(MRSTR_DATA(strs[i]));

                __mrstr_das_free(strs);
                mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_DEF_LEN, NULL);
            }

            MRSTR_LEN(cstr) = 0;
            MRSTR_OFFSET(cstr) = 0;

            salloc = MRSTR_DEF_LEN;
        }
        else
        {
            if (MRSTR_LEN(cstr) == salloc)
            {
                tdata = __mrstr_das_realloc(MRSTR_DATA(cstr), salloc += MRSTR_DEF_LEN);
                if (!tdata)
                {
                    for (i = 0; i <= *count; i++)
                        __mrstr_das_free(MRSTR_DATA(strs[i]));

                    __mrstr_das_free(strs);
                    mrstr_dbg_aloc_err("mrstr_n_split", salloc, NULL);
                }

                MRSTR_DATA(cstr) = tdata;
            }

            MRSTR_DATA(cstr)[MRSTR_LEN(cstr)++] = MRSTR_DATA(str)[i];
        }
    }

    if (!MRSTR_LEN(cstr))
    {
        __mrstr_das_free(MRSTR_DATA(cstr));
        MRSTR_DATA(cstr) = NULL;
    }
    else
    {
        if (salloc != MRSTR_LEN(cstr) + 1)
        {
            tdata = __mrstr_das_realloc(MRSTR_DATA(cstr), MRSTR_LEN(cstr) + 1);
            if (!tdata)
            {
                for (i = 0; i <= *count; i++)
                    __mrstr_das_free(MRSTR_DATA(strs[i]));

                __mrstr_das_free(strs);
                mrstr_dbg_aloc_err("mrstr_n_split", MRSTR_LEN(cstr) + 1, NULL);
            }

            MRSTR_DATA(cstr) = tdata;
        }

        MRSTR_DATA(cstr)[MRSTR_LEN(cstr)] = '\0';
    }

    if (++*count != alloc)
    {
        tdata = __mrstr_das_realloc(strs, *count * sizeof(mrstr_t));
        if (!tdata)
        {
            for (i = 0; i < *count; i++)
                __mrstr_das_free(MRSTR_DATA(strs[i]));

            __mrstr_das_free(strs);
            mrstr_dbg_aloc_err("mrstr_n_split", *count * sizeof(mrstr_t), NULL);
        }

        strs = tdata;
    }

    return strs;
}
