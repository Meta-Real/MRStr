/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_upper(mrstr_p, mrstr_pc)
 * Uppers the lowercase characters of the string data
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (str) pointer must be valid
/*/

#include "intern.h"

void mrstr_upper(mrstr_p res, mrstr_pc str)
{
    if (!MRSTR_LEN(str))
        return;

    if (res == str)
    {
        mrstr_size i;
        for (i = 0; i < MRSTR_LEN(res); i++)
            if (MRSTR_DATA(res)[i] >= 'a' && MRSTR_DATA(res)[i] <= 'z')
                MRSTR_DATA(res)[i] -= MRSTR_DIFF_CHR;

        return;
    }

    MRSTR_DATA(res) = __mrstr_das_alloc(MRSTR_LEN(str) + 1);

    if (!MRSTR_DATA(res))
        mrstr_dbg_aloc_err("mrstr_upper", MRSTR_LEN(str) + 1, );

    mrstr_size i;
    for (i = 0; i < MRSTR_LEN(str); i++)
    {
        if (MRSTR_DATA(str)[i] >= 'a' && MRSTR_DATA(str)[i] <= 'z')
            MRSTR_DATA(res)[i] = MRSTR_DATA(str)[i] - MRSTR_DIFF_CHR;
        else
            MRSTR_DATA(res)[i] = MRSTR_DATA(str)[i];
    }

    MRSTR_DATA(res)[MRSTR_LEN(str)] = '\0';
    MRSTR_LEN(res) = MRSTR_LEN(str);
}
