/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_clear(mrstr_p)
 * Deallocates the space occupied by the string
 * Offsetting the string does not affect the deallocation process
 *
 * input reqs:
 *  (str) pointer must be valid
/*/

#include <mrstr.h>

void mrstr_clear(mrstr_p str)
{
    if (!(MRSTR_LEN(str) || MRSTR_OFFSET(str)))
        return;

    __mrstr_das_free(MRSTR_DATA(str) - MRSTR_OFFSET(str));
    MRSTR_DATA(str) = NULL;
    MRSTR_LEN(str) = 0;
    MRSTR_OFFSET(str) = 0;
}
