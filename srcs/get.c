/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_get(mrstr_p)
 * Reads from stdin and stores it in the destination string
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
/*/

#include <intern.h>

void mrstr_get(mrstr_p dst)
{
    mrstr_size alloc;
    mrstr_chr c;
    mrstr_str tdata;

    MRSTR_DATA(dst) = __mrstr_alloc(MRSTR_DEF_LEN);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_get", MRSTR_DEF_LEN, );

    alloc = MRSTR_DEF_LEN;

    while ((c = getchar()) != '\n')
    {
        if (MRSTR_LEN(dst) == alloc)
        {
            tdata = __mrstr_realloc(MRSTR_DATA(dst), alloc += MRSTR_DEF_LEN);
            if (!tdata)
                mrstr_dbg_aloc_err("mrstr_get", alloc, );

            MRSTR_DATA(dst) = tdata;
        }

        MRSTR_DATA(dst)[MRSTR_LEN(dst)++] = c;
    }

    if (!MRSTR_LEN(dst))
    {
        __mrstr_free(MRSTR_DATA(dst));
        MRSTR_DATA(dst) = NULL;
        return;
    }

    tdata = __mrstr_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_get", MRSTR_LEN(dst) + 1, );

    MRSTR_DATA(dst) = tdata;
    MRSTR_DATA(dst)[MRSTR_LEN(dst)] = '\0';
}
