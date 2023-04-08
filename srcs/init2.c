/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_init2(mrstr_p, mrstr_str)
 * Initializes the string with the default data
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (str) must not be allocated (memory leak)
 *  (data) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

void mrstr_init2(mrstr_p str, mrstr_str data)
{
    MRSTR_DATA(str) = data;

    MRSTR_OFFSET(str) = 0;

    if (!data)
        MRSTR_LEN(str) = 0;
    else
        MRSTR_LEN(str) = strlen(data);
}
