/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_cn_iniset(mrstr_p, mrstr_chr, mrstr_size)
 * Initializes and sets the destination string with the source character by the specified count
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
/*/

#include <intern.h>
#include <string.h>

void mrstr_cn_iniset(mrstr_p dst, mrstr_chr src, mrstr_size cnt)
{
    if (!cnt)
    {
        MRSTR_DATA(dst) = NULL;
        MRSTR_LEN(dst) = 0;
        MRSTR_OFFSET(dst) = 0;
        return;
    }

    MRSTR_DATA(dst) = __mrstr_das_alloc(cnt + 1);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_cn_iniset", cnt + 1, );

    memset(MRSTR_DATA(dst), src, cnt);
    MRSTR_DATA(dst)[cnt] = '\0';
    MRSTR_LEN(dst) = cnt;
    MRSTR_OFFSET(dst) = 0;
}
