/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_clears(mrstr_p, ...)
 * Deallocates the space occupied by the string in multiple strings
 * Offsetting the strings does not affect the deallocation process
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
        if (MRSTR_LEN(str) || MRSTR_OFFSET(str))
        {
            __mrstr_das_free(MRSTR_DATA(str) - MRSTR_OFFSET(str));
            MRSTR_DATA(str) = NULL;

            MRSTR_LEN(str) = 0;

            MRSTR_OFFSET(str) = 0;
        }

        str = va_arg(ap, mrstr_p);
    } while (str);

    va_end(ap);
}
