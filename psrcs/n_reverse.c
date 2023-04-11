/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_reverse(mrstr_p, mrstr_pc, mrstr_size)
 * Reverses the order of the string up to the specified length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>

void mrstr_n_reverse(mrstr_p res, mrstr_pc str, mrstr_size len)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        if (!len)
        {
            if (!MRSTR_OFFSET(res))
            {
                __mrstr_das_free(MRSTR_DATA(res));
                MRSTR_DATA(res) = NULL;
                MRSTR_LEN(res) = 0;
                return;
            }

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_reverse", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            MRSTR_LEN(res) = 0;
            return;
        }

        if (MRSTR_LEN(res) == 1 || len == 1)
            return;

        if (len >= MRSTR_LEN(res))
        {
            char t_chr;
            mrstr_size i, j;
            for (i = 0; i < MRSTR_LEN(res) / 2; i++)
            {
                t_chr = MRSTR_DATA(res)[i];

                j = MRSTR_LEN(res) - i - 1;
                MRSTR_DATA(res)[i] = MRSTR_DATA(res)[j];
                MRSTR_DATA(res)[j] = t_chr;
            }
        }

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               len + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_reverse", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[len] = '\0';

        char t_chr;
        mrstr_size i, j;
        for (i = 0; i < len / 2; i++)
        {
            t_chr = MRSTR_DATA(res)[i];

            j = len - i - 1;
            MRSTR_DATA(res)[i] = MRSTR_DATA(res)[j];
            MRSTR_DATA(res)[j] = t_chr;
        }

        MRSTR_LEN(res) = len;
        return;
    }

    if (!len)
        return;

    if (len > MRSTR_LEN(res))
        len = MRSTR_LEN(res);

    MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_reverse", len + 1, );

    mrstr_size i;
    for (i = 0; i < len; i++)
        MRSTR_DATA(res)[i] = MRSTR_DATA(str)[len - i - 1];

    MRSTR_DATA(res)[len] = '\0';
    MRSTR_LEN(res) = len;
}
