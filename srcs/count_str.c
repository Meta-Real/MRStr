/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_count_str(mrstr_pc, mrstr_cstr)
 * Returns the number of matched substrings within the string
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_count_str(mrstr_pc str, mrstr_cstr substr)
{
    mrstr_size slen;
    if (!(substr && (slen = strlen(substr))))
        return 0;

    if (slen > MRSTR_LEN(str))
        return 0;

    if (slen == MRSTR_LEN(str))
        return memcmp(MRSTR_DATA(str), substr, slen) ? 0 : 1;

    mrstr_size i, c = 0;
    for (i = 0; i <= MRSTR_LEN(str) - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, substr, slen))
            c++;

    return c;
}
