/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_join(mrstr_p, mrstr_pc, ...)
 * Joins all the strings and separates them with the separator
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (sep) pointer must be valid
 *  (str) pointers must be valid
 *  there must be a NULL pointer as the last argument
/*/

#include <intern.h>
#include <string.h>
#include <stdarg.h>

void mrstr_join(mrstr_p res, mrstr_pc sep, ...)
{
    va_list ap;
    mrstr_p str;
    mrstr_size nlen;

    va_start(ap, sep);
    str = va_arg(ap, mrstr_p);

    if (!str)
        return;

    if (MRSTR_LEN(str))
    {
        MRSTR_DATA(res) = __mrstr_alloc(MRSTR_LEN(str) + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_join", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str));
        MRSTR_LEN(res) = MRSTR_LEN(str);
    }

    str = va_arg(ap, mrstr_p);

    if (!MRSTR_LEN(sep))
        while (str)
        {
            if (MRSTR_LEN(str))
            {
                nlen = MRSTR_LEN(res) + MRSTR_LEN(str);

                MRSTR_DATA(res) = __mrstr_realloc(MRSTR_DATA(res), nlen + 1);
                if (!MRSTR_DATA(res))
                    mrstr_dbg_aloc_err("mrstr_join", nlen + 1, );

                memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(str), MRSTR_LEN(str));
                MRSTR_LEN(res) = nlen;
            }

            str = va_arg(ap, mrstr_p);
        }
    else
        while (str)
        {
            nlen = MRSTR_LEN(res) + MRSTR_LEN(sep) + MRSTR_LEN(str);

            MRSTR_DATA(res) = __mrstr_realloc(MRSTR_DATA(res), nlen + 1);
            if (!MRSTR_DATA(res))
                mrstr_dbg_aloc_err("mrstr_join", nlen + 1, );

            memcpy(MRSTR_DATA(res) + MRSTR_LEN(res), MRSTR_DATA(sep), MRSTR_LEN(sep));
            if (MRSTR_LEN(str))
                memcpy(MRSTR_DATA(res) + MRSTR_LEN(res) + MRSTR_LEN(sep), MRSTR_DATA(str), MRSTR_LEN(str));

            MRSTR_LEN(res) = nlen;

            str = va_arg(ap, mrstr_p);
        }

    va_end(ap);

    if (MRSTR_LEN(res))
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
