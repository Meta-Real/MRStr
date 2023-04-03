/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_init3(mrstr_p restrict, mrstr_str restrict, mrstr_size, mrstr_idx)
 * Initializes the string with default data, len and offset
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (str) must not be allocated (memory leak)
 *  (data) pointer must be valid
 *  (len) must be equal to the length of the string (non-fatal error)
/*/

#include <mrstr.h>

void mrstr_init3(mrstr_p restrict str, mrstr_str restrict data, mrstr_size len, mrstr_idx offset)
{
    if (offset > len)
        offset = len;

    MRSTR_DATA(str) = data + offset;
    MRSTR_LEN(str) = len - offset;

    MRSTR_OFFSET(str) = offset;
}
