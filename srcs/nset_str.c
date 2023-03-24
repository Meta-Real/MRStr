/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>

char mrstr_nset_str(mrstr_t dst, const char* src, size_t size)
{
    if (!size)
    {
        MRSTR_DATA(dst) = NULL;
        MRSTR_SIZE(dst) = 0;

        return 0;
    }

    MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

    if (!MRSTR_DATA(dst))
    {
#if __MRSTR_DEBUG__
        fprintf(stderr,
            "MRSTR mrstr_nset_str function: can not allocate %llu bytes from memory\n",
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
        MRSTR_DATA(dst)[size] = src[size];
    while (size--);

    return 0;
}
