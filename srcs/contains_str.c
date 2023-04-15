/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_bool mrstr_contains_str(mrstr_pc, mrstr_cstr)
 * Checks the existence of the substring within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_bool mrstr_contains_str(mrstr_pc str, mrstr_cstr substr)
{
    mrstr_size slen;
    if (!(substr && (slen = strlen(substr))))
        return MRSTR_TRUE;

    if (slen > MRSTR_LEN(str))
        return MRSTR_FALSE;

    if (slen == MRSTR_LEN(str))
        return memcmp(MRSTR_DATA(str), substr, slen) ? MRSTR_FALSE : MRSTR_TRUE;

    mrstr_size i;
    for (i = 0; i <= MRSTR_LEN(str) - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, substr, slen))
            return MRSTR_TRUE;

    return MRSTR_FALSE;
}
