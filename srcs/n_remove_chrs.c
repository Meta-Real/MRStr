/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_remove_chrs(mrstr_p, mrstr_pc, mrstr_size, mrstr_cstr)
 * Removes the matched characters from the string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (chrs) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_remove_chrs(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr chrs)
{
    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (!len)
    {
        if (!MRSTR_LEN(str) || res == str)
            return;

        MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_n_remove_chrs", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    mrstr_size clen;
    if (!(chrs && (clen = strlen(chrs))))
        return;

    mrstr_size i;
    for (i = 0; i < len && !memchr(chrs, MRSTR_DATA(str)[i], clen); i++);

    if (res == str)
    {
        if (i == len)
            return;

        mrstr_size j;
        for (j = i++; i < len; i++)
            if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
                MRSTR_DATA(res)[j++] = MRSTR_DATA(res)[i];

        if (!j && i == MRSTR_LEN(res))
            mrstr_data_free("mrstr_n_remove_chrs");

        memmove(MRSTR_DATA(res) + j, MRSTR_DATA(res) + i, MRSTR_LEN(res) - i + 1);
        MRSTR_LEN(res) -= i - j;

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_remove_chrs", MRSTR_LEN(res) + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_remove_chrs", MRSTR_LEN(str) + 1, );

    memcpy(MRSTR_DATA(res), MRSTR_DATA(str), i);

    if (i == len)
    {
        memcpy(MRSTR_DATA(res) + i, MRSTR_DATA(str) + i, MRSTR_LEN(str) - i + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    mrstr_size j;
    for (j = i++; i < len; i++)
        if (!memchr(chrs, MRSTR_DATA(str)[i], clen))
            MRSTR_DATA(res)[j++] = MRSTR_DATA(str)[i];

    if (!j && i == MRSTR_LEN(str))
    {
        __mrstr_das_free(MRSTR_DATA(res));
        MRSTR_DATA(res) = NULL;
        return;
    }

    MRSTR_LEN(res) = MRSTR_LEN(str) - i + j;
    memcpy(MRSTR_DATA(res) + j, MRSTR_DATA(str) + i, MRSTR_LEN(res) + 1);

    mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res), MRSTR_LEN(res) + 1);
    if (!t_data)
        mrstr_dbg_aloc_err("mrstr_n_remove_chrs", MRSTR_LEN(res) + 1, );

    MRSTR_DATA(res) = t_data;
    return;
}
