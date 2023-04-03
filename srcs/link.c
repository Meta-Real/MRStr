/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_link(mrstr_p restrict, mrstr_p restrict)
 * Links destination to the source
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (memory leak)
 *  (dst) and (src) must be distinct pointers
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_link(mrstr_p restrict dst, mrstr_p restrict src)
{
    MRSTR_DATA(dst) = MRSTR_DATA(src);
    MRSTR_LEN(dst) = MRSTR_LEN(src);

    MRSTR_OFFSET(dst) = MRSTR_OFFSET(src);
}
