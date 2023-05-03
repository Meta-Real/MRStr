/*/
 * MetaReal String Library version 1.0.0
 *
 * void mrstr_c_join(mrstr_p, mrstr_chr, ...)
 * Joins all the strings and separates them with the separator
 *
 * input reqs:
 *  (res) pointer must be valid
 *  (res) must not be allocated (memory leak)
 *  (str) pointers must be valid
 *  there must be a NULL pointer as the last argument
/*/

#include <intern.h>
#include <string.h>
#include <stdarg.h>

void mrstr_c_join(mrstr_p res, mrstr_chr sep, ...)
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
            mrstr_dbg_aloc_err("mrstr_c_join", MRSTR_LEN(str) + 1, );

        memcpy(MRSTR_DATA(res), MRSTR_DATA(str), MRSTR_LEN(str));
        MRSTR_LEN(res) = MRSTR_LEN(str);
    }

    str = va_arg(ap, mrstr_p);
    while (str)
    {
        nlen = MRSTR_LEN(res) + 1 + MRSTR_LEN(str);

        MRSTR_DATA(res) = __mrstr_realloc(MRSTR_DATA(res), nlen + 1);
        if (!MRSTR_DATA(res))
            mrstr_dbg_aloc_err("mrstr_c_join", nlen + 1, );

        MRSTR_DATA(res)[MRSTR_LEN(res)] = sep;
        if (MRSTR_LEN(str))
            memcpy(MRSTR_DATA(res) + MRSTR_LEN(res) + 1, MRSTR_DATA(str), MRSTR_LEN(str));

        MRSTR_LEN(res) = nlen;

        str = va_arg(ap, mrstr_p);
    }

    va_end(ap);

    if (MRSTR_LEN(res))
        MRSTR_DATA(res)[MRSTR_LEN(res)] = '\0';
}
