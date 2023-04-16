/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_ltrim(mrstr_p, mrstr_pc, mrstr_chr, mrstr_size)
 * Trims the left set of characters matching the character up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_ltrim(mrstr_p res, mrstr_pc str, mrstr_chr chr, mrstr_size len)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
        return;

    mrstr_size i;
    for (i = 0; i < len; i++)
        if (MRSTR_DATA(str)[i] != chr)
            break;

    MRSTR_LEN(res) = MRSTR_LEN(str) - i;

    if (res == str)
    {
        if (!i)
            return;

        if (!MRSTR_LEN(res))
            mrstr_data_free("mrstr_n_ltrim");

        memmove(MRSTR_DATA(res), MRSTR_DATA(res) + i, MRSTR_LEN(res));

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_ltrim", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
        return;
    }

    if (!MRSTR_LEN(res))
        return;

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_ltrim", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str) + i, MRSTR_LEN(res));
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}