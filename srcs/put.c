/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_put(mrstr_pc)
 * Writes the content of the source string in stdout
 *
 * input reqs:
 *  (src) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_put(mrstr_pc src)
{
    if (!MRSTR_LEN(src))
        return;

    fputs(MRSTR_DATA(src), stdout);
}
