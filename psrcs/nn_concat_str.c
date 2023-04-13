/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_nn_concat_str(mrstr_p, mrstr_pc, mrstr_size, mrstr_cstr, mrstr_size)
 * Concatenates the first string up to the length and the second string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str1) pointer) (memory leak)
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_nn_concat_str(mrstr_p res, mrstr_pc str1, mrstr_size len1, mrstr_cstr str2, mrstr_size len2)
{
    if (res == str1)
    {
        if (!MRSTR_LEN(res))
        {
            mrstr_size s2len;
            if (!str2 || !(s2len = strlen(str2)) || !len2)
                return;

            if (len2 > s2len)
                len2 = s2len;

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   len2 + MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_nn_concat_str", len2 + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), str2, len2);
            MRSTR_DATA(res)[len2] = '\0';
            MRSTR_LEN(res) = len2;
            return;
        }

        if (!len1)
        {
            mrstr_size s2len;
            if (!str2 || !(s2len = strlen(str2)) || !len2)
                mrstr_data_free(res, "mrstr_nn_concat_str");

            if (len2 > s2len)
                len2 = s2len;

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   len2 + MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_nn_concat_str", len2 + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), str2, len2);
            MRSTR_DATA(res)[len2] = '\0';
            MRSTR_LEN(res) = len2;
            return;
        }

        mrstr_size s2len;
        if (!str2 || !(s2len = strlen(str2)) || !len2)
        {
            if (len1 < MRSTR_LEN(res))
            {
                mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                       len1 + MRSTR_OFFSET(res) + 1);
                if (!t_data)
                    mrstr_dbg_aloc_err("mrstr_nn_concat_str", len1 + MRSTR_OFFSET(res) + 1, );

                MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
                MRSTR_DATA(res)[len1] = '\0';
                MRSTR_LEN(res) = len1;
            }

            return;
        }

        if (len1 > MRSTR_LEN(res))
            len1 = MRSTR_LEN(res);

        if (len2 > s2len)
            len2 = s2len;

        MRSTR_LEN(res) = len1 + len2;
        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_nn_concat_str", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res) + len1, str2, len2);
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
        return;
    }

    if (!MRSTR_LEN(str1) || !len1)
    {
        mrstr_size s2len;
        if (!str2 || !(s2len = strlen(str2)) || !len2)
            return;

        if (len2 > s2len)
            len2 = s2len;

        MRSTR_DATA(res) = __mrstr_das_alloc(len2 + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_nn_concat_str", len2 + 1, );

        memcpy(MRSTR_DATA(res), str2, len2);
        MRSTR_DATA(res)[len2] = '\0';
        MRSTR_LEN(res) = len2;
        return;
    }

    mrstr_size s2len;
    if (!str2 || !(s2len = strlen(str2)) || !len2)
    {
        if (len1 > MRSTR_LEN(str1))
            len1 = MRSTR_LEN(str1);

        MRSTR_DATA(res) = __mrstr_das_alloc(len1 + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_nn_concat_str", len1 + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len1);
        MRSTR_DATA(res)[len1] = '\0';
        MRSTR_LEN(res) = len1;
        return;
    }

    if (len1 > MRSTR_LEN(str1))
        len1 = MRSTR_LEN(str1);

    if (len2 > s2len)
        len2 = s2len;

    MRSTR_LEN(res) = len1 + len2;
    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_nn_concat_str", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len1);
    memcpy(MRSTR_DATA(res) + len1, str2, len2);
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
