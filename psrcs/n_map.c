/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_map(mrstr_p, mrstr_pc, mrstr_size, mrstr_chr (*)(mrstr_chr))
 * Replaces all the characters of the string up to the specified length by their alternative
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
/*/

#include <intern.h>

void mrstr_n_map(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr (*func)(mrstr_chr chr))
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        if (len > MRSTR_LEN(res))
        {
            mrstr_size i;
            for (i = 0; i < MRSTR_LEN(res); i++)
                MRSTR_DATA(res)[i] = func(MRSTR_DATA(res)[i]);

            return;
        }

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
                mrstr_dbg_aloc_err("mrstr_n_map", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';

            MRSTR_LEN(res) = 0;

            return;
        }

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               len + MRSTR_OFFSET(res) + 1);

        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_map", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);

        mrstr_size i;
        for (i = 0; i < len; i++)
            MRSTR_DATA(res)[i] = func(MRSTR_DATA(res)[i]);

        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;

        return;
    }

    if (!len)
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_map", len + 1, );

    mrstr_size i;
    for (i = 0; i < len; i++)
        MRSTR_DATA(res)[i] = func(MRSTR_DATA(str)[i]);

    MRSTR_DATA(res)[i] = '\0';
    MRSTR_LEN(res) = len;
}
