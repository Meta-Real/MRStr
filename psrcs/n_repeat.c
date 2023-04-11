/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_repeat(mrstr_p, mrstr_pc, mrstr_size, mrstr_size)
 * Repeats the string up to the length and count times
 * Throws MOVF_ERR if the length of the result string exceeds the mrstr_size limit
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_repeat(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_size count)
{
    if (!MRSTR_LEN(res))
        return;

    if (res == str)
    {
        if (!len || !count)
        {
            MRSTR_LEN(res) = 0;

            if (!MRSTR_OFFSET(res))
            {
                __mrstr_das_free(MRSTR_DATA(res));
                MRSTR_DATA(res) = NULL;
                return;
            }

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_repeat", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            return;
        }

        if (count == 1)
        {
            if (len >= MRSTR_LEN(res))
                return;

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   len + MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_repeat", len + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len] = '\0';
            MRSTR_LEN(res) = len;
            return;
        }

        if (len > MRSTR_LEN(res))
            len = MRSTR_LEN(res);

        MRSTR_LEN(res) = len * count;
        if (!MRSTR_LEN(res) || MRSTR_LEN(res) / len != count)
            mrstr_dbg_movf_err("mrstr_n_repeat", );

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_repeat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);

        if (len == 1)
        {
            memset(MRSTR_DATA(res) + 1, *MRSTR_DATA(res), MRSTR_LEN(res) - 1);
            MRSTR_DATA(res)[len] = '\0';
            return;
        }

        while (len <= MRSTR_LEN(res) - len)
        {
            memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(res), len);
            len *= 2;
        }

        memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(res), MRSTR_LEN(res) - len);
        MRSTR_DATA(res)[len] = '\0';

        return;
    }

    if (!len || !count)
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    MRSTR_LEN(res) = len * count;
    if (!MRSTR_LEN(res) || MRSTR_LEN(res) / len != count)
        mrstr_dbg_movf_err("mrstr_n_repeat", );

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_repeat", MRSTR_LEN(res) + 1, );

    if (count == 1)
    {
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), len);
        MRSTR_DATA(res)[len] = '\0';
        return;
    }

    if (len == 1)
    {
        memset(MRSTR_DATA(res), *MRSTR_DATA(str), count);
        MRSTR_DATA(res)[count] = '\0';
        return;
    }

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), len);

    while (len <= MRSTR_LEN(res) - len)
    {
        memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(res), len);
        len *= 2;
    }

    memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(res), MRSTR_LEN(res) - len);
    MRSTR_DATA(res)[len] = '\0';
}
