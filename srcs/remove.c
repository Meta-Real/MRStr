/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_remove(mrstr_p, mrstr_pc, mrstr_size)
 * Removes the character from the string at the index
 * Throws ORNG_ERR if the index exceeds the length of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_remove(mrstr_p res, mrstr_pc str, mrstr_size idx)
{
    if (idx >= MRSTR_LEN(str))
        mrstr_dbg_orng_err("mrstr_remove", idx, MRSTR_LEN(str), );

    if (res == str)
    {
        mrstr_str tdata;

        if (MRSTR_LEN(res) == 1)
            mrstr_data_free("mrstr_remove");

        memmove(MRSTR_DATA(res) + idx, MRSTR_DATA(res) + idx + 1, MRSTR_LEN(res) - idx);

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                    MRSTR_LEN(res) + MRSTR_OFFSET(res));
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_remove", MRSTR_LEN(res) + MRSTR_OFFSET(res), );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        MRSTR_LEN(res)--;
        return;
    }

    if (MRSTR_LEN(str) == 1)
        return;

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str));
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_remove", MRSTR_LEN(str), );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), idx);
    memcpy(MRSTR_DATA(res) + idx, MRSTR_DATA(str) + idx + 1, MRSTR_LEN(str) - idx);
    MRSTR_LEN(res) = MRSTR_LEN(str) - 1;
}
