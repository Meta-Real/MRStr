/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_init3(mrstr_p, char*, size_t)
 * Initializes the string with default data and size
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (str) must not be allocated (memory leak)
 *  (data) pointer must be valid
 *  (size) must be equal to the size of the string (non-fatal error)
/*/

#include <mrstr.h>

void mrstr_init3(mrstr_p str, char* data, size_t size)
{
    MRSTR_DATA(str) = data;
    MRSTR_SIZE(str) = size;
}
