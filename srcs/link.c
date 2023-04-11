/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_link(mrstr_p, mrstr_p)
 * Links destination and the source
 * May cause problems with resizing the strings or deleting them after linking
 * High level function for high level purposes
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (dst) must not be allocated (except when (dst) pointer equals (src) pointer) (memory leak)
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_link(mrstr_p dst, mrstr_p src)
{
    if (dst == src)
        return;

    MRSTR_DATA(dst) = MRSTR_DATA(src);
    MRSTR_LEN(dst) = MRSTR_LEN(src);
    MRSTR_OFFSET(dst) = MRSTR_OFFSET(src);
}
