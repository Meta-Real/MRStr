/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_creplace(mrstr_p, mrstr_pc, mrstr_chr, mrstr_chr)
 * Replaces all the old characters from the string with the new character
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>

void mrstr_creplace(mrstr_p res, mrstr_pc str, mrstr_chr old, mrstr_chr new)
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
        mrstr_dbg_aloc_err("mrstr_creplace", MRSTR_LEN(str) + 1, );

    for (; MRSTR_LEN(res) < MRSTR_LEN(str); MRSTR_LEN(res)++)
    {
        if (MRSTR_DATA(str)[MRSTR_LEN(res)] == old)
            MRSTR_DATA(res)[MRSTR_LEN(res)] = new;
        else
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
