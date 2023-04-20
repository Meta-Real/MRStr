/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size *mrstr_n_find_all_chr(mrstr_size*, mrstr_pc, mrstr_size, mrstr_chr)
 * Returns the indexes of the matched characters within the string and their count up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (count) pointer must be valid
 *  (count) value must be zero (if pointer is not NULL)
/*/

#include <intern.h>
#include <string.h>

mrstr_size *mrstr_n_find_all_chr(mrstr_size *count, mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
    {

        return NULL;
    }

    mrstr_size *idxs = __mrstr_das_alloc(MRSTR_DEF_IDX_LST_LEN * sizeof(mrstr_size));
    if (!idxs)
        mrstr_dbg_aloc_err("mrstr_n_find_all_chr", MRSTR_DEF_IDX_LST_LEN * sizeof(mrstr_size), NULL);

    mrstr_size alloc = MRSTR_DEF_IDX_LST_LEN;

    mrstr_size c = 0;
    if (!count)
        count = &c;

    mrstr_size i;
    mrstr_size *tdata;
    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] == chr)
        {
            if (*count == alloc)
            {
                tdata = __mrstr_das_realloc(idxs, (alloc += MRSTR_DEF_IDX_LST_LEN) * sizeof(mrstr_size));
                if (!tdata)
                {
                    free(idxs);
                    mrstr_dbg_aloc_err("mrstr_n_find_all_chr", alloc * sizeof(mrstr_size), NULL);
                }

                idxs = tdata;
            }

            idxs[(*count)++] = i;
        }

    if (!*count)
    {
        __mrstr_das_free(idxs);
        return NULL;
    }

    if (*count != alloc)
    {
        tdata = __mrstr_das_realloc(idxs, *count * sizeof(mrstr_size));
        if (!tdata)
        {
            free(idxs);
            mrstr_dbg_aloc_err("mrstr_n_find_all_chr", *count * sizeof(mrstr_size), NULL);
        }

        idxs = tdata;
    }

    return idxs;
}
