/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_reverse(mrstr_p, mrstr_pc)
 * Reverses the order of string data
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (str) pointer must be valid
/*/

#include "intern.h"

void mrstr_reverse(mrstr_p res, mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        if (MRSTR_LEN(res) == 1)
            return;

        char t_chr;
        mrstr_size i, j;
        for (i = 0; i < MRSTR_LEN(res) / 2; i++)
        {
            t_chr = MRSTR_DATA(res)[i];

            j = MRSTR_LEN(res) - i - 1;
            MRSTR_DATA(res)[i] = MRSTR_DATA(res)[j];
            MRSTR_DATA(res)[j] = t_chr;
        }

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_reverse", MRSTR_LEN(str) + 1, );

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
        MRSTR_DATA(res)[i] = MRSTR_DATA(str)[MRSTR_LEN(str) - i - 1];

    MRSTR_DATA(res)[MRSTR_LEN(str)] = '\0';
    MRSTR_LEN(res) = MRSTR_LEN(str);
}
