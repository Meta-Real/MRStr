/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_n_put(mrstr_pc, mrstr_size)
 * Writes the content of the source string in stdout up to the length
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_n_put(mrstr_pc src, mrstr_size len)
{
    if (len > MRSTR_LEN(src))
        len = MRSTR_LEN(src);

    if (!len)
        return;

    fwrite(MRSTR_DATA(src), 1, len, stdout);
}
