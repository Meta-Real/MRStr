/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_set_chr(mrstr_p, mrstr_chr)
 * Sets the destination data with the source
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
/*/

#include <mrstr.h>

void mrstr_set_chr(mrstr_p dst, mrstr_chr src)
{
    MRSTR_DATA(dst) = __mrstr_das_alloc(2);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fputs("(MRSTR_ERR) mrstr_set_chr function: can not allocate 2 bytes from memory\n", stderr);
        abort();
#else
        err_code = ALOC_ERR;
        return;
#endif
    }

    MRSTR_DATA(dst)[0] = src;
    MRSTR_DATA(dst)[1] = '\0';

    MRSTR_SIZE(dst) = 1;
}
