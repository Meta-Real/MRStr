/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_get(mrstr_p, mrstr_size)
 * Reads from stdin up to the length and stores it in the destination string
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_get(mrstr_p dst, mrstr_size len)
{
    mrstr_str tdata;

    if (!len)
        return;

    MRSTR_DATA(dst) = __mrstr_alloc(len + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_n_get", len + 1, );

    fgets(MRSTR_DATA(dst), len + 1, stdin);
    MRSTR_LEN(dst) = strlen(MRSTR_DATA(dst));

    if (MRSTR_LEN(dst) == len)
        return;

    MRSTR_DATA(dst)[--MRSTR_LEN(dst)] = '\0';
    if (!MRSTR_LEN(dst))
    {
        __mrstr_free(MRSTR_DATA(dst));
        MRSTR_DATA(dst) = NULL;
        return;
    }

    tdata = __mrstr_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);
    if (!tdata)
        mrstr_dbg_aloc_err("mrstr_n_get", MRSTR_LEN(dst) + 1, );

    MRSTR_DATA(dst) = tdata;
}
