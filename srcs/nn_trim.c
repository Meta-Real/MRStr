/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_nn_trim(mrstr_p, mrstr_pc, mrstr_chr, mrstr_size, mrstr_size)
 * Trims the left and right set of characters matching the character up to the lengths
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_nn_trim(mrstr_p res, mrstr_pc str, mrstr_chr chr, mrstr_size len1, mrstr_size len2)
{
    if (len1 > MRSTR_LEN(str))
        len1 = MRSTR_LEN(str);

    if (len2 > MRSTR_LEN(str))
        len2 = MRSTR_LEN(str);

    if (!(len1 || len2))
        return;

    mrstr_size i;
    for (i = 0; i < len1; i++)
        if (MRSTR_DATA(str)[i] != chr)
            break;

    mrstr_size eidx = MRSTR_LEN(str) - len2;
    if (eidx < i)
        eidx = i;

    mrstr_size j;
    for (j = MRSTR_LEN(str); j != eidx;)
        if (MRSTR_DATA(str)[--j] != chr)
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
            mrstr_data_free("mrstr_nn_trim");

        memmove(MRSTR_DATA(res), MRSTR_DATA(res) + i, j);

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               j + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_nn_trim", j + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[j] = '\0';
        MRSTR_LEN(res) = j;
        return;
    }

    if (!j)
        return;

    MRSTR_DATA(res) = __mrstr_das_alloc(j + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_nn_trim", j + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str) + i, j);
    MRSTR_DATA(res)[j] = '\0';
    MRSTR_LEN(res) = j;
}