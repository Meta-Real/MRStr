/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_clears(mrstr_p, ...)
 * Deallocates the space occupied by string data in multiple strings
 *
 * input reqs:
 *  (str) pointers must be valid
 *  there must be a NULL pointer as the last argument
/*/

#include <mrstr.h>
#include <stdarg.h>

void mrstr_clears(mrstr_p str, ...)
{
    va_list ap;
    va_start(ap, str);

    do
    {
        __mrstr_das_free(MRSTR_DATA(str) - MRSTR_OFFSET(str));

        MRSTR_SIZE(str) = 0;
        MRSTR_LEN(str) = 0;

        MRSTR_OFFSET(str) = 0;

        str = va_arg(ap, mrstr_p);
    } while (str);

    va_end (ap);
}
