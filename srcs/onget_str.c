/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_noget_str(mrstr_pc, size_t)
 * Returns the data of source in string form (up to the specified size and by the specified offset)
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

char* mrstr_noget_str(mrstr_pc src, size_t size, size_t offset)
{
    if (offset >= MRSTR_SIZE(src) || !size)
        return NULL;

    if (!offset)
    {
        if (size > MRSTR_SIZE(src))
            size = MRSTR_SIZE(src);

        char* dst = __mrstr_das_alloc(size + 1);

        if (!dst)
        {
#ifdef __MRSTR_DBG__
            fprintf(stderr,
                "(MRSTR_ERR) mrstr_noget_str function: can not allocate %llu bytes from memory\n",
                size + 1
            );
            abort();
#else
            err_code = ALLOC_ERR;
            return NULL;
#endif
        }

        dst[size--] = '\0';

        do
            dst[size] = MRSTR_DATA(src)[size];
        while (size--);

        return dst;
    }

    size_t src_size = MRSTR_SIZE(src) - offset;

    if (size > src_size)
        size = src_size;

    char* dst = __mrstr_das_alloc(size + 1);

    if (!dst)
    {
#ifdef __MRSTR_DBG__
        fprintf(stderr,
            "(MRSTR_ERR) mrstr_noget_str function: can not allocate %llu bytes from memory\n",
            size + 1
        );
        abort();
#else
        err_code = ALLOC_ERR;
        return NULL;
#endif
    }

    dst[size--] = '\0';

    do
        dst[size] = MRSTR_DATA(src)[size + offset];
    while (size--);

    return dst;
}
