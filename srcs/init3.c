/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>

void mrstr_init3(mrstr_t mrstr, char* data, size_t size)
{
    MRSTR_DATA(mrstr) = data;
    MRSTR_SIZE(mrstr) = size;
}
