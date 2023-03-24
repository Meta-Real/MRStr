/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>

void mrstr_clear(mrstr_t mrstr)
{
    __mrstr_das_free(MRSTR_DATA(mrstr));
}
