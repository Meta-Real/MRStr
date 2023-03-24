/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>

char mrstr_set(mrstr_t dst, mrstr_tc src)
{
    MRSTR_DATA(dst) = __mrstr_das_alloc(MRSTR_SIZE(src) + 1);

    if (!MRSTR_DATA(dst))
    {
#if __MRSTR_DEBUG__
        fprintf(stderr,
            "MRSTR mrstr_set function: can not allocate %llu bytes from memory\n",
            MRSTR_SIZE(src) + 1
        );
        abort();
#else
        return 1;
#endif
    }

    size_t i;
    for (i = 0; i <= MRSTR_SIZE(src); i++)
        MRSTR_DATA(dst)[i] = MRSTR_DATA(src)[i];

    MRSTR_SIZE(dst) = MRSTR_SIZE(src);

    return 0;
}
