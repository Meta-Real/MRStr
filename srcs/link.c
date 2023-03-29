/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_link(mrstr_p, mrstr_p)
 * Links destination to the source
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) == (src)) (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_link(mrstr_p dst, mrstr_p src)
{
    if (dst == src)
        return;

    MRSTR_DATA(dst) = MRSTR_DATA(src);

    MRSTR_SIZE(dst) = MRSTR_SIZE(src);
    MRSTR_LEN(dst) = MRSTR_LEN(src);

    MRSTR_OFFSET(dst) = MRSTR_OFFSET(src);
}
