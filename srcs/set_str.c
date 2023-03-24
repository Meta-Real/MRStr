/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>
#include <string.h>

char mrstr_set_str(mrstr_t dst, const char* src)
{
    size_t size = strlen(src);
    MRSTR_DATA(dst) = __mrstr_das_alloc(size + 1);

    if (!MRSTR_DATA(dst))
    {
#if __MRSTR_DEBUG__
        fprintf(stderr,
            "MRSTR mrstr_set_str function: can not allocate %llu bytes from memory\n",
            size + 1
        );
        abort();
#else
        return 1;
#endif
    }

    MRSTR_SIZE(dst) = size;

    do
        MRSTR_DATA(dst)[size] = src[size];
    while (size--);

    return 0;
}
