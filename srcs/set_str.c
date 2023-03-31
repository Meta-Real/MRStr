/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_set_str(mrstr_p, mrstr_cstr)
 * Sets the destination data with the source
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

void mrstr_set_str(mrstr_p restrict dst, mrstr_cstr restrict src)
{
    if (!src)
        return;

    mrstr_size size = strlen(src);

    if (!size)
        return;

    MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_set_str function: can not allocate %llu bytes from memory\n",
            size + 1
        );
        abort();
#else
        err_code = ALOC_ERR;
        return;
#endif
    }

    MRSTR_LEN(dst) = size;

    do
        MRSTR_DATA(dst)[size] = src[size];
    while (size--);
}
