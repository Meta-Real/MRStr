/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_oset(mrstr_p, mrstr_pc, size_t)
 * Sets the destination data with the source data (by the specified offset)
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) == (src)) (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

char mrstr_oset(mrstr_p dst, mrstr_pc src, size_t offset)
{
    if (!MRSTR_SIZE(src))
        return 0;

    if (dst == src)
    {
        if (!offset)
            return 0;

        if (offset >= MRSTR_SIZE(dst))
        {
            __mrstr_das_free(MRSTR_DATA(dst));

            MRSTR_SIZE(dst) = 0;
            return 0;
        }

        size_t i;
        for (i = offset; i <= MRSTR_SIZE(dst); i++)
            MRSTR_DATA(dst)[i - offset] = MRSTR_DATA(dst)[i];

        MRSTR_SIZE(dst) -= offset;
        MRSTR_DATA(dst) = __mrstr_das_realloc(MRSTR_DATA(dst), MRSTR_SIZE(dst) + 1);

        if (!MRSTR_DATA(dst))
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_oset function: can not allocate %llu bytes from memory\n",
                MRSTR_SIZE(dst) + 1
            );
            abort();
#else
            return 1;
#endif
        }

        return 0;
    }

    if (offset >= MRSTR_SIZE(src))
        return 0;

    MRSTR_SIZE(dst) = MRSTR_SIZE(src) - offset;
    MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_SIZE(dst) + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_oset function: can not allocate %llu bytes from memory\n",
            MRSTR_SIZE(dst) + 1
        );
        abort();
#else
        return 1;
#endif
    }

    size_t i;
    for (i = offset; i <= MRSTR_SIZE(src); i++)
        MRSTR_DATA(dst)[i - offset] = MRSTR_DATA(src)[i];

    return 0;
}
