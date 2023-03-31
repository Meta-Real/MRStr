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
    if (dst == src)
    {
        if (!MRSTR_OFFSET(dst))
            return;

        if (!MRSTR_LEN(dst))
        {
            __mrstr_das_free(MRSTR_DATA(dst) - MRSTR_OFFSET(dst));

            MRSTR_OFFSET(dst) = 0;

            return;
        }

        MRSTR_DATA(dst) -= MRSTR_OFFSET(dst);

        mrstr_size i;
        for (i = 0; i <= MRSTR_LEN(dst); i++)
            MRSTR_DATA(dst)[i] = MRSTR_DATA(dst)[i + MRSTR_OFFSET(dst)];

        mrstr_str t_data = __mrstr_das_realloc(MRSTR_DATA(dst), MRSTR_LEN(dst) + 1);

        if (!t_data)
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_set function: can not allocate %llu bytes from memory\n",
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

    if (!MRSTR_LEN(src))
        return;

    MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_LEN(src) + 1);

    if (!MRSTR_DATA(dst))
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_set function: can not allocate %llu bytes from memory\n",
            MRSTR_LEN(src) + 1
        );
        abort();
#else
        err_code = ALOC_ERR;
        return;
#endif
    }

    mrstr_size i;
    for (i = 0; i <= MRSTR_LEN(src); i++)
        MRSTR_DATA(dst)[i] = MRSTR_DATA(src)[i];

    MRSTR_LEN(dst) = MRSTR_LEN(src);
}
