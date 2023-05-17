/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_upper(mrstr_p, mrstr_pc)
 * Uppers the lowercase alphabet characters of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>

void mrstr_upper(mrstr_p res, mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_size i;
        for (i = 0; i < MRSTR_LEN(res); i++)
            if (MRSTR_DATA(res)[i] >= 'a' && MRSTR_DATA(res)[i] <= 'z')
                MRSTR_DATA(res)[i] -= 32;

        return;
    }

    MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_upper", MRSTR_LEN(str) + 1, );

    for (; MRSTR_LEN(res) < MRSTR_LEN(str); MRSTR_LEN(res)++)
    {
        if (MRSTR_DATA(str)[MRSTR_LEN(res)] >= 'a' && MRSTR_DATA(str)[MRSTR_LEN(res)] <= 'z')
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)] - 32;
        else
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
