/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_dn_map(mrstr_p, mrstr_pc, mrstr_size, mrstr_chr (*)(mrstr_chr, mrstr_chr_data_pc))
 * Replaces all the characters of the string up to the length by their alternative (with data)
 * The function must return the alternative of each character of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (func) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_dn_map(mrstr_p res, mrstr_pc str, mrstr_size len,
                  mrstr_chr (*func)(mrstr_chr chr, mrstr_chr_data_pc data))
{
    if (!MRSTR_LEN(str))
        return;

    mrstr_chr_data_t data;
    data.str = str;
    data.idx = 0;
    data.prev = '\0';
    data.next = MRSTR_DATA(str)[1];

    if (res == str)
    {
        if (!len)
        {
            MRSTR_LEN(res) = 0;

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
                mrstr_dbg_aloc_err("mrstr_dn_map", MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = '\0';
            MRSTR_LEN(res) = 0;
            return;
        }

        if (len > MRSTR_LEN(res))
            len = MRSTR_LEN(res);

        mrstr_str t_data = __mrstr_das_alloc(len);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_dn_map", len, );

        for (; data.idx < len; data.idx++)
        {
            t_data[data.idx] = func(MRSTR_DATA(res)[data.idx], &data);

            data.prev = MRSTR_DATA(res)[data.idx];
            data.next = MRSTR_DATA(res)[data.idx + 2];
        }

        memcpy(MRSTR_DATA(res), t_data, len);
        __mrstr_das_free(t_data);

        if (len == MRSTR_LEN(res))
            return;

        t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               len + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_dn_map", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
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
        mrstr_dbg_aloc_err("mrstr_dn_map", len + 1, );

    for (; data.idx < len; data.idx++)
    {
        MRSTR_DATA(res)[data.idx] = func(MRSTR_DATA(str)[data.idx], &data);

        data.prev = MRSTR_DATA(res)[data.idx];
        data.next = MRSTR_DATA(res)[data.idx + 2];
    }

    MRSTR_DATA(res)[data.idx] = '\0';
    MRSTR_LEN(res) = data.idx;
}
