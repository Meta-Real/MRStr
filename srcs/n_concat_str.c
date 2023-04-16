/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_concat_str(mrstr_p, mrstr_pc, mrstr_size, mrstr_cstr)
 * Concatenates the first string and the second string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str1) pointer) (memory leak)
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_concat_str(mrstr_p res, mrstr_pc str1, mrstr_size len, mrstr_cstr str2)
{
    if (len > MRSTR_LEN(str1))
        len = MRSTR_LEN(str1);

    if (res == str1)
    {
        if (!len)
        {
            mrstr_size slen;
            if (!(str2 && (slen = strlen(str2))))
                mrstr_data_free("mrstr_n_concat_str");

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   slen + MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_concat_str", slen + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            memcpy(MRSTR_DATA(res), str2, slen + 1);
            MRSTR_LEN(res) = slen;
            return;
        }

        mrstr_size slen;
        if (!(str2 && (slen = strlen(str2))))
        {
            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   len + MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_concat_str", len + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len] = '\0';
            MRSTR_LEN(res) = len;
            return;
        }

        MRSTR_LEN(res) = len + slen;
        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_concat_str", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res) + len, str2, slen + 1);
        return;
    }

    if (!len)
    {
        mrstr_size slen;
        if (!(str2 && (slen = strlen(str2))))
            return;

        MRSTR_DATA(res) = __mrstr_das_alloc(slen + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat_str", slen + 1, );

        memcpy(MRSTR_DATA(res), str2, slen + 1);
        MRSTR_LEN(res) = slen;
        return;
    }

    mrstr_size slen;
    if (!(str2 && (slen = strlen(str2))))
    {
        MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat_str", len + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    MRSTR_LEN(res) = len + slen;
    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_concat_str", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), len);
    memcpy(MRSTR_DATA(res) + len, str2, slen + 1);
}
