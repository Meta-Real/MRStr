/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_replace_all(mrstr_p, mrstr_pc, mrstr_cstr, mrstr_chr)
 * Replaces all the old characters from th string with the new character
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
 *  (olds) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_replace_all(mrstr_p res, mrstr_pc str, mrstr_cstr olds, mrstr_chr new)
{
    if (!MRSTR_LEN(str) || !olds)
        return;

    mrstr_size olen = strlen(olds);

    if (!olen)
        return;

    if (res == str)
    {
        mrstr_size i, j;
        for (i = 0; i < MRSTR_LEN(res); i++)
            for (j = 0; j < olen; j++)
                if (MRSTR_DATA(res)[i] == olds[j])
                {
                    MRSTR_DATA(res)[i] = new;
                    break;
                }

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_replace_all", MRSTR_LEN(str) + 1, );

    mrstr_size i, j;
    for (i = 0; i < MRSTR_LEN(str); i++)
    {
        for (j = 0; j < olen; j++)
            if (MRSTR_DATA(res)[i] == olds[j])
            {
                MRSTR_DATA(res)[i] = new;
                break;
            }

        if (j == olen)
            MRSTR_DATA(res)[i] = MRSTR_DATA(str)[i];
    }

    MRSTR_DATA(res)[i] = '\0';
    MRSTR_LEN(res) = i;
}
