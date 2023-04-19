/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_nn_trim_chrs(mrstr_p, mrstr_pc, mrstr_cstr, mrstr_size, mrstr_size)
 * Trims the left and right set of characters matching one of the characters up to the lengths
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_nn_trim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs, mrstr_size len1, mrstr_size len2)
{
    if (!MRSTR_LEN(str))
        return;

    mrstr_size clen;
    if (!((len1 || len2) && chrs && (clen = strlen(chrs))))
    {
        if (res == str)
            return;

        MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_nn_trim_chrs", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
    }

    if (len1 > MRSTR_LEN(str))
        len1 = MRSTR_LEN(str);

    if (len2 > MRSTR_LEN(str))
        len2 = MRSTR_LEN(str);

    mrstr_size i;
    for (i = 0; i < len1; i++)
        if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
            break;

    mrstr_size eidx = MRSTR_LEN(str) - len2;
    if (eidx < i)
        eidx = i;

    mrstr_size j;
    for (j = MRSTR_LEN(str); j != eidx;)
        if (!memchr(chrs, MRSTR_DATA(str)[--j], clen))
        {
            j -= i - 1;
            break;
        }

    if (res == str)
    {
        if (j == MRSTR_LEN(res))
            return;

        if (i == MRSTR_LEN(res))
            mrstr_data_free("mrstr_nn_trim_chrs");

        memmove(MRSTR_DATA(res), MRSTR_DATA(res) + i, j);

        mrstr_str tdata = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                              j + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_nn_trim_chrs", j + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[j] = '\0';
        MRSTR_LEN(res) = j;
        return;
    }

    if (i == MRSTR_LEN(res))
        return;

    MRSTR_DATA(res) = __mrstr_das_alloc(j + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_nn_trim_chrs", j + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str) + i, j);
    MRSTR_DATA(res)[j] = '\0';
    MRSTR_LEN(res) = j;
}
