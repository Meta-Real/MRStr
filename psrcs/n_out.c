/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_out(FILE*, mrstr_pc, mrstr_size)
 * Writes the content of the source string in the destination file up to the length
 *
 * input reqs:
 *  (dst) pointer must be valid
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_n_out(FILE *dst, mrstr_pc src, mrstr_size len)
{
    if (!MRSTR_LEN(src) || !len)
        return;

    if (!dst)
        dst = stdout;

    if (len > MRSTR_LEN(src))
        len = MRSTR_LEN(src);

    fwrite(MRSTR_DATA(src), 1, len, dst);
}
