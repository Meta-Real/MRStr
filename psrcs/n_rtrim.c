/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_rtrim(mrstr_p, mrstr_pc, mrstr_size, mrstr_chr)
 * Trims the right set of characters matching the character up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_rtrim(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (!MRSTR_LEN(str) || MRSTR_DATA(str)[MRSTR_LEN(str) - 1] != chr || !len)
        return;

    if (len >= MRSTR_LEN(str))
        len = 0;
    else
        len = MRSTR_LEN(str) - len;

    for (MRSTR_LEN(res) = MRSTR_LEN(str) - 1; MRSTR_LEN(res) != len;)
        if (MRSTR_DATA(str)[--MRSTR_LEN(res)] != chr)
        {
            MRSTR_LEN(res)++;
            break;
        }

    if (res == str)
    {
        if (!MRSTR_LEN(res))
            mrstr_data_free("mrstr_n_rtrim");

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_rtrim", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
        return;
    }

    if (!MRSTR_LEN(res))
        return;

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_rtrim", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(res));
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
