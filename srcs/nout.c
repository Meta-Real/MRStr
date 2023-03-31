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

void mrstr_nout(FILE* restrict dst, mrstr_pc restrict src, mrstr_size size)
{
    if (!MRSTR_LEN(src) || !size)
        return;

    if (!dst)
        dst = stdout;

    if (size > MRSTR_LEN(src))
        size = MRSTR_LEN(src);

    fwrite(MRSTR_DATA(src), 1, size, dst);
}
