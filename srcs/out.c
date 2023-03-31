/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_out(FILE*, mrstr_pc)
 * Sets the destination file with the source data
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_out(FILE* dst, mrstr_pc src)
{
    if (!MRSTR_SIZE(src))
        return;

    if (!dst)
        dst = stdout;

    fwrite(MRSTR_DATA(src), 1, MRSTR_SIZE(src), dst);
}
