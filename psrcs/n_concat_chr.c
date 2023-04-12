/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_concat_chr(mrstr_p, mrstr_pc, mrstr_size, mrstr_chr)
 * Concatenates the string up to the length and the character
 * if result and first string pointers were the same, then the second string will be added to the first string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_concat_chr(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr chr)
{
    if (res == str)
    {
        if (!MRSTR_LEN(res) || !len)
        {
            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   MRSTR_OFFSET(res) + 2);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_concat_chr", MRSTR_OFFSET(res) + 2, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            *MRSTR_DATA(res) = chr;
            MRSTR_DATA(res)[1] = '\0';
            MRSTR_LEN(res) = 1;
            return;
        }

        if (len > MRSTR_LEN(res))
            len = MRSTR_LEN(res);

        MRSTR_LEN(res) = len + 1;
        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_concat_chr", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[len] = chr;
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
        return;
    }

    if (!MRSTR_LEN(str) || !len)
    {
        MRSTR_DATA(res) = __mrstr_das_alloc(2);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat_chr", 2ULL, );

        *MRSTR_DATA(res) = chr;
        MRSTR_DATA(res)[1] = '\0';
        MRSTR_LEN(res) = 1;
        return;
    }

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    MRSTR_LEN(res) = len + 1;
    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_concat_chr", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), len);
    MRSTR_DATA(res)[len] = chr;
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
