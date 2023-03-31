/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_clear(mrstr_p)
 * Deallocates the space occupied by string data
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_clear(mrstr_p str)
{
    __mrstr_das_free(MRSTR_DATA(str) - MRSTR_OFFSET(str));
    MRSTR_LEN(str) = 0;

    MRSTR_OFFSET(str) = 0;
}
