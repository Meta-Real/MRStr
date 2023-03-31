/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_nout(FILE*, mrstr_pc, mrstr_size)
 * Sets the destination file with the source data (up to the specified size)
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_nout(FILE* dst, mrstr_pc src, mrstr_size size)
{
    if (!MRSTR_SIZE(src) || !size)
        return;

    if (!dst)
        dst = stdout;

    if (size > MRSTR_SIZE(src))
        size = MRSTR_SIZE(src);

    fwrite(MRSTR_DATA(src), 1, size, dst);
}
