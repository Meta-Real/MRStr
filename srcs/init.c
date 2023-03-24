/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>

void mrstr_init(mrstr_t mrstr)
{
    MRSTR_DATA(mrstr) = NULL;
    MRSTR_SIZE(mrstr) = 0;
}
