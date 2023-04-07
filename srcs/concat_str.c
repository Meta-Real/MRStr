/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_concat_str(mrstr_p, mrstr_pc, mrstr_cstr)
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

void mrstr_concat_str(mrstr_p res, mrstr_pc str1, mrstr_cstr str2)
{
    if (res == str1)
    {
        if (!str2)
            return;

        mrstr_size str2_len = strlen(str2);

        if (!str2_len)
            return;

        mrstr_size len = MRSTR_LEN(res) + str2_len;
        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               len + MRSTR_OFFSET(res) + 1);

        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_concat_str", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), str2, str2_len + 1);

        MRSTR_LEN(res) = len;

        return;
    }

    if (!MRSTR_LEN(str1))
    {
        if (!str2)
            return;

        mrstr_size str2_len = strlen(str2);

        if (!str2_len)
            return;

        MRSTR_DATA(res) = __mrstr_das_alloc(str2_len + 1);

        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_concat_str", str2_len + 1, );

        memcpy(MRSTR_DATA(res), str2, str2_len + 1);
        MRSTR_LEN(res) = str2_len;

        return;
    }

    mrstr_size str2_len;
    if (!str2 || !(str2_len = strlen(str2)))
    {
        MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str1) + 1);

        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_concat_str", MRSTR_LEN(str1) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str1);

        return;
    }

    MRSTR_LEN(res) = MRSTR_LEN(str1) + str2_len;
    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(res) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_concat_str", MRSTR_LEN(res) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str1), MRSTR_LEN(str1));
    memcpy(MRSTR_DATA(res) + MRSTR_LEN(str1), str2, str2_len + 1);
}
