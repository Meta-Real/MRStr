/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_inp(mrstr_p, FILE*)
 * Reads the content of the source file and stores it in the destination string
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <intern.h>

void mrstr_inp(mrstr_p dst, FILE *src)
{
    if (src == stdin || !src)
    {
        mrstr_size alloc;
        mrstr_str tdata;
        mrstr_chr c;

        MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_DEF_LEN);
        if (!MRSTR_DATA(dst))
            mrstr_dbg_aloc_err("mrstr_inp", MRSTR_DEF_LEN, );

        alloc = MRSTR_DEF_LEN;

        while ((c = getchar()) != '\n')
        {
            if (MRSTR_LEN(dst) == alloc)
            {
                tdata = __mrstr_das_realloc(MRSTR_DATA(dst), alloc += MRSTR_DEF_LEN);
                if (!tdata)
                    mrstr_dbg_aloc_err("mrstr_inp", alloc, );

                MRSTR_DATA(dst) = tdata;
            }

            MRSTR_DATA(dst)[MRSTR_LEN(dst)++] = c;
        }

        if (!MRSTR_LEN(dst))
        {
            __mrstr_das_free(MRSTR_DATA(dst));
            MRSTR_DATA(dst) = NULL;
            return;
        }

        tdata = __mrstr_das_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);
        if (!MRSTR_DATA(dst))
            mrstr_dbg_aloc_err("mrstr_inp", MRSTR_LEN(dst) + 1, );

        MRSTR_DATA(dst) = tdata;
        MRSTR_DATA(dst)[MRSTR_LEN(dst)] = '\0';
        return;
    }

    fseeko64(src, 0, SEEK_END);
    MRSTR_LEN(dst) = ftello64(src);
    fseeko64(src, 0, SEEK_SET);

    if (!MRSTR_LEN(dst))
        return;

    MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_LEN(dst) + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_inp", MRSTR_LEN(dst) + 1, );

    fread(MRSTR_DATA(dst), 1, MRSTR_LEN(dst), src);
    MRSTR_DATA(dst)[MRSTR_LEN(dst)] = '\0';
}
