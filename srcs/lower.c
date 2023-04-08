/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_lower(mrstr_p, mrstr_pc)
 * Lowers the uppercase alphabet characters of the string
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (except when (res) pointer equals (str) pointer) (memory leak)
 *  (str) pointer must be valid
/*/

#include <intern.h>

void mrstr_lower(mrstr_p res, mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_size i;
        for (i = 0; i < MRSTR_LEN(res); i++)
            if (MRSTR_DATA(res)[i] >= 'A' && MRSTR_DATA(res)[i] <= 'Z')
                MRSTR_DATA(res)[i] += MRSTR_DIFF_CHR;

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_lower", MRSTR_LEN(str) + 1, );

    for (; MRSTR_LEN(res) < MRSTR_LEN(str); MRSTR_LEN(res)++)
    {
        if (MRSTR_DATA(str)[MRSTR_LEN(res)] >= 'A' && MRSTR_DATA(str)[MRSTR_LEN(res)] <= 'Z')
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)] + MRSTR_DIFF_CHR;
        else
            MRSTR_DATA(res)[MRSTR_LEN(res)] = MRSTR_DATA(str)[MRSTR_LEN(res)];
    }

    MRSTR_DATA(res)[MRSTR_LEN(str)] = '\0';
}
