/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_nset(mrstr_p, mrstr_pc, mrstr_size)
 * Sets the destination data with the source data (up to the specified size)
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) == (src)) (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_nset(mrstr_p dst, mrstr_pc src, mrstr_size size)
{
    if (dst == src)
    {
        if (!MRSTR_LEN(dst) && !MRSTR_OFFSET(dst))
            return;

        if (!MRSTR_LEN(dst) || !size)
        {
            __mrstr_das_free(MRSTR_DATA(dst) - MRSTR_OFFSET(dst));

            MRSTR_OFFSET(dst) = 0;

            return;
        }

        if (!MRSTR_OFFSET(dst))
        {
            if (size >= MRSTR_LEN(dst))
                return;

            mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(dst), size + 1);

            if (!t_data)
            {
#ifdef __MRSTR_DBG__
                fprintf(stderr,
                    "(MRSTR_ERR) mrstr_nset function: can not allocate %llu bytes from memory\n",
                    size + 1
                );
                abort();
#else
                err_code = ALOC_ERR;
                return;
#endif
            }

            MRSTR_DATA(dst) = t_data;
            MRSTR_DATA(dst)[size] = '\0';

            MRSTR_LEN(dst) = size;

            return;
        }

        if (MRSTR_LEN(dst) > size)
            MRSTR_LEN(dst) = size;

        MRSTR_DATA(dst) -= MRSTR_OFFSET(dst);

        mrstr_size i;
        for (i = 0; i <= MRSTR_LEN(dst); i++)
            MRSTR_DATA(dst)[i] = MRSTR_DATA(dst)[i + MRSTR_OFFSET(dst)];

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);

        if (!t_data)
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_nset function: can not allocate %llu bytes from memory\n",
                MRSTR_LEN(dst) + 1
            );
            abort();
#else
            err_code = ALOC_ERR;
            return;
#endif
        }

        MRSTR_DATA(dst) = t_data;

        MRSTR_OFFSET(dst) = 0;

        return;
    }

    if (!MRSTR_LEN(src) || !size)
        return;

    if (size > MRSTR_LEN(src))
        size = MRSTR_LEN(src);

    MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_nset function: can not allocate %llu bytes from memory\n",
            size + 1
        );
        abort();
#else
        err_code = ALOC_ERR;
        return;
#endif
    }

    MRSTR_LEN(dst) = size;
    MRSTR_DATA(dst)[size--] = '\0';

    do
        MRSTR_DATA(dst)[size] = MRSTR_DATA(src)[size];
    while (size--);
}
