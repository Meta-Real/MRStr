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
    mrstr_bool issrc = MRSTR_FALSE;
    mrstr_str data = NULL, tdata;
    mrstr_size len = 0, nlen;

    va_start(ap, sep);
    str = va_arg(ap, mrstr_p);

    if (!str)
        return;

    if (res == str)
        issrc = MRSTR_TRUE;

    if (MRSTR_LEN(str))
    {
        data = __mrstr_alloc(MRSTR_LEN(str) + 1);
        if (!data)
            mrstr_dbg_aloc_err("mrstr_c_join", MRSTR_LEN(str) + 1, );

        memcpy(data, MRSTR_DATA(str), MRSTR_LEN(str));
        len = MRSTR_LEN(str);
    }

    str = va_arg(ap, mrstr_p);

    while (str)
    {
        if (res == str)
            issrc = MRSTR_TRUE;

        nlen = len + 1 + MRSTR_LEN(str);

        data = __mrstr_realloc(data, nlen + 1);
        if (!data)
            mrstr_dbg_aloc_err("mrstr_c_join", nlen + 1, );

        data[len] = sep;
        if (MRSTR_LEN(str))
            memcpy(data + len + 1, MRSTR_DATA(str), MRSTR_LEN(str));

        len = nlen;

        str = va_arg(ap, mrstr_p);
    }

    va_end(ap);

    if (len)
        data[len] = '\0';

    if (issrc)
    {
        if (!MRSTR_OFFSET(res))
        {
            __mrstr_free(MRSTR_DATA(res));
            MRSTR_DATA(res) = data;
            MRSTR_LEN(res) = len;
            return;
        }

        tdata = __mrstr_realloc(MRSTR_DATA(res) - MRSTR_OFFSET(res), len + MRSTR_OFFSET(res) + 1);
        if (!tdata)
            mrstr_dbg_aloc_err("mrstr_c_join", len + MRSTR_OFFSET(res) + 1, );

        MRSTR_DATA(res) = tdata + MRSTR_OFFSET(res);
        memcpy(MRSTR_DATA(res), data, len + 1);
        MRSTR_LEN(res) = len;
        return;
    }

    MRSTR_DATA(res) = data;
    MRSTR_LEN(res) = len;
}
