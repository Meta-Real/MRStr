/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_init3(mrstr_p, mrstr_str, mrstr_size, mrstr_size)
 * Initializes the string with the default data, length and offset
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (str) must not be allocated (memory leak)
 *  (data) pointer must be valid
 *  (len) must be equal to the length of the string (non-fatal error)
/*/

#include <mrstr.h>

void mrstr_init3(mrstr_p str, mrstr_str data, mrstr_size len, mrstr_size offset)
{
    if (offset > len)
        offset = len;

    MRSTR_DATA(str) = data + offset;
    MRSTR_LEN(str) = len - offset;
    MRSTR_OFFSET(str) = offset;
}
