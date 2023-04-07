/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_map(mrstr_p, mrstr_pc, mrstr_chr (*)(mrstr_chr))
 * Replaces all the characters of the string by their alternative
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (func) pointer must be valid
/*/

#include <intern.h>

void mrstr_map(mrstr_p res, mrstr_pc str, mrstr_chr (*func)(mrstr_chr chr))
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_size i;
        for (i = 0; i < MRSTR_LEN(res); i++)
            MRSTR_DATA(res)[i] = func(MRSTR_DATA(res)[i]);

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_map", MRSTR_LEN(str) + 1, );

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        MRSTR_DATA(res)[i] = func(MRSTR_DATA(str)[i]);

    MRSTR_DATA(res)[i] = '\0';
    MRSTR_LEN(res) = MRSTR_LEN(str);
}
