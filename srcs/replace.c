/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_replace(mrstr_p, mrstr_pc, mrstr_chr, mrstr_chr)
 * Replaces all the old characters from th string with the new character
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>

void mrstr_replace(mrstr_p res, mrstr_pc str, mrstr_chr old, mrstr_chr new)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_size i;
        for (i = 0; i < MRSTR_LEN(res); i++)
            if (MRSTR_DATA(res)[i] == old)
                MRSTR_DATA(res)[i] = new;

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_replace", MRSTR_LEN(str) + 1, );

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
    {
        if (MRSTR_DATA(str)[i] == old)
            MRSTR_DATA(res)[i] = new;
        else
            MRSTR_DATA(res)[i] = MRSTR_DATA(str)[i];
    }

    MRSTR_DATA(res)[i] = '\0';
    MRSTR_LEN(res) = MRSTR_LEN(res);
}
