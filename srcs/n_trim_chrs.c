/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_trim_chrs(mrstr_p, mrstr_pc, mrstr_cstr, mrstr_size)
 * Trims the left and right set of characters matching one of the characters up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_trim_chrs(mrstr_p res, mrstr_pc str, mrstr_cstr chrs, mrstr_size len)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    mrstr_size clen;
    if (!(len && chrs && (clen = strlen(chrs))))
        return;

    mrstr_size i;
    for (i = 0; i < len; i++)
        if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
            break;

    mrstr_size eidx = MRSTR_LEN(str) - len;
    if (eidx < i)
        eidx = i;

    mrstr_size j;
    for (j = MRSTR_LEN(str); j != eidx;)
        if (!memchr(chrs, MRSTR_DATA(str)[--j], clen))
        {
            j++;
            break;
        }

    j -= i;
    if (res == str)
    {
        if (j == MRSTR_LEN(str))
            return;

        if (!j)
            mrstr_data_free("mrstr_n_trim_chrs");

        memmove(MRSTR_DATA(res), MRSTR_DATA(res) + i, j);

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               j + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_trim_chrs", j + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[j] = '\0';
        MRSTR_LEN(res) = j;
        return;
    }

    if (!j)
        return;

    MRSTR_DATA(res) = __mrstr_das_alloc(j + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_trim_chrs", j + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str) + i, j);
    MRSTR_DATA(res)[j] = '\0';
    MRSTR_LEN(res) = j;
}