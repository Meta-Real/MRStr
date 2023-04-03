/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_inp(mrstr_p restrict, FILE *restrict, mrstr_size)
 * Sets the destination data with the source file up to the specified length
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include "intern.h"
#include <string.h>

void mrstr_n_inp(mrstr_p restrict dst, FILE *restrict src, mrstr_size len)
{
    if (!len)
        return;

    if (src == stdin || !src)
    {
        MRSTR_DATA(dst) = __mrstr_das_alloc(++len);

        if (!MRSTR_DATA(dst))
            mrstr_dbg_aloc_err("mrstr_n_inp", len, );

        fgets(MRSTR_DATA(dst), len, stdin);
        MRSTR_LEN(dst) = strlen(MRSTR_DATA(dst));

        if (!MRSTR_LEN(dst))
        {
            __mrstr_das_free(MRSTR_DATA(dst));
            return;
        }

        if (MRSTR_LEN(dst) + 1 != len)
            MRSTR_DATA(dst)[--MRSTR_LEN(dst)] = '\0';

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);

        if (!t_data)
            mrstr_dbg_aloc_err("mrstr_n_inp", MRSTR_LEN(dst) + 1, );

        MRSTR_DATA(dst) = t_data;

        return;
    }

    fseeko64(src, 0, SEEK_END);
    MRSTR_LEN(dst) = ftello64(src);
    fseeko64(src, 0, SEEK_SET);

    if (!MRSTR_LEN(dst))
        return;

    if (MRSTR_LEN(dst) > len)
        MRSTR_LEN(dst) = len;

    MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_LEN(dst) + 1);

    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_n_inp", MRSTR_LEN(dst) + 1, );

    fread(MRSTR_DATA(dst), 1, MRSTR_LEN(dst), src);
    MRSTR_DATA(dst)[MRSTR_LEN(dst)] = '\0';
}
