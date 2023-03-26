/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_set(mrstr_p, mrstr_pc)
 * Sets the destination data with the source data
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) == (src)) (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_set(mrstr_p dst, mrstr_pc src)
{
    if (!MRSTR_SIZE(src) || dst == src)
        return;

    MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_SIZE(src) + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_set function: can not allocate %llu bytes from memory\n",
            MRSTR_SIZE(src) + 1
        );
        abort();
#else
        err_code = ALLOC_ERR;
        return;
#endif
    }

    size_t i;
    for (i = 0; i <= MRSTR_SIZE(src); i++)
        MRSTR_DATA(dst)[i] = MRSTR_DATA(src)[i];

    MRSTR_SIZE(dst) = MRSTR_SIZE(src);
}
