/*/
 * MetaReal String Library version 1.0.0
 *
 * mrstr_size mrstr_n_count_str(mrstr_pc, mrstr_size, mrstr_cstr)
 * Returns the number of matched substrings within the string up to the length
 *
 * input reqs:
 *  (str) pointer must be valid
 *  (substr) pointer must be valid
/*/

#include <mrstr.h>
#include <string.h>

mrstr_size mrstr_n_count_str(mrstr_pc str, mrstr_size len, mrstr_cstr substr)
{
    mrstr_size slen;
    if (!(substr && (slen = strlen(substr))))
        return 0;

    if (len > MRSTR_LEN(str))
        len = MRSTR_LEN(str);

    if (len < slen)
        return 0;

    if (len == slen)
        return memcmp(MRSTR_DATA(str), substr, len) ? 0 : 1;

    mrstr_size i, c = 0;
    for (i = 0; i <= len - slen; i++)
        if (!memcmp(MRSTR_DATA(str) + i, substr, slen))
            c++;

    return c;
}
