/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_repeat(mrstr_p, mrstr_pc, mrstr_size)
 * Repeats the string with specified count
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_repeat(mrstr_p res, mrstr_pc str, mrstr_size count)
{
    if (res == str)
    {
        if (!MRSTR_LEN(res) || count == 1)
            return;

        if (!count)
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
                mrstr_dbg_aloc_err("mrstr_repeat", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';

            MRSTR_LEN(res) = 0;

            return;
        }

        mrstr_size len = MRSTR_LEN(res) * count;

        if (!len || len / MRSTR_LEN(res) != count)
            mrstr_dbg_movf_err("mrstr_repeat", );

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               len + MRSTR_OFFSET(res) + 1);

        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_repeat", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);

        if (MRSTR_LEN(res) == 1)
        {
            memset(MRSTR_DATA(res) + 1, *MRSTR_DATA(res), len - 1);
            MRSTR_DATA(res)[len] = '\0';

            MRSTR_LEN(res) = len;

            return;
        }

        while (MRSTR_LEN(res) <= len - MRSTR_LEN(res))
        {
            memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), MRSTR_LEN(res));
            MRSTR_LEN(res) *= 2;
        }

        memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), len - MRSTR_LEN(res));
        MRSTR_DATA(res)[len] = '\0';

        MRSTR_LEN(res) = len;

        return;
    }

    if (!MRSTR_LEN(str) || !count)
        return;

    mrstr_size len = MRSTR_LEN(str) * count;

    if (!len || len / MRSTR_LEN(str) != count)
        mrstr_dbg_movf_err("mrstr_repeat", );

    MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_repeat", len + 1, );

    if (count == 1)
    {
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), len + 1);
        MRSTR_LEN(res) = len;

        return;
    }

    if (MRSTR_LEN(str) == 1)
    {
        memset(MRSTR_DATA(res), *MRSTR_DATA(str), len);
        MRSTR_DATA(res)[len] = '\0';

        MRSTR_LEN(res) = len;

        return;
    }

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str));
    MRSTR_LEN(res) = MRSTR_LEN(str);

    while (MRSTR_LEN(res) <= len - MRSTR_LEN(res))
    {
        memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), MRSTR_LEN(res));
        MRSTR_LEN(res) *= 2;
    }

    memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(res), len - MRSTR_LEN(res));
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';

    MRSTR_LEN(res) = len;
}