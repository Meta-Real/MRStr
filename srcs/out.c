/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_out(FILE*, mrstr_pc)
 * Writes the content of the source string in the destination file
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_out(FILE *dst, mrstr_pc src)
{
    if (!MRSTR_LEN(src))
        return;

#ifndef __MRSTR_ADV__
    if (!dst)
        dst = stdout;
#endif

    fwrite(MRSTR_DATA(src), 1, MRSTR_LEN(src), dst);
}
