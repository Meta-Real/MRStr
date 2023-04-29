/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_cs_replace2(mrstr_p, mrstr_pc, mrstr_cstr, mrstr_chr)
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

void mrstr_cs_replace2(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_cstr news)
{
    mrstr_size olen, nlen, i;

    if (olds == news)
    {
        if (!MRSTR_LEN(str) || res == str)
            return;

        MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_cs_replace2", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    if (!olds)
        mrstr_dbg_lmch_err("mrstr_cs_replace2", 0ULL, strlen(news), );

    if (!news)
        mrstr_dbg_lmch_err("mrstr_cs_replace2", strlen(olds), 0ULL, );

    olen = strlen(olds);
    nlen = strlen(news);
    if (olen != nlen)
        mrstr_dbg_lmch_err("mrstr_cs_replace2", olen, nlen, );

    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_size j;

        if (!olen)
            return;

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
        mrstr_dbg_aloc_err("mrstr_cs_replace2", MRSTR_LEN(str) + 1, );

    if (!olen)
    {
        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str) + 1);
        MRSTR_LEN(res) = MRSTR_LEN(str);
        return;
    }

    for (; MRSTR_LEN(res) < MRSTR_LEN(str); MRSTR_LEN(res)++)
    {
        for (i = 0; i < olen; i++)
            if (MRSTR_DATA(res)[MRSTR_LEN(res)] == olds[i])
            {
                MRSTR_DATA(res)[MRSTR_LEN(res)] = news[i];
                break;
            }

        if (i == olen)
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
