/*/
 * MetaReal String Library version 1.0.0
 *
 * mstr_nset_str(mrstr_p, mrstr_cstr, mrstr_size)
 * Sets the destination data with the source (up to the specified size)
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

void mrstr_nset_str(mrstr_p dst, mrstr_cstr src, mrstr_size size)
{
    if (!size || !src)
        return;

    mrstr_size len = strlen(src);
    if (!len)
        return;

    if (size > len)
        size = len;

    MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_nset_str function: can not allocate %llu bytes from memory\n",
            size + 1
        );
        abort();
#else
        err_code = ALOC_ERR;
        return;
#endif
    }

    MRSTR_SIZE(dst) = size;
    MRSTR_DATA(dst)[size--] = '\0';

    do
        MRSTR_DATA(dst)[size] = src[size];
    while (size--);
}
