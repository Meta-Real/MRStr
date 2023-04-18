/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_inp(mrstr_p, FILE*, mrstr_size)
 * Reads the content of the source file up to the length and stores it in the destination string
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_inp(mrstr_p dst, FILE *src, mrstr_size len)
{
    if (!len)
        return;

    if (src == stdin || !src)
    {
        MRSTR_DATA(dst) = __mrstr_das_alloc(len + 1);
        if (!MRSTR_DATA(dst))
            mrstr_dbg_aloc_err("mrstr_n_inp", len + 1, );

        fgets(MRSTR_DATA(dst), len + 1, stdin);
        MRSTR_LEN(dst) = strlen(MRSTR_DATA(dst));

        if (MRSTR_DATA(dst)[MRSTR_LEN(dst) - 1] == '\n')
            MRSTR_DATA(dst)[--MRSTR_LEN(dst)] = '\0';

        if (MRSTR_LEN(dst) == len)
            return;

        if (!MRSTR_LEN(dst))
        {
            __mrstr_das_free(MRSTR_DATA(dst));
            MRSTR_DATA(dst) = NULL;
            return;
        }

        mrstr_str tdata = __mrstr_das_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_n_inp", MRSTR_LEN(dst) + 1, );

        MRSTR_DATA(dst) = tdata;
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
