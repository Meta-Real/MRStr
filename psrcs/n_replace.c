/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_replace(mrstr_p, mrstr_pc, mrstr_size, mrstr_chr, mrstr_chr)
 * Replaces all the old characters from the string with the new character up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>

void mrstr_n_replace(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_chr old, mrstr_chr new)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        if (!len)
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
                mrstr_dbg_aloc_err("mrstr_n_replace", MRSTR_OFFSET(res) + 1, );
        }

        if (len < MRSTR_LEN(res))
        {
            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                                   len + MRSTR_OFFSET(res) + 1);
            if (!t_data)
                mrstr_dbg_aloc_err("mrstr_n_replace", len + MRSTR_OFFSET(res) + 1, );

            MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
            MRSTR_DATA(res)[len] = '\0';
            MRSTR_LEN(res) = len;
        }
        else if (len > MRSTR_LEN(res))
            len = MRSTR_LEN(res);

        mrstr_size i;
        for (i = 0; i < len; i++)
            if (MRSTR_DATA(res)[i] == old)
                MRSTR_DATA(res)[i] = new;

        return;
    }

    if (!len)
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_replace", len + 1, );

    mrstr_size i;
    for (i = 0; i < len; i++)
    {
        if (MRSTR_DATA(str)[i] == old)
            MRSTR_DATA(res)[i] = new;
        else
            MRSTR_DATA(res)[i] = MRSTR_DATA(str)[i];
    }

    MRSTR_DATA(res)[i] = '\0';
    MRSTR_LEN(res) = MRSTR_LEN(res);
}
