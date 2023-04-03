/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_init2(mrstr_p restrict, mrstr_str restrict)
 * Initializes the string with default data
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (str) must not be allocated (memory leak)
 *  (data) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

void mrstr_init2(mrstr_p restrict str, mrstr_str restrict data)
{
    MRSTR_OFFSET(str) = 0;

    if (!data)
        MRSTR_LEN(str) = 0;
    else
    {
        MRSTR_DATA(str) = data;
        MRSTR_LEN(str) = strlen(data);
    }
}
