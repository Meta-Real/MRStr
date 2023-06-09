/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_reverse(mrstr_p, mrstr_pc, mrstr_size)
 * Reverses the order of the string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_reverse(mrstr_p res, mrstr_pc str, mrstr_size len)
{
    if (!MRSTR_LEN(str))
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (res == str)
    {
        mrstr_chr tchr;
        mrstr_size i, j;

        if (len <= 1)
            return;

        for (i = 0; i < len / 2; i++)
        {
            tchr = MRSTR_DATA(res)[i];

            j = len - i - 1;
            MRSTR_DATA(res)[i] = MRSTR_DATA(res)[j];
            MRSTR_DATA(res)[j] = tchr;
        }

        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_reverse", MRSTR_LEN(str) + 1, );

    for (; MRSTR_LEN(res) < len; MRSTR_LEN(res)++)
        MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[len - MRSTR_LEN(res) - 1];

    memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(str) + len, MRSTR_LEN(str) - len + 1);
    MRSTR_LEN(res) = MRSTR_LEN(str);
}
