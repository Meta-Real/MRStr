/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_upper(mrstr_p, mrstr_pc, mrstr_size)
 * Uppers the lowercase alphabet characters of the string up to the length
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_upper(mrstr_p res, mrstr_pc str, mrstr_size len)
{
    if (!(MRSTR_LEN(str) && len))
        return;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (res == str)
    {
        mrstr_size i;
        for (i = 0; i < len; i++)
            if (MRSTR_DATA(res)[i] >= 'a' && MRSTR_DATA(res)[i] <= 'z')
                MRSTR_DATA(res)[i] -= 32;

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);
    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_n_upper", MRSTR_LEN(str) + 1, );

    for (; MRSTR_LEN(res) < len; MRSTR_LEN(res)++)
    {
        if (MRSTR_DATA(str)[MRSTR_LEN(res)] >= 'a' && MRSTR_DATA(str)[MRSTR_LEN(res)] <= 'z')
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)] - 32;
        else
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    memcpy(MRSTR_DATA(res) + len, MRSTR_DATA(str) + len, MRSTR_LEN(str) - len + 1);
    MRSTR_LEN(res) = MRSTR_LEN(str);
}
