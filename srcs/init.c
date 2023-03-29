/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_init(mrstr_p)
 * Initializes the string with the null value
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (str) must not be allocated (memory leak)
/*/

#include <mrstr.h>

void mrstr_init(mrstr_p str)
{
    MRSTR_SIZE(str) = 0;
    MRSTR_LEN(str) = 0;

    MRSTR_OFFSET(str) = 0;
}
