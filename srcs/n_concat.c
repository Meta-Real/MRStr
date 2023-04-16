/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_concat(mrstr_p, mrstr_pc, mrstr_size, mrstr_pc)
 * Concatenates the first string up to the length and the second string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str1) pointer) (memory leak)
 *  (res) pointer must not be equal to the (str2) pointer
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_concat(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_pc str2)
{
    if (len > MRSTR_LEN(str1))
        len = MRSTR_LEN(str1);

    if (res == str1)
    {
        if (!len)
        {
            if (!MRSTR_LEN(str2))
                mrstr_data_free("mrstr_n_concat");

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   MRSTR_LEN(str2) + MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(str2) + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);
            MRSTR_LEN(res) = MRSTR_LEN(str2);
            return;
        }

        if (!MRSTR_LEN(str2))
        {
            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   len + MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_concat", len + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len] = '\0';
            MRSTR_LEN(res) = len;
            return;
        }

        MRSTR_LEN(res) = len + MRSTR_LEN(str2);
        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);
        return;
    }

    if (!len)
    {
        if (!MRSTR_LEN(str2))
            return;

        MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str2) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(str2) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str2);
        return;
    }

    if (!MRSTR_LEN(str2))
    {
        MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat", len + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    MRSTR_LEN(res) = len + MRSTR_LEN(str2);
    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
    memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(str2), MRSTR_LEN(str2) + 1);
}
