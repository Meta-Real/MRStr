/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_replace_all(mrstr_p, mrstr_pc, mrstr_size, mrstr_cstr, mrstr_chr)
 * Replaces all the old characters from the string with the new character up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (olds) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_replace_all(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_chr new)
{
    mrstr_size olen;
    if (!MRSTR_LEN(str) || !olds || !(olen = strlen(olds)))
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (res == str)
    {
        if (!len)
            mrstr_data_free("mrstr_n_replace_all");

        mrstr_size i, j;
        for (i = 0; i < len; i++)
            for (j = 0; j < olen; j++)
                if (MRSTR_DATA(res)[i] == olds[j])
                {
                    MRSTR_DATA(res)[i] = new;
                    break;
                }

        if (len == MRSTR_LEN(res))
            return;

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               len + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_replace_all", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    if (!len)
        return;

    MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_replace_all", len + 1, );

    mrstr_size j;
    for (; MRSTR_LEN(res) < len; MRSTR_LEN(res)++)
    {
        for (j = 0; j < olen; j++)
            if (MRSTR_DATA(res)[MRSTR_LEN(res)] == olds[j])
            {
                MRSTR_DATA(res)[MRSTR_LEN(res)] = new;
                break;
            }

        if (j == olen)
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    MRSTR_DATA(res)[len] = '\0';
}
