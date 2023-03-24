/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>

char mrstr_set_char(mrstr_t dst, char src)
{
    MRSTR_DATA(dst) = __mrstr_das_alloc(2);

    if (!MRSTR_DATA(dst))
    {
#if __MRSTR_DEBUG__
        fprintf(stderr,
            "MRSTR mrstr_set_char function: can not allocate %llu bytes from memory\n",
            2
        );
        abort();
#else
        return 1;
#endif
    }

    MRSTR_DATA(dst)[0] = src;
    MRSTR_DATA(dst)[1] = '\0';

    MRSTR_SIZE(dst) = 1;

    return 0;
}
