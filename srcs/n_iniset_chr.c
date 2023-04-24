/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_iniset_chr(mrstr_p, mrstr_chr, mrstr_size)
 * Initializes and sets the destination string with the source character up to the length
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
/*/

#include <intern.h>
#include <string.h>

void mrstr_n_iniset_chr(mrstr_p dst, mrstr_chr src, mrstr_size len)
{
    if (!len)
    {
        MRSTR_DATA(dst) = NULL;
        MRSTR_LEN(dst) = 0;
        MRSTR_OFFSET(dst) = 0;
        return;
    }

    MRSTR_DATA(dst) = __mrstr_das_alloc(len + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_n_iniset_chr", len + 1, );

    memset(MRSTR_DATA(dst), src, len);
    MRSTR_DATA(dst)[len] = '\0';
    MRSTR_LEN(dst) = len;
    MRSTR_OFFSET(dst) = 0;
}
