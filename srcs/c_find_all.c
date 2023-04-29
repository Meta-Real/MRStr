/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size *mrstr_c_find_all(mrstr_size*, mrstr_pc, mrstr_chr)
 * Returns the indexes of the matched characters within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (cnt) pointer must be valid
 *  (cnt) value must be zero (if pointer is not NULL)
/*/

#include <intern.h>
#include <string.h>

mrstr_size *mrstr_c_find_all(mrstr_size *cnt, mrstr_pc str, mrstr_chr chr)
{
    mrstr_size *idxs, *tdata;
    mrstr_size alloc, c, i;

    if (!MRSTR_LEN(str))
        return NULL;

    idxs = __mrstr_alloc(MRSTR_DEF_IDX_LST_LEN * sizeof(mrstr_size));
    if (!idxs)
        mrstr_dbg_aloc_err("mrstr_c_find_all", MRSTR_DEF_IDX_LST_LEN * sizeof(mrstr_size), NULL);

    alloc = MRSTR_DEF_IDX_LST_LEN;

    c = 0;
    if (!cnt)
        cnt = &c;

    for (i = 0; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] == chr)
        {
            if (*cnt == alloc)
            {
                tdata = __mrstr_realloc(idxs, (alloc += MRSTR_DEF_IDX_LST_LEN) * sizeof(mrstr_size));
                if (!tdata)
                {
                    __mrstr_free(idxs);
                    mrstr_dbg_aloc_err("mrstr_c_find_all", alloc * sizeof(mrstr_size), NULL);
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
            mrstr_dbg_aloc_err("mrstr_c_find_all", *cnt * sizeof(mrstr_size), NULL);
        }

        idxs = tdata;
    }

    return idxs;
}
