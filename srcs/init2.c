/*/
 * MetaReal String Library version 1.0.0
/*/

#include <mrstr.h>
#include <string.h>

void mrstr_init2(mrstr_t mrstr, char* data)
{
    MRSTR_DATA(mrstr) = data;
    MRSTR_SIZE(mrstr) = strlen(data);
}
