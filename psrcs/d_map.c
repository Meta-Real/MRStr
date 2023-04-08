/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_d_map(mrstr_p, mrstr_pc, mrstr_chr (*)(mrstr_chr, mrstr_chr_data_pc))
 * Replaces all the characters of the string by their alternative
 * The function parameter must return the alternative of each character of the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_d_map(mrstr_p res, mrstr_pc str, mrstr_chr (*func)(mrstr_chr chr, mrstr_chr_data_pc data))
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
        mrstr_str t_data = __mrstr_das_alloc(MRSTR_LEN(res));

        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_d_map", MRSTR_LEN(res), );

        for (; data.idx < MRSTR_LEN(res); data.idx++)
        {
            t_data[data.idx] = func(MRSTR_DATA(res)[data.idx], &data);

            data.prev = MRSTR_DATA(res)[data.idx];
            data.next = MRSTR_DATA(res)[data.idx + 2];
        }

        memcpy(MRSTR_DATA(res), t_data, MRSTR_LEN(res));
        __mrstr_das_free(t_data);

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_d_map", MRSTR_LEN(str) + 1, );

    for (; data.idx < MRSTR_LEN(str); data.idx++)
    {
        MRSTR_DATA(res)[data.idx] = func(MRSTR_DATA(str)[data.idx], &data);

        data.prev = MRSTR_DATA(res)[data.idx];
        data.next = MRSTR_DATA(res)[data.idx + 2];
    }

    MRSTR_DATA(res)[data.idx] = '\0';
    MRSTR_LEN(res) = data.idx;
}
