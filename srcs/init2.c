/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_init2(mrstr_p, char*)
 * Initializes the string with default data
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (str) must not be allocated (memory leak)
 *  (data) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

void mrstr_init2(mrstr_p str, char* data)
{
    MRSTR_OFFSET(str) = 0;

    if (!data)
    {
        MRSTR_SIZE(str) = 0;
        MRSTR_LEN(str) = 0;
        return;
    }

    MRSTR_DATA(str) = data;

    MRSTR_SIZE(str) = strlen(data);
    MRSTR_LEN(str) = MRSTR_SIZE(str);
}
