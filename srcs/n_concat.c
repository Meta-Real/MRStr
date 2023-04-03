/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_concat(mrstr_p, mrstr_pc, mrstr_pc, mrstr_size)
 * Concatenates the first string and the second string up to the specified size
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str1) pointer) (memory leak)
 *  (res) pointer must not be equal to (str2) pointer
 *  (str1) pointer must be valid
 *  (str2) pointer must be valid
/*/

#include "intern.h"
#include <string.h>

void mrstr_n_concat(mrstr_p res, mrstr_pc str1, mrstr_pc str2, mrstr_size len)
{
    if (res == str1)
    {
        if (!MRSTR_LEN(str2) || !len)
            return;

        if (len > MRSTR_LEN(str2))
            len = MRSTR_LEN(str2);

        mrstr_size new_len = MRSTR_LEN(res) + len;
        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               new_len + MRSTR_OFFSET(res) + 1);

        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_concat", new_len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(str2), len);
        MRSTR_DATA(res)[new_len] = '\0';

        MRSTR_LEN(res) = new_len;

        return;
    }

    if (!MRSTR_LEN(str1))
    {
        if (!MRSTR_LEN(str2) || !len)
            return;

        if (len > MRSTR_LEN(str2))
            len = MRSTR_LEN(str2);

        MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);

        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat", len + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str2), len);
        MRSTR_DATA(res)[len] = '\0';

        MRSTR_LEN(res) = len;

        return;
    }

    if (!MRSTR_LEN(str2))
    {
        MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str1) + 1);

        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(str1) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str1);

        return;
    }

    if (len > MRSTR_LEN(str2))
        len = MRSTR_LEN(str2);

    MRSTR_LEN(res) = MRSTR_LEN(str1) + len;
    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_concat", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1));
    memcpy(MRSTR_DATA(res) + MRSTR_LEN(str1), MRSTR_DATA(str2), len);
    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
