/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_cs_trim(mrstr_p, mrstr_pc, mrstr_cstr)
 * Trims the left and right set of characters matching one of the characters
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_cs_trim(mrstr_p res, mrstr_pc str, mrstr_cstr chrs)
{
    mrstr_size clen, i, j;

    if (!MRSTR_LEN(str))
        return;

    if (!(chrs && (clen = strlen(chrs))))
    {
        if (res == str)
            return;

        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_cs_trim", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
    }

    for (i = 0; i < MRSTR_LEN(str); i++)
        if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
            break;

    for (j = MRSTR_LEN(str); j != i;)
        if (!memchr(chrs, MRSTR_DATA(str)[--j], clen))
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
                mrstr_dbg_aloc_err("mrstr_cs_trim", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        memmove(MRSTR_DATA(res), MRSTR_DATA(res) + i, j);

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), j + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_cs_trim", j + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[j] = '\0';
        MRSTR_LEN(res) = j;
        return;
    }

    if (i == MRSTR_LEN(res))
        return;

    MRSTR_DATA(res) = __mrstr_alloc(j + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_cs_trim", j + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str) + i, j);
    MRSTR_DATA(res)[j] = '\0';
    MRSTR_LEN(res) = j;
}
