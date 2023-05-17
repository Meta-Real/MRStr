/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_remove(mrstr_p, mrstr_pc, mrstr_size, mrstr_size)
 * Removes the characters from the string at the index up to the length
 * Throws ORNG_ERR if the index exceeds the length of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_remove(mrstr_p res, mrstr_pc str, mrstr_size idx, mrstr_size len)
{
    mrstr_size eidx;

    if (idx >= MRSTR_LEN(str))
        mrstr_dbg_orng_err("mrstr_n_remove", idx, MRSTR_LEN(str), );

    if (!len)
        return;

    eidx = idx + len;
    if (eidx > MRSTR_LEN(str))
    {
        len = MRSTR_LEN(str) - idx;
        eidx = MRSTR_LEN(str);
    }

    if (res == str)
    {
        mrstr_str tdata;

        if (len == MRSTR_LEN(res))
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
                mrstr_dbg_aloc_err("mrstr_n_remove", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        memmove(MRSTR_DATA(res) + idx, MRSTR_DATA(res) + eidx, MRSTR_LEN(res) - eidx + 1);
        MRSTR_LEN(res) -= len;

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_n_remove", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        return;
    }

    if (len == MRSTR_LEN(str))
        return;

    MRSTR_LEN(res) = MRSTR_LEN(str) - len;
    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_remove", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), idx);
    memcpy(MRSTR_DATA(res) + idx, MRSTR_DATA(str) + eidx, MRSTR_LEN(str) - eidx + 1);
}
