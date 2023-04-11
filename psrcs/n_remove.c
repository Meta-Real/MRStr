/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_remove(mrstr_p, mrstr_p, mrstr_idx, mrstr_size)
 * Removes the characters from the string at the index up to the length
 * Throws ORNG_ERR if the index exceeds the length of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_remove(mrstr_p res, mrstr_p str, mrstr_idx idx, mrstr_size len)
{
    if (idx >= MRSTR_LEN(str))
        mrstr_dbg_orng_err("mrstr_n_remove", idx, MRSTR_LEN(str), );

    if (!len)
        return;

    mrstr_size eidx = idx + len;
    if (eidx > MRSTR_LEN(str))
    {
        len = MRSTR_LEN(str) - idx;
        eidx = MRSTR_LEN(str);
    }

    if (res == str)
    {
        if (len == MRSTR_LEN(res))
        {
            MRSTR_LEN(res) = 0;

            if (!MRSTR_OFFSET(res))
            {
                __mrstr_das_free(MRSTR_DATA(res));
                MRSTR_DATA(res) = NULL;
                return;
            }

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_remove", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        memmove(MRSTR_DATA(res) + idx, MRSTR_DATA(res) + eidx, MRSTR_LEN(res) - eidx + 1);
        MRSTR_LEN(res) -= len;

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_remove", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        return;
    }

    if (len == MRSTR_LEN(str))
        return;

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) - len + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_remove", MRSTR_LEN(res) - len + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), idx);
    memcpy(MRSTR_DATA(res) + idx, MRSTR_DATA(str) + eidx, MRSTR_LEN(str) - eidx + 1);
    MRSTR_LEN(res) = MRSTR_LEN(str) - len;
}
