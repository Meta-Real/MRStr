/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_upper(mrstr_p, mrstr_pc, mrstr_size)
 * Uppers the lowercase alphabet characters of the string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>

void mrstr_n_upper(mrstr_p res, mrstr_pc str, mrstr_size len)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        if (!len)
            mrstr_data_free("mrstr_n_upper");

        if (MRSTR_LEN(res) == 1 || len == 1)
            return;

        if (len >= MRSTR_LEN(res))
        {
            mrstr_size i;
            for (i = 0; i < MRSTR_LEN(res); i++)
                if (MRSTR_DATA(res)[i] >= 'a' && MRSTR_DATA(res)[i] <= 'z')
                    MRSTR_DATA(res)[i] -= MRSTR_DIFF_CHR;

            return;
        }

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               len + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_upper", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[len] = '\0';

        mrstr_size i;
        for (i = 0; i < len; i++)
            if (MRSTR_DATA(res)[i] >= 'a' && MRSTR_DATA(res)[i] <= 'z')
                MRSTR_DATA(res)[i] -= MRSTR_DIFF_CHR;

        MRSTR_LEN(res) = len;
        return;
    }

    if (!len)
        return;

    if (len > MRSTR_LEN(res))
        len = MRSTR_LEN(res);

    MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_upper", len + 1, );

    mrstr_size i;
    for (i = 0; i < len; i++)
    {
        if (MRSTR_DATA(str)[i] >= 'a' && MRSTR_DATA(str)[i] <= 'z')
            MRSTR_DATA(res)[i] = MRSTR_DATA(str)[i] - MRSTR_DIFF_CHR;
        else
            MRSTR_DATA(res)[i] = MRSTR_DATA(str)[i];
    }

    MRSTR_DATA(res)[len] = '\0';
    MRSTR_LEN(res) = len;
}
