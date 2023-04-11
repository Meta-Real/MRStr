/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_map(mrstr_p, mrstr_pc, mrstr_chr (*)(mrstr_chr))
 * Replaces all the characters of the string by their alternative
 * The function parameter must return the alternative of each character of the string
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

    for (; MRSTR_LEN(res) < MRSTR_LEN(str); MRSTR_LEN(res)++)
        MRSTR_DATA(res)[MRSTR_LEN(res)] = func(MRSTR_DATA(str)[MRSTR_LEN(res)]);

    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
