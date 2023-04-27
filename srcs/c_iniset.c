/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_c_iniset(mrstr_p, mrstr_chr)
 * Initializes and sets the destination string with the source character
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
/*/

#include <intern.h>

void mrstr_c_iniset(mrstr_p dst, mrstr_chr src)
{
    MRSTR_DATA(dst) = __mrstr_das_alloc(2);
    if (!MRSTR_DATA(dst))
        mrstr_dbg_aloc_err("mrstr_c_iniset", 2ULL, );

    *MRSTR_DATA(dst) = src;
    MRSTR_DATA(dst)[1] = '\0';
    MRSTR_LEN(dst) = 1;
    MRSTR_OFFSET(dst) = 0;
}
