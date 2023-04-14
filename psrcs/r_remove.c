/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_r_remove(mrstr_p, mrstr_p, mrstr_idx, mrstr_idx)
 * Removes the characters in the specified range of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_r_remove(mrstr_p res, mrstr_p str, mrstr_idx sidx, mrstr_idx eidx)
{
    if (sidx >= MRSTR_LEN(str))
        mrstr_dbg_orng_err("mrstr_r_remove", sidx, MRSTR_LEN(str), );

    if (sidx >= eidx)
        return;

    if (eidx > MRSTR_LEN(str))
        eidx = MRSTR_LEN(str);

    mrstr_size diff = eidx - sidx;

    if (res == str)
    {
        if (diff == MRSTR_LEN(res))
            mrstr_data_free("mrstr_r_remove");

        memmove(MRSTR_DATA(res) + sidx, MRSTR_DATA(res) + eidx, MRSTR_LEN(res) - eidx + 1);
        MRSTR_LEN(res) -= diff;

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_r_remove", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        return;
    }

    if (diff == MRSTR_LEN(str))
        return;

    MRSTR_LEN(res) = MRSTR_LEN(str) - diff;
    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_r_remove", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), sidx);
    memcpy(MRSTR_DATA(res) + sidx, MRSTR_DATA(str) + eidx, MRSTR_LEN(str) - eidx + 1);
}
