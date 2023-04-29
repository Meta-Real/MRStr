/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size *mrstr_find_all(mrstr_size*, mrstr_pc, mrstr_pc)
 * Returns the indexes of the matched substrings within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (sub) pointer must be valid
 *  (cnt) pointer must be valid
 *  (cnt) value must be zero (if pointer is not NULL)
/*/

#include <intern.h>
#include <string.h>

mrstr_size *mrstr_find_all(mrstr_size *cnt, mrstr_pc str, mrstr_pc sub)
{
    mrstr_size *idxs, *tdata;
    mrstr_size alloc, c, i;

    if (str == sub)
    {
        idxs = __mrstr_alloc(sizeof(mrstr_size));
        if (!idxs)
            mrstr_dbg_aloc_err("mrstr_find_all", sizeof(mrstr_size), NULL);

        *idxs = 0;
        *cnt = 1;
        return idxs;
    }

    if (!MRSTR_LEN(sub) || MRSTR_LEN(str) < MRSTR_LEN(sub))
        return NULL;

    if (MRSTR_LEN(str) == MRSTR_LEN(sub))
    {
        if (memcmp(MRSTR_DATA(str), MRSTR_DATA(sub), MRSTR_LEN(str)))
            return NULL;

        idxs = __mrstr_alloc(sizeof(mrstr_size));
        if (!idxs)
            mrstr_dbg_aloc_err("mrstr_find_all", sizeof(mrstr_size), NULL);

        *idxs = 0;
        *cnt = 1;
        return idxs;
    }

    idxs = __mrstr_alloc(MRSTR_DEF_IDX_LST_LEN * sizeof(mrstr_size));
    if (!idxs)
        mrstr_dbg_aloc_err("mrstr_find_all", MRSTR_DEF_IDX_LST_LEN * sizeof(mrstr_size), NULL);

    alloc = MRSTR_DEF_IDX_LST_LEN;

    c = 0;
    if (!cnt)
        cnt = &c;

    for (i = 0; i <= MRSTR_LEN(str) - MRSTR_LEN(sub); i++)
        if (!memcmp(MRSTR_DATA(str) + i, MRSTR_DATA(sub), MRSTR_LEN(sub)))
        {
            if (*cnt == alloc)
            {
                tdata = __mrstr_realloc(idxs, (alloc += MRSTR_DEF_IDX_LST_LEN) * sizeof(mrstr_size));
                if (!tdata)
                {
                    __mrstr_free(idxs);
                    mrstr_dbg_aloc_err("mrstr_find_all", alloc * sizeof(mrstr_size), NULL);
                }

                idxs = tdata;
            }

            idxs[(*cnt)++] = i;
        }

    if (!*cnt)
    {
        __mrstr_free(idxs);
        return NULL;
    }

    if (*cnt != alloc)
    {
        tdata = __mrstr_realloc(idxs, *cnt * sizeof(mrstr_size));
        if (!tdata)
        {
            __mrstr_free(idxs);
            mrstr_dbg_aloc_err("mrstr_find_all", *cnt * sizeof(mrstr_size), NULL);
        }

        idxs = tdata;
    }

    return idxs;
}
