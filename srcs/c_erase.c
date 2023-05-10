/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_c_erase(mrstr_p, mrstr_pc, mrstr_chr)
 * Removes the matched characters from the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_c_erase(mrstr_p res, mrstr_pc str, mrstr_chr chr)
{
    mrstr_size i, j;
    mrstr_str tdata;

    if (!MRSTR_LEN(str))
        return;

    for (i = 0; i < MRSTR_LEN(str) && MRSTR_DATA(str)[i] != chr; i++);

    if (res == str)
    {
        if (i == MRSTR_LEN(res))
            return;

        for (j = i++; i < MRSTR_LEN(res); i++)
            if (MRSTR_DATA(res)[i] != chr)
                MRSTR_DATA(res)[j++] = MRSTR_DATA(res)[i];

        if (!j)
            mrstr_data_free("mrstr_c_erase");

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), j + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_c_erase", j + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[j] = '\0';
        MRSTR_LEN(res) = j;
        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_c_erase", MRSTR_LEN(str) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), i);

    if (i == MRSTR_LEN(str))
    {
        MRSTR_DATA(res)[i] = '\0';
        MRSTR_LEN(res) = i;
        return;
    }

    for (j = i++; i < MRSTR_LEN(str); i++)
        if (MRSTR_DATA(str)[i] != chr)
            MRSTR_DATA(res)[j++] = MRSTR_DATA(str)[i];

    if (!j)
    {
        __mrstr_free(MRSTR_DATA(res));
        MRSTR_DATA(res) = NULL;
        return;
    }

    tdata = __mrstr_realloc(MRSTR_DATA(res), j + 1);
    if (!tdata)
        mrstr_dbg_aloc_err("mrstr_c_erase", j + 1, );

    MRSTR_DATA(res) = tdata;
    MRSTR_DATA(res)[j] = '\0';
    MRSTR_LEN(res) = j;
}
