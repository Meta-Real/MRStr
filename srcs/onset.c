/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_onset(mrstr_p, mrstr_pc, size_t, size_t)
 * Sets the destination data with the source data (up to the specified size and by the specified offset)
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) == (src)) (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

char mrstr_onset(mrstr_p dst, mrstr_pc src, size_t size, size_t offset)
{
    if (!MRSTR_SIZE(src))
        return 0;

    if (dst == src)
    {
        if (offset >= MRSTR_SIZE(dst) || !size)
        {
            __mrstr_das_free(MRSTR_DATA(dst));

            MRSTR_SIZE(dst) = 0;
            return 0;
        }

        if (!offset)
        {
            if (size >= MRSTR_SIZE(dst))
                return 0;

            MRSTR_DATA(dst) = __mrstr_das_realloc(MRSTR_DATA(dst), size + 1);

            if (!MRSTR_DATA(dst))
            {
#ifdef __MRSTR_DBG__
                fprintf(stderr,
                    "(MRSTR_ERR) mrstr_onset function: can not allocate %llu bytes from memory\n",
                    size + 1
                );
                abort();
#else
                return 1;
#endif
            }

            MRSTR_DATA(dst)[size] = '\0';
            MRSTR_SIZE(dst) = size;

            return 0;
        }

        MRSTR_SIZE(dst) -= offset;

        if (size > MRSTR_SIZE(dst))
            size = MRSTR_SIZE(dst);
        else
            MRSTR_SIZE(dst) = size;

        size_t i;
        for (i = 0; i < size; i++)
            MRSTR_DATA(dst)[i] = MRSTR_DATA(dst)[i + offset];

        MRSTR_DATA(dst)[size] = '\0';
        MRSTR_DATA(dst) = __mrstr_das_realloc(MRSTR_DATA(dst), size + 1);

        if (!MRSTR_DATA(dst))
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_onset function: can not allocate %llu bytes from memory\n",
                size + 1
            );
            abort();
#else
            return 1;
#endif
        }

        return 0;
    }

    if (offset >= MRSTR_SIZE(src) || !size)
        return 0;

    if (!offset)
    {
        if (size > MRSTR_SIZE(src))
            size = MRSTR_SIZE(src);

        MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

        if (!MRSTR_DATA(dst))
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_onset function: can not allocate %llu bytes from memory\n",
                size + 1
            );
            abort();
#else
            return 1;
#endif
        }

        MRSTR_SIZE(dst) = size;
        MRSTR_DATA(dst)[size--] = '\0';

        do
            MRSTR_DATA(dst)[size] = MRSTR_DATA(src)[size];
        while (size--);

        return 0;
    }

    MRSTR_SIZE(dst) = MRSTR_SIZE(src) - offset;

    if (size > MRSTR_SIZE(dst))
        size = MRSTR_SIZE(dst);
    else
        MRSTR_SIZE(dst) = size;

    MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_onset function: can not allocate %llu bytes from memory\n",
            size + 1
        );
        abort();
#else
        return 1;
#endif
    }

    MRSTR_DATA(dst)[size--] = '\0';

    do
        MRSTR_DATA(dst)[size] = MRSTR_DATA(src)[size + offset];
    while (size--);

    return 0;
}
