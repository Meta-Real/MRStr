/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_inits(mrstr_p, ...)
 * Initializes strings with the null value
 *
 * input reqs:
 *  (str) pointers must be valid
 *  (str)s must not be allocated (memory leak)
 *  (str)s must be distinct pointers
 *  there must be a NULL pointer as the last argument
/*/

#include <mrstr.h>
#include <stdarg.h>

void mrstr_inits(mrstr_p restrict str, ...)
{
    va_list ap;
    va_start(ap, str);

    do
    {
        MRSTR_LEN(str) = 0;

        MRSTR_OFFSET(str) = 0;

        str = va_arg(ap, mrstr_p restrict);
    } while (str);

    va_end (ap);
}
