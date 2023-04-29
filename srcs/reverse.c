/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_reverse(mrstr_p, mrstr_pc)
 * Reverses the order of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>

void mrstr_reverse(mrstr_p res, mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_chr tchr;
        mrstr_size i, j;

        if (MRSTR_LEN(res) == 1)
            return;
        for (i = 0; i < MRSTR_LEN(res) / 2; i++)
        {
            tchr = MRSTR_DATA(res)[i];

            j = MRSTR_LEN(res) - i - 1;
            MRSTR_DATA(res)[i] = MRSTR_DATA(res)[j];
            MRSTR_DATA(res)[j] = tchr;
        }

        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_reverse", MRSTR_LEN(str) + 1, );

    for (; MRSTR_LEN(res) < MRSTR_LEN(str); MRSTR_LEN(res)++)
        MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(str) - MRSTR_LEN(res) - 1];

    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
