/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>

char mrstr_nset(mrstr_t dst, mrstr_tc src, size_t size)
{
    if (!size)
    {
        MRSTR_DATA(dst) = __mrstr_das_alloc(1);

        *MRSTR_DATA(dst) = '\0';
        MRSTR_SIZE(dst) = 0;

        return 0;
    }

    if (dst == src)
    {
        if (size >= MRSTR_SIZE(src))
            return 0;

        MRSTR_DATA(dst) = __mrstr_das_realloc(MRSTR_DATA(dst), size + 1);

        if (!MRSTR_DATA(dst))
        {
#if __MRSTR_DEBUG__
            fprintf(stderr,
                "MRSTR mrstr_nset function: can not allocate %llu bytes from memory\n",
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

    if (size > MRSTR_SIZE(src))
        size = MRSTR_SIZE(src);

    MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

    if (!MRSTR_DATA(dst))
    {
#if __MRSTR_DEBUG__
        fprintf(stderr,
            "MRSTR mrstr_nset function: can not allocate %llu bytes from memory\n",
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
