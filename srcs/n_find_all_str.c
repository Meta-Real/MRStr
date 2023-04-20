/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size *mrstr_n_find_all_str(mrstr_size*, mrstr_pc, mrstr_size, mrstr_cstr)
 * Returns the indexes of the matched substrings within the string and their count up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
 *  (count) pointer must be valid
 *  (count) value must be zero (if pointer is not NULL)
/*/

#include <intern.h>
#include <string.h>

mrstr_size *mrstr_n_find_all_str(mrstr_size *count, mrstr_pc str, mrstr_size len, mrstr_cstr substr)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_size slen;
    if (!(substr && (slen = strlen(substr))) || len < slen)
        return NULL;

    if (len == slen)
    {
        if (memcmp(MRSTR_DATA(str), substr, len))
            return NULL;

        mrstr_size *idxs = __mrstr_das_alloc(sizeof(mrstr_size));
        if (!idxs)
            mrstr_dbg_aloc_err("mrstr_n_find_all_str", sizeof(mrstr_size), NULL);

        *idxs = 0;
        *count = 1;
        return idxs;
    }

    mrstr_size *idxs = __mrstr_das_alloc(MRSTR_DEF_IDX_LST_LEN * sizeof(mrstr_size));
    if (!idxs)
        mrstr_dbg_aloc_err("mrstr_n_find_all_str", MRSTR_DEF_IDX_LST_LEN * sizeof(mrstr_size), NULL);

    mrstr_size alloc = MRSTR_DEF_IDX_LST_LEN;

    mrstr_size c = 0;
    if (!count)
        count = &c;

    mrstr_size i;
    mrstr_size *tdata;
    for (i = 0; i <= len - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, substr, slen))
        {
            if (*count == alloc)
            {
                tdata = __mrstr_das_realloc(idxs, (alloc += MRSTR_DEF_IDX_LST_LEN) * sizeof(mrstr_size));
                if (!tdata)
                {
                    __mrstr_das_free(idxs);
                    mrstr_dbg_aloc_err("mrstr_n_find_all_str", alloc * sizeof(mrstr_size), NULL);
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
            __mrstr_das_free(idxs);
            mrstr_dbg_aloc_err("mrstr_n_find_all_str", *count * sizeof(mrstr_size), NULL);
        }

        idxs = tdata;
    }

    return idxs;
}
