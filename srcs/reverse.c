/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_reverse(mrstr_p, mrstr_pc)
 * Reverses the order of string data
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_reverse(mrstr_p res, mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        if (!MRSTR_OFFSET(res))
        {
            if (MRSTR_LEN(res) == 1)
                return;

            char t_chr;
            mrstr_size i, j;
            for (i = 0; i < MRSTR_LEN(res) / 2; i++)
            {
                t_chr = MRSTR_DATA(res)[i];

                j = MRSTR_LEN(res) - i - 1;
                MRSTR_DATA(res)[i] = MRSTR_DATA(res)[j];
                MRSTR_DATA(res)[j] = t_chr;
            }

            return;
        }

        MRSTR_DATA(res) -= MRSTR_OFFSET(res);

        if (MRSTR_OFFSET(res) >= MRSTR_LEN(res))
        {
            mrstr_size i;
            for (i = 0; i < MRSTR_LEN(res); i++)
                MRSTR_DATA(res)[i] = MRSTR_DATA(res)[MRSTR_OFFSET(res) + MRSTR_LEN(res) - i - 1];

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res), MRSTR_LEN(res) + 1);

            if (!t_data)
            {
#ifdef __MRSTR_DBG__
                fprintf(stderr,
                    "(MRSTR_ERR) mrstr_reverse function: can not allocate %llu bytes from memory\n",
                    MRSTR_LEN(res) + 1
                );
                abort();
#else
                err_code = ALOC_ERR;
                return;
#endif
            }

            MRSTR_DATA(res) = t_data;
            MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';

            MRSTR_OFFSET(res) = 0;

            return;
        }

        mrstr_size i;
        for (i = 0; i < MRSTR_OFFSET(res); i++)
            MRSTR_DATA(res)[i] = MRSTR_DATA(res)[MRSTR_OFFSET(res) + MRSTR_LEN(res) - i - 1];

        char t_chr;
        mrstr_size j;
        for (; i < (MRSTR_LEN(res) + MRSTR_OFFSET(res)) / 2; i++)
        {
            t_chr = MRSTR_DATA(res)[i];

            j = MRSTR_LEN(res) - i - 1;
            MRSTR_DATA(res)[i] = MRSTR_DATA(res)[j];
            MRSTR_DATA(res)[j] = t_chr;
        }

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res), MRSTR_LEN(res) + 1);

        if (!t_data)
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_reverse function: can not allocate %llu bytes from memory\n",
                MRSTR_LEN(res) + 1
            );
            abort();
#else
            err_code = ALOC_ERR;
            return;
#endif
        }

        MRSTR_DATA(res) = t_data;
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';

        MRSTR_OFFSET(res) = 0;

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);

    if (!MRSTR_DATA(res))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_reverse function: can not allocate %llu bytes from memory\n",
            MRSTR_LEN(str) + 1
        );
        abort();
#else
        err_code = ALOC_ERR;
        return;
#endif
    }

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        MRSTR_DATA(res)[i] = MRSTR_DATA(str)[MRSTR_LEN(str) - i - 1];

    MRSTR_DATA(res)[MRSTR_LEN(str)] = '\0';
    MRSTR_LEN(res) = MRSTR_LEN(str);
}
