/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_replace_chrs(mrstr_p, mrstr_pc, mrstr_size, mrstr_cstr, mrstr_cstr)
 * Replaces all the old characters from the string with their alternatives up to the length
 * Throws LMCH_ERR if the length of the olds and the news string do not match
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (olds) pointer must be valid
 *  (news) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_replace_chrs(mrstr_p res, mrstr_pc str, mrstr_size len, mrstr_cstr olds, mrstr_cstr news)
{
    if (!len)
    {
        if (res == str)
            mrstr_data_free("mrstr_n_replace_chrs");
        return;
    }

    if (olds == news)
        return;

    if (!olds)
        mrstr_dbg_lmch_err("mrstr_n_replace_chrs", 0ULL, strlen(news), );

    if (!news)
        mrstr_dbg_lmch_err("mrstr_n_replace_chrs", strlen(olds), 0ULL, );

    mrstr_size olen = strlen(olds);
    mrstr_size nlen = strlen(news);
    if (olen != nlen)
        mrstr_dbg_lmch_err("mrstr_n_replace_chrs", olen, nlen, );

    if (!MRSTR_LEN(str) || !olen)
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (res == str)
    {
        mrstr_size i, j;
        for (i = 0; i < len; i++)
            for (j = 0; j < olen; j++)
                if (MRSTR_DATA(res)[i] == olds[j])
                {
                    MRSTR_DATA(res)[i] = news[j];
                    break;
                }

        if (len == MRSTR_LEN(res))
            return;

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res),
                                               len + MRSTR_OFFSET(res) + 1);
        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_replace_chrs", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = t_data + MRSTR_OFFSET(res);
        MRSTR_DATA(res)[len] = '\0';
        MRSTR_LEN(res) = len;
        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(len + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_replace_chrs", len + 1, );

    mrstr_size j;
    for (; MRSTR_LEN(res) < len; MRSTR_LEN(res)++)
    {
        for (j = 0; j < olen; j++)
            if (MRSTR_DATA(res)[MRSTR_LEN(res)] == olds[j])
            {
                MRSTR_DATA(res)[MRSTR_LEN(res)] = news[j];
                break;
            }

        if (j == olen)
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    MRSTR_DATA(res)[len] = '\0';
}
