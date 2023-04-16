/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_replace_chrs2(mrstr_p, mrstr_pc, mrstr_cstr, mrstr_chr)
 * Replaces all the old characters from the string with their alternatives
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

void mrstr_replace_chrs2(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_cstr news)
{
    if (olds == news)
        return;

    if (!olds)
        mrstr_dbg_lmch_err("mrstr_replace_chrs2", 0ULL, strlen(news), );

    if (!news)
        mrstr_dbg_lmch_err("mrstr_replace_chrs2", strlen(olds), 0ULL, );

    mrstr_size olen = strlen(olds);
    mrstr_size nlen = strlen(news);
    if (olen != nlen)
        mrstr_dbg_lmch_err("mrstr_replace_chrs2", olen, nlen, );

    if (!(MRSTR_LEN(str) && olen))
        return;

    if (res == str)
    {
        mrstr_size i, j;
        for (i = 0; i < MRSTR_LEN(res); i++)
            for (j = 0; j < olen; j++)
                if (MRSTR_DATA(res)[i] == olds[j])
                {
                    MRSTR_DATA(res)[i] = news[j];
                    break;
                }

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_replace_chrs2", MRSTR_LEN(str) + 1, );

    mrstr_size j;
    for (; MRSTR_LEN(res) < MRSTR_LEN(str); MRSTR_LEN(res)++)
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

    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
