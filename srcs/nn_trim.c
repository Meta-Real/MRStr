/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_nn_trim(mrstr_p, mrstr_pc, mrstr_size, mrstr_size, mrstr_chr)
 * Trims the left and right set of characters matching the character up to the lengths
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_nn_trim(mrstr_p res, mrstr_pc str, mrstr_size llen, mrstr_size rlen, mrstr_chr chr)
{
    mrstr_size i, eidx, j;

    if (!MRSTR_LEN(str))
        return;

    if (!(llen || rlen))
    {
        if (res == str)
            return;

        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_nn_trim", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
    }

    if (llen > MRSTR_LEN(str))
        llen = MRSTR_LEN(str);

    if (rlen > MRSTR_LEN(str))
        rlen = MRSTR_LEN(str);

    for (i = 0; i < llen; i++)
        if (MRSTR_DATA(str)[i] != chr)
            break;

    eidx = MRSTR_LEN(str) - rlen;
    if (eidx < i)
        eidx = i;

    for (j = MRSTR_LEN(str); j != eidx;)
        if (MRSTR_DATA(str)[--j] != chr)
        {
            j -= i - 1;
            break;
        }

    if (res == str)
    {
        mrstr_str tdata;

        if (j == MRSTR_LEN(res))
            return;

        if (i == MRSTR_LEN(res))
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
                mrstr_dbg_aloc_err("mrstr_nn_trim", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        memmove(MRSTR_DATA(res), MRSTR_DATA(res) + i, j);

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), j + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_nn_trim", j + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[j] = '\0';
        MRSTR_LEN(res) = j;
        return;
    }

    if (i == MRSTR_LEN(str))
        return;

    MRSTR_DATA(res) = __mrstr_alloc(j + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_nn_trim", j + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str) + i, j);
    MRSTR_DATA(res)[j] = '\0';
    MRSTR_LEN(res) = j;
}
