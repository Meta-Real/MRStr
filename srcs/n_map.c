/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_map(mrstr_p, mrstr_pc, mrstr_size, mrstr_chr (*)(mrstr_chr))
 * Replaces all the characters of the string by their alternative up to the length
 * The function must return the alternative of each character of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) pointer must not be allocated (memory leak)
 *  (str) pointer must be valid
 *  (func) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_map(mrstr_p res, mrstr_pc str, mrstr_size len,
                 mrstr_chr (*func)(mrstr_chr))
{
    if (!MRSTR_LEN(str))
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (res == str)
    {
        mrstr_size i;

        if (!len)
            return;

        for (i = 0; i < len; i++)
            MRSTR_DATA(res)[i] = func(MRSTR_DATA(res)[i]);

        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_map", MRSTR_LEN(str) + 1, );

    for (; MRSTR_LEN(res) < len; MRSTR_LEN(res)++)
        MRSTR_DATA(res)[MRSTR_LEN(res)] = func(MRSTR_DATA(str)[MRSTR_LEN(res)]);

    memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(str) + len, MRSTR_LEN(str) - len + 1);
    MRSTR_LEN(res) = MRSTR_LEN(str);
}
